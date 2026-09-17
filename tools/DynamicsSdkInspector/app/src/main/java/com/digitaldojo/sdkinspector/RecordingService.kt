package com.digitaldojo.sdkinspector
import android.app.*
import android.content.Intent
import android.os.*
import kotlinx.coroutines.*
class RecordingService:Service(){
 private val scope=CoroutineScope(SupervisorJob()+Dispatchers.Main.immediate)
 private val manager get()=(application as InspectorApp).manager
 private var wake:PowerManager.WakeLock?=null
 override fun onBind(intent:Intent?)=null
 override fun onStartCommand(intent:Intent?,flags:Int,startId:Int):Int {
  if(intent?.action=="STOP"){scope.launch { manager.endRecording();stopForeground(STOP_FOREGROUND_REMOVE);stopSelf() };return START_NOT_STICKY}
  val nm=getSystemService(NotificationManager::class.java);nm.createNotificationChannel(NotificationChannel("recording","Sensor recording",NotificationManager.IMPORTANCE_LOW))
  val stop=PendingIntent.getService(this,2,Intent(this,RecordingService::class.java).setAction("STOP"),PendingIntent.FLAG_IMMUTABLE)
  val open=PendingIntent.getActivity(this,1,Intent(this,MainActivity::class.java),PendingIntent.FLAG_IMMUTABLE)
  startForeground(1,Notification.Builder(this,"recording").setContentTitle("Dynamics SDK Inspector").setContentText("Recording sensor data").setSmallIcon(android.R.drawable.stat_notify_sync).setContentIntent(open).addAction(android.R.drawable.ic_media_pause,"Stop",stop).setOngoing(true).build())
  if(!manager.recorder.status.value.recording)scope.launch {
   try { manager.beginRecording();wake=getSystemService(PowerManager::class.java).newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,"SdkInspector:recording").apply { acquire() }
    manager.recorder.status.collect { if(it.failure.isNotEmpty()){manager.error("writer",IllegalStateException(it.failure));stopForeground(STOP_FOREGROUND_REMOVE);stopSelf()} }
   }catch(e:Exception){manager.error("recording_start",e);stopSelf()}
  }
  return START_NOT_STICKY
 }
 override fun onDestroy(){wake?.let { if(it.isHeld)it.release() };scope.cancel();if(manager.recorder.status.value.recording)manager.scope.launch { manager.endRecording() };super.onDestroy()}
}
