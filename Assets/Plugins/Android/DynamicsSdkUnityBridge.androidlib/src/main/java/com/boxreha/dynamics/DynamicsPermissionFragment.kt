@file:Suppress("DEPRECATION")
package com.boxreha.dynamics

import android.app.Fragment
import android.os.Bundle

/** Owns the Android permission result without replacing Unity's Activity. */
class DynamicsPermissionFragment : Fragment() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        if (savedInstanceState == null) requestPermissions(DynamicsCollector.missingPermissions(), 6402)
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        if (requestCode != 6402) return
        val permanentlyDenied = permissions.indices.any { index ->
            index < grantResults.size && grantResults[index] == android.content.pm.PackageManager.PERMISSION_DENIED &&
                !shouldShowRequestPermissionRationale(permissions[index])
        }
        DynamicsCollector.permissionsChanged(permanentlyDenied)
        fragmentManager?.beginTransaction()?.remove(this)?.commitAllowingStateLoss()
    }
}
