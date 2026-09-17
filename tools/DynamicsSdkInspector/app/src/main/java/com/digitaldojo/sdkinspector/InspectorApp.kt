package com.digitaldojo.sdkinspector
import android.app.Application
class InspectorApp:Application(){lateinit var manager:DynamicsSdkManager
 override fun onCreate(){super.onCreate();manager=DynamicsSdkManager(this)}
}
