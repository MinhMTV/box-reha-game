@file:OptIn(kotlin.uuid.ExperimentalUuidApi::class,kotlin.time.ExperimentalTime::class)
package com.digitaldojo.sdkinspector

import android.app.Application
import android.content.*
import android.bluetooth.BluetoothManager
import android.os.SystemClock
import com.boxreha.dynamics.Sdk0256Compat
import com.boxreha.dynamics.SdkDeviceOperations
import android.Manifest
import android.content.pm.PackageManager
import android.location.LocationManager
import android.os.Build
import com.russhwolf.settings.SharedPreferencesSettings
import com.riseworld.dynamics.multiplatform.di.*
import com.riseworld.dynamics.multiplatform.settings.DynamicsSettings
import com.riseworld.dynamics.models.PeripheralDto
import com.riseworld.dynamics.models.Side
import com.riseworld.dynamics.models.ble.nearby.NearbyGlove
import com.riseworld.dynamics.composite.ble.Glove
import com.riseworld.dynamics.models.domain.profile.body.Gender
import com.riseworld.dynamics.models.domain.session.TrainingSessionSensorType
import com.riseworld.dynamics.models.domain.punch.Punch
import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.sync.Mutex
import kotlinx.coroutines.sync.withLock
import org.json.*
import java.time.Instant
import kotlin.uuid.Uuid

data class DeviceState(val id:String,val name:String,val family:String="UNKNOWN",val side:String="UNKNOWN",val connection:String="SAVED",val metadata:String="",val raw:String="",val computed:String="",val rawCount:Long=0,val computedCount:Long=0,val rawReceived:Long=0,val punchReceived:Long=0,val punchId:String="") {
 val role:String get()=when { family=="ALPHA"&&side=="LEFT"->"LEFT_HAND";family=="ALPHA"&&side=="RIGHT"->"RIGHT_HAND";family=="DELTA"&&side=="LEFT"->"LEFT_FOOT";family=="DELTA"&&side=="RIGHT"->"RIGHT_FOOT";else->"UNKNOWN" }
 fun json()=JSONObject().put("peripheralId",id).put("family",family).put("side",side).put("role",role)
}
data class UiEvent(val type:String,val role:String,val text:String,val deviceId:String="",val time:String="",val summary:String="")
data class InspectorState(val initialized:Boolean=false,val scanning:Boolean=false,val sdkState:String="Not initialized",val bluetooth:String="Unknown",val devices:List<DeviceState> = emptyList(),val nearby:List<Pair<String,String>> = emptyList(),val events:List<UiEvent> = emptyList(),val message:String="",val sessions:List<String> = emptyList(),val permissions:Boolean=false,val scanBlocker:String="Initialize SDK",val rawEnabled:Boolean=false,val busy:Boolean=false,val recording:RecordingStatus=RecordingStatus())

