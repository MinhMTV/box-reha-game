package com.digitaldojo.sdkinspector

import android.Manifest
import android.app.Application
import android.content.*
import android.os.*
import android.provider.Settings
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.horizontalScroll
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.Alignment
import androidx.compose.ui.unit.dp
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.viewmodel.compose.viewModel
import org.json.JSONObject
import org.json.JSONArray
import java.io.File

class InspectorViewModel(app:Application):AndroidViewModel(app){val manager=(app as InspectorApp).manager}
class MainActivity:ComponentActivity(){
 private val manager get()=(application as InspectorApp).manager
 private var exportFile:File?=null
 private val permissionRequest=registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()){result->manager.command("permissions"){manager.emit("PERMISSIONS",payload=JSONObject(result))}}
 private val export=registerForActivityResult(ActivityResultContracts.CreateDocument("application/zip")){uri->val f=exportFile;if(uri!=null&&f!=null)manager.command("export"){manager.recorder.export(f,uri)}}
 private val bluetoothReceiver=object:BroadcastReceiver(){override fun onReceive(c:Context?,i:Intent?){manager.command("bluetooth_change"){manager.emit("BLUETOOTH",payload=JSONObject().put("state",manager.bluetooth()))}}}
 @OptIn(ExperimentalMaterial3Api::class)
 override fun onCreate(savedInstanceState:Bundle?){super.onCreate(savedInstanceState)
  registerReceiver(bluetoothReceiver,IntentFilter(android.bluetooth.BluetoothAdapter.ACTION_STATE_CHANGED))
  setContent {
   val vm:InspectorViewModel=viewModel();val m=vm.manager;val state by m.state.collectAsState();val recording=state.recording
   var page by remember { mutableStateOf("Devices") };var typeFilter by remember { mutableStateOf("All") };var deviceFilter by remember { mutableStateOf("") };var selected by remember { mutableStateOf("") }
   var weight by remember { mutableStateOf("") };var height by remember { mutableStateOf("") };var gender by remember { mutableStateOf("") };var family by remember { mutableStateOf("ALPHA") }
   var delete by remember { mutableStateOf<File?>(null) }
   MaterialTheme(colorScheme=darkColorScheme()) {
    Scaffold(topBar={TopAppBar(title={Column{Text("Dynamics SDK Inspector");Text("0.25.6 · compatibility build",style=MaterialTheme.typography.labelSmall)}})},bottomBar={NavigationBar{listOf("Devices","Live","Log","Sessions").forEachIndexed { i,name->NavigationBarItem(selected=page==name,onClick={page=name},icon={Text(listOf("◉","≋","≡","▣")[i])},label={Text(name)})}}}) { padding ->
     LazyColumn(Modifier.fillMaxSize().padding(padding).padding(horizontal=16.dp),verticalArrangement=Arrangement.spacedBy(12.dp)) {
      item { Card { Column(Modifier.padding(16.dp),verticalArrangement=Arrangement.spacedBy(6.dp)) {
       ValueRow("Bluetooth",state.bluetooth);ValueRow("Permissions",if(state.permissions)"Granted" else "Required");ValueRow("SDK",state.sdkState);ValueRow("Recording",if(recording.recording)"REC · ${(SystemClock.elapsedRealtime()-recording.started)/1000}s" else "OFF")
       if(recording.recording)Text("${recording.events} events · ${recording.raw} raw · ${recording.bytes} bytes",style=MaterialTheme.typography.bodySmall)
       Row(horizontalArrangement=Arrangement.spacedBy(8.dp)) {
        OutlinedButton(enabled=!recording.recording && state.permissions,onClick={try{startForegroundService(Intent(this@MainActivity,RecordingService::class.java))}catch(e:Exception){m.command("record"){throw e}}}){Text("Record")}
        OutlinedButton(enabled=recording.recording,onClick={startService(Intent(this@MainActivity,RecordingService::class.java).setAction("STOP"))}){Text("Stop recording")}
       }
       if(recording.failure.isNotBlank())Text(recording.failure,color=MaterialTheme.colorScheme.error)
      } } }
      if(state.message.isNotBlank())item { Text(state.message,style=MaterialTheme.typography.bodyMedium) }
      when(page){
       "Devices"->{
        if(state.scanBlocker.isNotEmpty())item { Card{Column(Modifier.padding(16.dp)){Text(state.scanBlocker);Row(Modifier.horizontalScroll(rememberScrollState())){
         if(!state.permissions)Button(onClick={permissionRequest.launch(permissions())}){Text("Grant permissions")}
         if(state.bluetooth!="ON"&&state.permissions)Button(onClick={startActivity(Intent(Settings.ACTION_BLUETOOTH_SETTINGS))}){Text("Enable Bluetooth")}
         if(state.scanBlocker.contains("location services"))Button(onClick={startActivity(Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS))}){Text("Enable location")}
         if(!state.initialized)Button(enabled=state.permissions&&!state.busy,onClick={m.initialize()}){Text("Initialize SDK")}
        };TextButton(onClick={startActivity(Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS,android.net.Uri.parse("package:$packageName")))}){Text("App permission settings")}}} }
        item { Button(modifier=Modifier.fillMaxWidth(),enabled=state.scanning||state.scanBlocker.isEmpty()&&!state.busy,onClick={if(state.scanning)m.stopScan() else m.scan()}){Text(if(state.scanning)"SCANNING…  STOP" else "SCAN FOR DEVICES")} }
        item{Text("CONNECTED",style=MaterialTheme.typography.titleMedium)}
        if(state.devices.none{it.connection=="CONNECTED"})item{Text("No connected sensors",style=MaterialTheme.typography.bodySmall)}
        items(state.devices.filter{it.connection=="CONNECTED"},key={it.id}){d->DeviceCard(d,state.busy,m)}
        item{Text("SAVED",style=MaterialTheme.typography.titleMedium)}
        if(state.devices.none{it.connection!="CONNECTED"})item{Text("No offline saved sensors",style=MaterialTheme.typography.bodySmall)}
        items(state.devices.filter{it.connection!="CONNECTED"},key={it.id}){d->DeviceCard(d,state.busy,m)}
        item{Text("DISCOVERED",style=MaterialTheme.typography.titleMedium)}
        if(state.nearby.isEmpty())item{Text(if(state.scanning)"Listening for nearby SDK sensors…" else "Start a scan to add a sensor.")}
        items(state.nearby,key={it.first}){(id,data)->val json=runCatching{JSONObject(data)}.getOrNull();Card{Column(Modifier.padding(16.dp),verticalArrangement=Arrangement.spacedBy(6.dp)){
         Text(json?.optString("advertisingName")?.takeIf{it.isNotBlank()&&it!="null"}?:"Unnamed sensor",style=MaterialTheme.typography.titleMedium)
         ValueRow("Discovery address",id);ValueRow("PeripheralId","Assigned by SDK after pairing");ValueRow("Family / side","UNKNOWN / unassigned");ValueRow("RSSI",json?.optString("rssi")?.plus(" dBm")?:"Unavailable");ValueRow("State","Discovered · not connected")
         Text("Choose its physical side. SDK reports hand/foot family after connection.",style=MaterialTheme.typography.bodySmall)
         Row(horizontalArrangement=Arrangement.spacedBy(8.dp)){Button(enabled=!state.busy&&state.scanBlocker.isEmpty(),onClick={m.pair(id,true)}){Text("Pair LEFT")};Button(enabled=!state.busy&&state.scanBlocker.isEmpty(),onClick={m.pair(id,false)}){Text("Pair RIGHT")}}
         Detail("SDK discovery metadata",data)
        }}}
        item{OutlinedButton(enabled=state.initialized&&!state.busy,onClick={m.reconnect()}){Text("Refresh SDK observations")};Text("SDK manages connections to saved sensors automatically. Independent connect/disconnect is not exposed by its public repository. Remove deletes the saved pairing.",style=MaterialTheme.typography.bodySmall)}
       }
       "Live"->{
        item { Row(Modifier.horizontalScroll(rememberScrollState()),horizontalArrangement=Arrangement.spacedBy(8.dp)){state.devices.forEach { d->FilterChip(selected=selected==d.id,onClick={selected=d.id},label={Text("${d.role} · ${d.name}")})}} }
        item{Card{Column(Modifier.padding(16.dp)){Row(verticalAlignment=Alignment.CenterVertically){Text("Raw sensor stream",Modifier.weight(1f),style=MaterialTheme.typography.titleMedium);Switch(checked=state.rawEnabled,enabled=state.initialized&&!state.busy,onCheckedChange={m.setRawEnabled(it)})};Text("Streams high-frequency sensor packets. Turning this off leaves device and computed observations running.",style=MaterialTheme.typography.bodySmall);Text(if(!state.rawEnabled)"OFF" else if(state.devices.any{it.rawReceived>0 && SystemClock.elapsedRealtime()-it.rawReceived<2000})"ACTIVE" else "ON · waiting for packets")}}}
        val d=state.devices.firstOrNull{it.id==selected}
        if(d==null)item{Text("Select a sensor above to inspect its values.")}
        else {
         item{Text("${d.name} · ${d.role}",style=MaterialTheme.typography.titleLarge);Text("${d.rawCount} raw packets · ${d.computedCount} computed occurrences")}
         if(d.punchReceived>0&&SystemClock.elapsedRealtime()-d.punchReceived<1200)item{Card(colors=CardDefaults.cardColors(containerColor=MaterialTheme.colorScheme.primaryContainer)){Text("PUNCH DETECTED � ${d.role}",Modifier.padding(20.dp),style=MaterialTheme.typography.headlineSmall)}}
         item{SensorValues(d)}
        }
        item{var open by remember{mutableStateOf(false)};TextButton(onClick={open=!open}){Text("Computed session / SDK body profile")};if(open){Text("Required only for computed Punch events. Values remain in the local SDK profile. One family per session.");OutlinedTextField(weight,{weight=it},label={Text("Weight kg")},modifier=Modifier.fillMaxWidth());OutlinedTextField(height,{height=it},label={Text("Height cm")},modifier=Modifier.fillMaxWidth());Row{listOf("MALE","FEMALE").forEach{g->FilterChip(selected=gender==g,onClick={gender=g},label={Text(g)})}};Row{listOf("ALPHA","DELTA").forEach{f->FilterChip(selected=family==f,onClick={family=f},label={Text(f)})}};Button(enabled=state.initialized&&!state.busy,onClick={m.startComputed(family,weight,height,gender)}){Text("Start computed session")};OutlinedButton(enabled=state.initialized&&!state.busy,onClick={m.finishComputed()}){Text("Finish SDK session")}}}
       }
       "Log"->{
        item{Text("Event type");Row(Modifier.horizontalScroll(rememberScrollState())){listOf("All","Raw","Computed","Device","Error").forEach{f->FilterChip(selected=typeFilter==f,onClick={typeFilter=f},label={Text(f)})}};Text("Device");Row(Modifier.horizontalScroll(rememberScrollState())){FilterChip(selected=deviceFilter.isEmpty(),onClick={deviceFilter=""},label={Text("All")});state.devices.forEach{d->FilterChip(selected=deviceFilter==d.id,onClick={deviceFilter=d.id},label={Text(d.name)})}}}
        items(state.events.asReversed().filter{e->(deviceFilter.isEmpty()||e.deviceId==deviceFilter)&&when(typeFilter){"Raw"->e.type=="RAW_SENSOR";"Computed"->e.type.startsWith("COMPUTED");"Error"->e.type=="ERROR";"Device"->e.type.contains("DEVICE")||e.type.contains("RESULT")||e.type=="DISCOVERED";else->true}}){e->Card{Column(Modifier.padding(12.dp)){Text("${e.time} · ${e.role}",style=MaterialTheme.typography.labelMedium);Text(e.type,style=MaterialTheme.typography.titleSmall);Text(e.summary,maxLines=2,style=MaterialTheme.typography.bodySmall);Detail("Event JSON preview (complete payload in recording)",e.text)}}}
       }
       "Sessions"->{items(state.sessions){name->val dir=File(m.recorder.root,name);Card{Column(Modifier.padding(16.dp)){Text(name,style=MaterialTheme.typography.titleSmall);Row{Button(enabled=!(recording.recording&&recording.session==name),onClick={exportFile=dir;export.launch("DynamicsSDK_$name.zip")}){Text("Export ZIP")};TextButton(enabled=!(recording.recording&&recording.session==name),onClick={delete=dir}){Text("Delete")}}}}}}
      }
      item{Spacer(Modifier.height(12.dp))}
     }
    }
    delete?.let { f->AlertDialog(onDismissRequest={delete=null},title={Text("Delete recording?")},text={Text(f.name)},confirmButton={TextButton(onClick={m.command("delete_recording"){m.recorder.delete(f)};delete=null}){Text("Delete permanently")}},dismissButton={TextButton(onClick={delete=null}){Text("Cancel")}}) }
   }
  }
 }
 private fun permissions():Array<String> = (if(Build.VERSION.SDK_INT>=31)listOf(Manifest.permission.BLUETOOTH_SCAN,Manifest.permission.BLUETOOTH_CONNECT) else listOf(Manifest.permission.ACCESS_FINE_LOCATION)).let{if(Build.VERSION.SDK_INT>=33)it+Manifest.permission.POST_NOTIFICATIONS else it}.toTypedArray()
 override fun onStop(){super.onStop();manager.command("activity_background"){manager.emit("APP_BACKGROUND")}}
 override fun onStart(){super.onStart();manager.command("activity_foreground"){manager.emit("APP_FOREGROUND")}}
 override fun onDestroy(){unregisterReceiver(bluetoothReceiver);manager.command("activity_destroyed"){manager.emit("APP_ACTIVITY_DESTROYED")};super.onDestroy()}
}
@Composable fun ValueRow(label:String,value:String){Row(Modifier.fillMaxWidth(),horizontalArrangement=Arrangement.spacedBy(12.dp)){Text(label,Modifier.weight(1f),style=MaterialTheme.typography.bodySmall,color=MaterialTheme.colorScheme.onSurfaceVariant);Text(value,Modifier.weight(1.3f),style=MaterialTheme.typography.bodyMedium)}}
@Composable fun Detail(title:String,value:String){var open by remember{mutableStateOf(false)};Column{TextButton(onClick={open=!open}){Text((if(open)"▼ " else "▶ ")+title)};if(open)Text(value.ifBlank{"No observed data"},style=MaterialTheme.typography.bodySmall)}}
@Composable fun DeviceCard(d:DeviceState,busy:Boolean,m:DynamicsSdkManager){Card{Column(Modifier.padding(16.dp),verticalArrangement=Arrangement.spacedBy(6.dp)){Text(d.name,style=MaterialTheme.typography.titleMedium);Text(d.role,color=MaterialTheme.colorScheme.primary);ValueRow("PeripheralId",d.id);ValueRow("Family / side","${d.family} / ${d.side}");ValueRow("State",d.connection);if(d.family=="UNKNOWN")Text("Family is not reported yet. No role inferred from the name.",style=MaterialTheme.typography.bodySmall);Row(horizontalArrangement=Arrangement.spacedBy(8.dp)){OutlinedButton(enabled=!busy,onClick={m.swap(d.id)}){Text(if(d.family=="UNKNOWN")"Swap SDK side" else "To "+(if(d.side=="LEFT")"RIGHT " else "LEFT ")+(if(d.family=="ALPHA")"HAND" else "FOOT"))};OutlinedButton(enabled=!busy,onClick={m.remove(d.id)}){Text("Remove")}};Text("Side changes may swap both members of the SDK pair.",Modifier.padding(horizontal=16.dp),style=MaterialTheme.typography.bodySmall);Detail("SDK device metadata",d.metadata)}}
}
@Composable fun FieldCard(title:String,value:Any?){Card{Column(Modifier.padding(16.dp),verticalArrangement=Arrangement.spacedBy(6.dp)){Text(title,style=MaterialTheme.typography.titleMedium);if(value==null||value==JSONObject.NULL)Text("No observed value",style=MaterialTheme.typography.bodySmall) else if(value is JSONObject){value.keys().asSequence().filter{!it.startsWith("_")}.forEach{key->ValueRow(key,value.opt(key)?.toString()?:"Unavailable")}}else Text(value?.toString()?:"Unavailable")}}}
@Composable fun SensorValues(d:DeviceState){val raw=runCatching{JSONObject(d.raw)}.getOrNull();val computed=runCatching{JSONObject(d.computed)}.getOrNull();Column(verticalArrangement=Arrangement.spacedBy(12.dp)){
 for((title,key) in listOf("ACCELEROMETER" to "accData","GYROSCOPE" to "gyroData","MAGNETOMETER" to "magnetoData","BAROMETER" to "baroData")){val list=raw?.optJSONArray(key);FieldCard(title,list?.opt(list.length()-1))}
 FieldCard("SAMPLING RATE (Hz)",raw?.opt("samplingRate"))
 FieldCard("PACKET",raw?.let{JSONObject().put("Sampling rate",it.opt("samplingRate")).put("BLE counter",it.opt("bleCounter")).put("Relative counter (SDK packed duration)",it.opt("relativeTimeCounter")).put("Relative seconds",if(it.opt("relativeTimeCounter") is Number)com.boxreha.dynamics.Sdk0256Compat.durationSeconds(it.getLong("relativeTimeCounter")) else JSONObject.NULL).put("Last received (monotonic ms)",d.rawReceived)})
 FieldCard("COMPUTED · latest Punch",computed?.let{JSONObject().put("SDK timestamp",it.opt("timestamp")).put("Valid computed values",it.opt("areComputedValuesValid"))});FieldCard("SPEED",computed?.optJSONObject("speed")?.let { original -> JSONObject(original.toString()).apply { for(key in listOf("punchDuration","contactDuration"))if(has(key)&&opt(key) is Number){put(key+"Seconds",com.boxreha.dynamics.Sdk0256Compat.durationSeconds(getLong(key)));remove(key)} } });FieldCard("POWER / POWER INDEX",computed?.opt("power"));Text("SDK units retained. DELTA powerIndex is not physical force. Duration fields retain SDK packed values in the recording.",style=MaterialTheme.typography.bodySmall);Detail("All raw packet fields",d.raw);Detail("All computed fields",d.computed)
}}
