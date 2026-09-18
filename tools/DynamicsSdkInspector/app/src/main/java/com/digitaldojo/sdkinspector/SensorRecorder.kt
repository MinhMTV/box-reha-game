package com.digitaldojo.sdkinspector

import android.content.Context
import android.os.Build
import android.os.SystemClock
import kotlinx.coroutines.*
import kotlinx.coroutines.channels.Channel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.sync.Mutex
import kotlinx.coroutines.sync.withLock
import org.json.JSONObject
import java.io.File
import java.time.Instant
import java.util.UUID
import java.util.concurrent.atomic.AtomicInteger
import java.util.zip.*

data class RecordingStatus(val recording:Boolean=false,val session:String="",val events:Long=0,val raw:Long=0,val computed:Long=0,val errors:Long=0,val bytes:Long=0,val started:Long=0,val failure:String="",val queueDepth:Int=0,val warning:String="")
class SensorRecorder(private val context:Context) {
 val status=MutableStateFlow(RecordingStatus())
 val root=File(context.filesDir,"sessions").apply { mkdirs() }
 private val scope=CoroutineScope(SupervisorJob()+Dispatchers.IO)
 private val gate=Mutex()
 private var channel:Channel<String>?=null
 private var writer:Job?=null
 private var folder:File?=null
 private var metadata=JSONObject()
 private val pending=AtomicInteger()
 suspend fun start(devices:Any, acquisitionMode:String = "IDLE") = gate.withLock {
  check(channel==null) { "Recording already active" }
  val id="sdk_session_"+Instant.now().toString().replace(':','-')+"_"+UUID.randomUUID().toString().take(8)
  val dir=File(root,id);check(dir.mkdir());folder=dir
  metadata=JSONObject().put("schemaVersion",1).put("appVersion",BuildConfig.VERSION_NAME).put("androidVersion",Build.VERSION.RELEASE).put("api",Build.VERSION.SDK_INT).put("deviceModel",Build.MANUFACTURER+" "+Build.MODEL).put("sdkVersion","0.25.6").put("sdkMode","COMPATIBILITY").put("startUtc",Instant.now().toString()).put("devicesAtStart",devices).put("complete",false)
  metadata.put("schemaVersion",2).put("acquisitionModeAtStart",acquisitionMode)
  withContext(Dispatchers.IO) { File(dir,"metadata.json").writeText(metadata.toString(2)) }
  pending.set(0)
  val queue=Channel<String>(256);channel=queue
  status.value=RecordingStatus(true,id,started=SystemClock.elapsedRealtime())
  writer=scope.launch {
   try {
    File(dir,"events.jsonl.partial").bufferedWriter().use { out ->
     var flushAt=SystemClock.elapsedRealtime()
     while(true) {
      val received=withTimeoutOrNull(1000) { queue.receiveCatching() }
      if(received==null) { out.flush();continue }
      if(received.isClosed) break
      val line=received.getOrThrow()
      out.write(line);out.newLine()
      val depth=pending.decrementAndGet()
      val event=JSONObject(line);val type=event.getString("eventType");val s=status.value
      status.value=s.copy(events=s.events+1,raw=s.raw+if(type=="RAW_SENSOR")1 else 0,computed=s.computed+if(type=="COMPUTED_EVENT")1 else 0,errors=s.errors+if(type=="ERROR")1 else 0,bytes=s.bytes+line.toByteArray(Charsets.UTF_8).size+1,queueDepth=depth,warning=if(depth>=192) "RECORDING_BACKLOG" else "")
      if(depth>=192 && s.warning.isEmpty()) android.util.Log.w("DynamicsInspector", "RECORDING_BACKLOG queueDepth=$depth; producer backpressure enabled")
      if(SystemClock.elapsedRealtime()-flushAt>=1000){out.flush();flushAt=SystemClock.elapsedRealtime()}
     }
     out.flush()
    }
   } catch(e:Throwable) {
    status.value=status.value.copy(recording=false,failure=e.stackTraceToString());queue.close(e)
    runCatching { File(dir,"recording-error.txt").writeText(e.stackTraceToString()) }
   }
  }
 }
 // Bounded queue + suspension/backpressure: no DROP_OLDEST, no per-packet launched coroutine.
 suspend fun append(line:String)=gate.withLock {
  channel?.let { q ->
   pending.incrementAndGet()
   try { q.send(line) } catch(e:Throwable) { pending.decrementAndGet();throw e }
  }
 }
 suspend fun stop(devices:Any, acquisitionMode:String = "IDLE")=gate.withLock {
  if(channel==null && writer==null) return@withLock
  channel?.close();channel=null;writer?.join();writer=null
  val s=status.value
  metadata.put("acquisitionModeAtEnd",acquisitionMode)
  metadata.put("endUtc",Instant.now().toString()).put("durationMs",SystemClock.elapsedRealtime()-s.started).put("events",s.events).put("rawPackets",s.raw).put("computedEvents",s.computed).put("errors",s.errors).put("bytes",s.bytes).put("devicesAtEnd",devices).put("complete",s.failure.isEmpty()).put("writerFailure",s.failure)
  withContext(Dispatchers.IO) { folder?.let {
   if(s.failure.isEmpty()) check(File(it,"events.jsonl.partial").renameTo(File(it,"events.jsonl"))) { "Could not finalize recording; partial preserved" }
   File(it,"metadata.json").writeText(metadata.toString(2))
  } };status.value=s.copy(recording=false)
 }
 fun sessions():List<File> = root.listFiles()?.filter { it.isDirectory }?.sortedByDescending { it.name }?:emptyList()
 suspend fun export(dir:File,uri:android.net.Uri)=withContext(Dispatchers.IO) {
  require(dir.canonicalFile.parentFile==root.canonicalFile && dir.name!=status.value.takeIf { it.recording }?.session)
  context.contentResolver.openOutputStream(uri)?.use { stream -> ZipOutputStream(stream).use { zip ->
   for(name in listOf("metadata.json","events.jsonl","events.jsonl.partial","recording-error.txt")) {
    val f=File(dir,name);if(f.exists()){zip.putNextEntry(ZipEntry(name));f.inputStream().use { it.copyTo(zip) };zip.closeEntry()}
   }
  }}?:error("Cannot open export destination")
 }
 suspend fun delete(dir:File)=withContext(Dispatchers.IO) {
  require(dir.canonicalFile.parentFile==root.canonicalFile && dir.name!=status.value.takeIf { it.recording }?.session)
  check(dir.deleteRecursively()) { "Delete failed" }
 }
}