class DynamicsSdkManager(val app:Application) {
 val scope=CoroutineScope(SupervisorJob()+Dispatchers.Main.immediate)
 val recorder=SensorRecorder(app)
 val state=MutableStateFlow(InspectorState())
 private val commands=Mutex();private val eventGate=Mutex()
 private val devices=linkedMapOf<String,DeviceState>();private val dtos=linkedMapOf<String,PeripheralDto>()
 private val nearby=linkedMapOf<String,NearbyGlove>();private val recent=ArrayDeque<UiEvent>()
 private val jobs=linkedMapOf<String,Job>();private val rawJobs=linkedMapOf<String,Job>()
 private var scanning=false;private var initialized=false;private var sdkState="Not initialized";private var message="";private var sequence=0L
 private val started=Instant.now().toString()
 private var settings:DynamicsSettings?=null
 private var rawEnabled=false
 private var busy=false
 init {
  scope.launch { while(isActive){delay(100);state.value=InspectorState(initialized,scanning,sdkState,bluetooth(),devices.values.toList(),nearby.map { it.key to SdkFields.read(it.value).toString() },recent.toList(),message,recorder.sessions().map { it.name },missingPermissions().isEmpty(),scanBlocker(),rawEnabled,busy,recorder.status.value)} }
  scope.launch { emit("APP_STARTED",payload=JSONObject().put("startedUtc",started)) }
 }
 fun missingPermissions():List<String> = (if(Build.VERSION.SDK_INT>=31) listOf(Manifest.permission.BLUETOOTH_SCAN,Manifest.permission.BLUETOOTH_CONNECT) else listOf(Manifest.permission.ACCESS_FINE_LOCATION)).filter { app.checkSelfPermission(it)!=PackageManager.PERMISSION_GRANTED }
 fun scanBlocker():String = when {
  !app.packageManager.hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE)->"Bluetooth LE not supported"
  missingPermissions().isNotEmpty()->"Grant Bluetooth / location permissions"
  bluetooth()!="ON"->"Enable Bluetooth"
  Build.VERSION.SDK_INT<31 && !androidx.core.location.LocationManagerCompat.isLocationEnabled(app.getSystemService(LocationManager::class.java))->"Enable location services for BLE discovery"
  !initialized->"Initialize SDK"
  else->""
 }
 fun bluetooth():String=try { if(app.getSystemService(BluetoothManager::class.java)?.adapter?.isEnabled==true) "ON" else "OFF" } catch(e:SecurityException){"Permission required"}
 fun command(name:String,block:suspend ()->Unit) { scope.launch { commands.withLock {
  emit("DEVICE_OPERATION",payload=JSONObject().put("operation",name).put("phase","requested"))
  busy=true
  try { withTimeout(90000){block()};emit("SDK",payload=JSONObject().put("operation",name).put("phase","completed")) }
  catch(e:Throwable){if(e is CancellationException && e !is TimeoutCancellationException)throw e;error(name,e)} finally { busy=false }
 } } }
 suspend fun error(name:String,e:Throwable){val root=generateSequence(e){it.cause}.last();message="$name: ${root.javaClass.simpleName}: ${root.message}";android.util.Log.e("DynamicsInspector",message,e);emit("ERROR",payload=JSONObject().put("operation",name).put("exception",SdkFields.read(e)))}
 suspend fun emit(type:String,id:String?=null,payload:Any?=null,sdkTimestamp:Any?=null) {
  val utc=Instant.now().toString();val nano=SystemClock.elapsedRealtimeNanos()
  eventGate.withLock {
   val d=devices[id];val device=d?.json()?:JSONObject().put("peripheralId",id?:JSONObject.NULL).put("family","UNKNOWN").put("side","UNKNOWN").put("role","UNKNOWN")
   val record=JSONObject().put("schemaVersion",1).put("sequence",++sequence).put("eventType",type).put("utcTimestamp",utc).put("elapsedRealtimeNanos",nano).put("device",device).put("sdkTimestamp",sdkTimestamp?:JSONObject.NULL).put("payload",payload?:JSONObject.NULL)
   val line=withContext(Dispatchers.Default){record.toString()}
   try { recorder.append(line) } catch(e:Throwable){message="Recording failure: $e";if(e is CancellationException)throw e}
   recent.addLast(UiEvent(type,d?.role?:"UNKNOWN",if(line.length>8192)line.take(8192)+" … [UI preview truncated; full event in JSONL]" else line,id?:"",utc.substringAfter("T").take(12),when(type){"RAW_SENSOR"->"Sensor packet";"COMPUTED_EVENT"->"SDK Punch snapshot";else->payload.toString().take(90)}));while(recent.size>1000)recent.removeFirst()
  }
 }
 fun watch(name:String,block:suspend ()->Unit) {
  jobs[name]?.cancel();jobs[name]=scope.launch { try { block() } catch(e:CancellationException){throw e} catch(e:Throwable){error(name,e)} }
 }
 fun initialize()=command("initialize") {
  if(!initialized){Sdk0256Compat.verifyAbi();settings=DynamicsSettings(SharedPreferencesSettings(app.getSharedPreferences("sdk",Context.MODE_PRIVATE))).also {
   it.setDebuggingMode(false);it.setDummyImpactDataEnabled(false);it.setAcceptAllPunches(false);it.setKeepAllPunchDetails(true)
   // SDK background policy remains a physical test: explicit long timeout during inspector process lifetime.
   it.setBackgroundDisconnectTimeoutInSeconds(86400);initSdk(dynamicsSettings=it)
  };initialized=true;sdkState="Initialized / COMPATIBILITY"}
  observe()
 }
 private fun observe() {
  watch("saved") { gloveRepository.savedPeripherals.collect { saved ->
   emit("SAVED_DEVICES",payload=withContext(Dispatchers.Default){SdkFields.read(saved)})
   val ids=saved.map { Sdk0256Compat.deviceUuid(it).toString() }.toSet()
   for(id in dtos.keys.toList())if(id !in ids){dtos.remove(id);devices.remove(id);rawJobs.remove(id)?.cancel()}
   for(dto in saved){val id=Sdk0256Compat.deviceUuid(dto).toString();dtos[id]=dto
    if(id !in devices)devices[id]=DeviceState(id,dto.name,side=dto.side.toString(),metadata=SdkFields.read(dto).toString())
    startRaw(dto)
   }
  } }
  watch("devices") { gloveRepository.observeGloves().collect { list ->
   for(g in list){val id=Sdk0256Compat.deviceUuid(g.dto).toString();val old=devices[id]?:DeviceState(id,g.dto.name)
    val family=when(g.data?.sensorType){TrainingSessionSensorType.ALPHA->"ALPHA";TrainingSessionSensorType.DELTA->"DELTA";else->old.family}
    val meta=withContext(Dispatchers.Default){SdkFields.read(g)}
    devices[id]=old.copy(name=g.data?.deviceName?:old.name,family=family,side=g.dto.side.toString(),connection=if(Sdk0256Compat.online(g.bleGloveState))"CONNECTED" else g.bleGloveState.toString(),metadata=meta.toString())
    emit("DEVICE_STATE",id,meta)
   }
  } }
  watch("scanner") { pairingRepository.scannerState.collect { if(Sdk0256Compat.scannerError(it))message="Scanner: "+it.toString();emit(if(Sdk0256Compat.scannerError(it))"ERROR" else "SCANNER_STATE",payload=SdkFields.read(it)) } }
  watch("session") { trainingSessionRepository.activeTrainingSessionTime.collect { sdkState=if(it==null)"Ready / COMPATIBILITY" else "Session: "+Sdk0256Compat.sessionState(it.state);emit("SESSION_STATE",payload=SdkFields.read(it)) } }
  watch("computed") { var previousIds=emptySet<String>();var observedSnapshot=false
   trainingSessionRepository.activeTrainingSessionStats.collect { stats ->
   // Every observed snapshot is retained; repeated Punch IDs are not silently discarded.
   emit("COMPUTED_SNAPSHOT",payload=withContext(Dispatchers.Default){SdkFields.read(stats)})
   for(p in stats.punches){val punch=p as Punch;val id=SdkFields.getter(punch,"getPeripheralId").toString();val data=withContext(Dispatchers.Default){SdkFields.read(punch)}
    devices[id]?.let { devices[id]=it.copy(computed=data.toString(),computedCount=it.computedCount+1,punchId=Sdk0256Compat.punchId(punch),punchReceived=if(observedSnapshot && Sdk0256Compat.punchId(punch) !in previousIds)SystemClock.elapsedRealtime() else it.punchReceived) }
    emit("COMPUTED_EVENT",id,data,punch.timestamp.toString())
   }
   previousIds=stats.punches.map { Sdk0256Compat.punchId(it as Punch) }.toSet();observedSnapshot=true
  } }
  watch("phone_barometer") { sensorDataRepository.observeSmartphoneBarometer().collect { emit("PHONE_BAROMETER",payload=SdkFields.read(it)) } }
  watch("pairs") { gloveRepository.observeGlovePairs().collect { emit("SDK_PAIRS",payload=SdkFields.read(it)) } }
 }
 private fun startRaw(dto:PeripheralDto) {
  val id=Sdk0256Compat.deviceUuid(dto).toString();if(!rawEnabled || rawJobs[id]?.isActive==true)return
  rawJobs[id]=scope.launch { try {
   Sdk0256Compat.raw(sensorDataRepository,dto).collect { packets ->
    for(packet in packets){val data=withContext(Dispatchers.Default){SdkFields.read(packet)}
     devices[id]?.let { devices[id]=it.copy(raw=data.toString(),rawCount=it.rawCount+1,rawReceived=SystemClock.elapsedRealtime()) }
     emit("RAW_SENSOR",id,data,SdkFields.getter(packet,"getRelativeTimeCounter"))
    }
   }
  } catch(e:CancellationException){throw e} catch(e:Throwable){error("raw/$id",e)} }
 }
 fun scan()=command("scan") { check(scanBlocker().isEmpty()){scanBlocker()};jobs.remove("scan")?.cancelAndJoin();nearby.clear();message="Scanning for nearby sensors";scanning=true;watch("scan") { try { pairingRepository.nearbyGloves.collect { found ->
  nearby.clear();for(g in found){nearby[g.address.toString()]=g;emit("DISCOVERED",payload=SdkFields.read(g))}
 } } finally { scanning=false } } }
 fun stopScan()=command("stop_scan") { jobs.remove("scan")?.cancelAndJoin();scanning=false }
 fun pair(id:String,left:Boolean)=command("pair_${if(left)"LEFT" else "RIGHT"}") {
  check(scanBlocker().isEmpty()){scanBlocker()}
  val g=nearby[id]?:error("Discovery expired")
  val result=pairingRepository.pair(g,g.advertisingName?:"Dynamics",if(left)Side.LEFT else Side.RIGHT)
  emit("PAIR_RESULT",payload=SdkFields.read(result));val pairedId=Sdk0256Compat.pairedUuid(result.getOrThrow<Any>())
  withTimeout(10000){gloveRepository.savedPeripherals.first { list -> list.any { Sdk0256Compat.deviceUuid(it) == pairedId && it.side == if(left)Side.LEFT else Side.RIGHT } }}
  message="Saved by SDK. Waiting for connection and sensor family."
 }
 fun remove(id:String)=command("remove/$id") {
  val dto=dtos[id]?:error("No saved peripheral");SdkDeviceOperations.remove(gloveRepository,dto).getOrThrow()
  withTimeout(5000){gloveRepository.savedPeripherals.first { list->list.none { Sdk0256Compat.deviceUuid(it).toString()==id } }}
  withTimeout(5000){gloveRepository.observeGloves().first { list->list.none { Sdk0256Compat.deviceUuid(it.dto).toString()==id } }}
  emit("REMOVAL_CONFIRMED",id);message="Removal confirmed by saved and connected SDK state"
 }
 fun swap(id:String)=command("swap/$id") {
  val dto=dtos[id]?:error("No saved peripheral");val side=dto.side
  SdkDeviceOperations.swap(gloveRepository,dto).getOrThrow()
  withTimeout(5000){gloveRepository.savedPeripherals.first { list->list.any { Sdk0256Compat.deviceUuid(it).toString()==id && it.side!=side } }}
  message="SDK side change confirmed; check both members of the pair"
 }
 fun setRawEnabled(enabled:Boolean)=command("raw_stream") { rawEnabled=enabled
  if(rawEnabled) dtos.values.forEach { startRaw(it) } else { rawJobs.values.forEach { it.cancelAndJoin() };rawJobs.clear() }
  emit("RAW_OBSERVATION",payload=JSONObject().put("enabled",rawEnabled));message="Raw observation: $rawEnabled"
 }
 fun reconnect()=command("refresh_subscriptions") { check(initialized);rawJobs.values.forEach { it.cancelAndJoin() };rawJobs.clear();observe() }
 fun unsupportedDisconnect(id:String)=command("disconnect/$id") { error("SDK public repository has no independent disconnect API. Use physical power-off/Bluetooth settings or persistent Remove. No private SDK bypass is used.") }
 fun startComputed(family:String,weight:String,height:String,gender:String)=command("computed_start") {
  check(initialized);val kg=weight.toDouble();val cm=height.toDouble();require(Sdk0256Compat.validBody(kg,cm));require(gender in listOf("MALE","FEMALE"))
  val body=Sdk0256Compat.body(Uuid.random(),"Inspector",kg,cm,Gender.valueOf(gender))
  profileRepository.insertOrUpdateBodyProfile(body).getOrThrow()
  trainingSessionRepository.initializeActiveTrainingSession(false,Sdk0256Compat.freeSession()).getOrThrow()
  trainingSessionRepository.readyActiveTrainingSession(TrainingSessionSensorType.valueOf(family)).getOrThrow()
  trainingSessionRepository.toggleActiveTrainingSessionState().getOrThrow()
 }
 fun finishComputed()=command("computed_finish") { trainingSessionRepository.finishActiveTrainingSession().getOrThrow() }
 fun snapshot():Any=JSONArray().also { a->devices.values.forEach { a.put(JSONObject().put("identity",it.json()).put("sdkMetadata",JSONObject(it.metadata.ifBlank { "{}" })).put("latestRawPacket",JSONObject(it.raw.ifBlank { "{}" })).put("observedRawCount",it.rawCount).put("observedComputedOccurrences",it.computedCount)) } }
 suspend fun beginRecording(){devices.keys.toList().forEach { id->devices[id]=devices.getValue(id).copy(rawCount=0,computedCount=0) };recorder.start(snapshot());emit("RECORDING_STARTED",payload=JSONObject().put("applicationStartedUtc",started).put("sdkInitialized",initialized).put("bluetooth",bluetooth()).put("devices",snapshot()))}
 suspend fun endRecording(){emit("RECORDING_STOPPED");recorder.stop(snapshot())}
}
