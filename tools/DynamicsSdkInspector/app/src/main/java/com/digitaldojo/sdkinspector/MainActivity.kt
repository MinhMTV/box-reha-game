package com.digitaldojo.sdkinspector

import android.Manifest
import android.content.*
import android.bluetooth.BluetoothAdapter
import android.os.Build
import android.os.Bundle
import android.os.SystemClock
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.horizontalScroll
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.*
import androidx.compose.foundation.rememberScrollState
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import org.json.JSONObject
import java.io.File
import kotlinx.coroutines.launch

class MainActivity : ComponentActivity() {
    private val manager: DynamicsSdkManager by lazy { (application as InspectorApp).manager }
    private val requestPermission = registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()) {
        manager.command("permissions_result") {
            manager.emit("PERMISSIONS_RESULT", payload = JSONObject().put("granted", manager.missingPermissions().isEmpty()))
        }
    }
    private val bluetoothReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context?, intent: Intent?) {
            if (intent?.action == BluetoothAdapter.ACTION_STATE_CHANGED) {
                manager.command("bluetooth_changed") {
                    manager.emit("BLUETOOTH_STATE", payload = JSONObject().put("bluetooth", manager.bluetooth()))
                }
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        registerReceiver(bluetoothReceiver, IntentFilter(BluetoothAdapter.ACTION_STATE_CHANGED))
        setContent {
            MaterialTheme(colorScheme = darkColorScheme()) {
                InspectorScreen(manager) { requestPermission.launch(permissions()) }
            }
        }
    }

    private fun permissions(): Array<String> = (if (Build.VERSION.SDK_INT >= 31)
        listOf(Manifest.permission.BLUETOOTH_SCAN, Manifest.permission.BLUETOOTH_CONNECT)
    else listOf(Manifest.permission.ACCESS_FINE_LOCATION)).let {
        if (Build.VERSION.SDK_INT >= 33) it + Manifest.permission.POST_NOTIFICATIONS else it
    }.toTypedArray()

    override fun onStop() {
        super.onStop()
        manager.command("activity_background") { manager.emit("APP_BACKGROUND") }
    }

    override fun onStart() {
        super.onStart()
        manager.command("activity_foreground") { manager.emit("APP_FOREGROUND") }
    }

    override fun onDestroy() {
        unregisterReceiver(bluetoothReceiver)
        manager.command("activity_destroyed") { manager.emit("APP_ACTIVITY_DESTROYED") }
        super.onDestroy()
    }
}

@Composable
fun InspectorScreen(m: DynamicsSdkManager, requestPermissions: () -> Unit) {
    val state by m.state.collectAsState()
    var tab by remember { mutableStateOf("Sensors") }
    var selectedDevice by remember { mutableStateOf("") }
    var typeFilter by remember { mutableStateOf("All") }
    var deviceFilter by remember { mutableStateOf("") }
    var weight by remember { mutableStateOf("75") }
    var height by remember { mutableStateOf("175") }
    var gender by remember { mutableStateOf("MALE") }
    var family by remember { mutableStateOf("ALPHA") }
    var customMarker by remember { mutableStateOf("") }
    var showForgetAllDialog by remember { mutableStateOf(false) }
    var deleteSessionDir by remember { mutableStateOf<File?>(null) }
    var exportSessionDir by remember { mutableStateOf<File?>(null) }

    val exportLauncher = androidx.activity.compose.rememberLauncherForActivityResult(
        ActivityResultContracts.CreateDocument("application/zip")
    ) { uri ->
        if (uri != null && exportSessionDir != null) {
            m.command("export") { m.recorder.export(exportSessionDir!!, uri) }
        }
        exportSessionDir = null
    }

    Scaffold { padding ->
        Column(Modifier.padding(padding).fillMaxSize().padding(16.dp), verticalArrangement = Arrangement.spacedBy(12.dp)) {
            Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween) {
                Column {
                    Text("Dynamics SDK 0.25.6 Inspector", style = MaterialTheme.typography.titleMedium)
                    Text(
                        "${state.sdkState} | BT: ${state.bluetooth} | Scanner: ${state.scannerStateString}",
                        style = MaterialTheme.typography.bodySmall,
                        color = MaterialTheme.colorScheme.onSurfaceVariant
                    )
                }
                Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                    if (!state.permissions) {
                        Button(onClick = requestPermissions) { Text("Grant permissions") }
                    } else if (!state.initialized) {
                        Button(enabled = !state.busy, onClick = { m.initialize() }) { Text("Initialize SDK") }
                    }
                    if (state.recording.recording) {
                        Button(
                            colors = ButtonDefaults.buttonColors(containerColor = MaterialTheme.colorScheme.error),
                            onClick = { m.app.startService(Intent(m.app, RecordingService::class.java).setAction("STOP")) }
                        ) { Text("Stop recording") }
                    } else {
                        OutlinedButton(enabled = state.initialized && !state.busy, onClick = { androidx.core.content.ContextCompat.startForegroundService(m.app, Intent(m.app, RecordingService::class.java)) }) {
                            Text("Record JSONL")
                        }
                    }
                }
            }

            if (state.message.isNotBlank()) {
                Card(colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.secondaryContainer)) {
                    Text(state.message, Modifier.padding(12.dp), style = MaterialTheme.typography.bodySmall)
                }
            }

            Text("Mode: ${state.acquisitionMode} | Recorder queue: ${state.recording.queueDepth} ${state.recording.warning}", style = MaterialTheme.typography.bodySmall)
            if (state.recording.failure.isNotEmpty()) Text("Recording failed: ${state.recording.failure.lineSequence().first()}", color = MaterialTheme.colorScheme.error)
            TabRow(selectedTabIndex = listOf("Sensors", "Inspector", "Log", "Sessions").indexOf(tab)) {
                listOf("Sensors", "Inspector", "Log", "Sessions").forEach { name ->
                    Tab(selected = tab == name, onClick = { tab = name }, text = { Text(name) })
                }
            }

            LazyColumn(Modifier.fillMaxSize(), verticalArrangement = Arrangement.spacedBy(12.dp)) {
                when (tab) {
                    "Sensors" -> {
                        item {
                            Card {
                                Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(8.dp)) {
                                    Text("Nearby Discovery", style = MaterialTheme.typography.titleMedium)
                                    Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                        if (state.scanning) {
                                            Button(
                                                colors = ButtonDefaults.buttonColors(containerColor = MaterialTheme.colorScheme.error),
                                                enabled = !state.busy,
                                                onClick = { m.stopScan() }
                                            ) { Text("Stop scan") }
                                        } else {
                                            Button(
                                                enabled = state.initialized && state.permissions && !state.busy,
                                                onClick = { m.scan() }
                                            ) { Text("Scan for sensors") }
                                        }
                                        OutlinedButton(
                                            enabled = state.initialized && state.devices.isNotEmpty() && !state.busy && !state.activeSessionRunning,
                                            onClick = { showForgetAllDialog = true }
                                        ) { Text("Forget all sensors") }
                                    }
                                    if (state.nearby.isEmpty()) {
                                        Text(
                                            if (state.scanning) "Scanning for advertising Dynamics sensors…" else "No nearby sensors discovered. Tap Scan to search.",
                                            style = MaterialTheme.typography.bodySmall,
                                            color = MaterialTheme.colorScheme.onSurfaceVariant
                                        )
                                    } else {
                                        state.nearby.forEach { (address, name) ->
                                            Card(colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surfaceVariant)) {
                                                Row(
                                                    Modifier.fillMaxWidth().padding(12.dp),
                                                    horizontalArrangement = Arrangement.SpaceBetween
                                                ) {
                                                    Column {
                                                        Text(name, style = MaterialTheme.typography.bodyMedium)
                                                        Text(address, style = MaterialTheme.typography.bodySmall)
                                                    }
                                                    Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                                        Button(enabled = !state.busy && !state.activeSessionRunning && !state.rawEnabled, onClick = { m.pair(address, true) }) { Text("Pair LEFT") }
                                                        Button(enabled = !state.busy && !state.activeSessionRunning && !state.rawEnabled, onClick = { m.pair(address, false) }) { Text("Pair RIGHT") }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        item {
                            Text("Saved & Connected Sensors (${state.devices.size})", style = MaterialTheme.typography.titleMedium)
                        }

                        if (state.devices.isEmpty()) {
                            item {
                                Text("No sensors saved. Scan and pair a nearby sensor.", style = MaterialTheme.typography.bodyMedium, color = MaterialTheme.colorScheme.onSurfaceVariant)
                            }
                        } else {
                            items(state.devices) { dev ->
                                DeviceCard(dev, state.busy || state.activeSessionRunning || state.rawEnabled, m)
                            }
                        }
                    }

                    "Inspector" -> {
                        item {
                            Text("Manual annotations — no automatic recognition", style = MaterialTheme.typography.titleSmall)
                            Row(Modifier.horizontalScroll(rememberScrollState()), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                listOf("STRAIGHT", "HOOK", "UPPERCUT", "KICK").forEach { label ->
                                    OutlinedButton(enabled = state.recording.recording, onClick = { m.marker(label, selectedDevice.ifBlank { state.devices.firstOrNull()?.id ?: "" }) }) { Text("MARK $label") }
                                }
                            }
                            OutlinedTextField(value = customMarker, onValueChange = { customMarker = it }, label = { Text("Custom marker text") })
                            OutlinedButton(enabled = state.recording.recording && customMarker.isNotBlank(), onClick = { m.marker("CUSTOM", selectedDevice.ifBlank { state.devices.firstOrNull()?.id ?: "" }, customMarker) }) { Text("CUSTOM MARKER") }
                        }
                        item {
                            Card {
                                Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(8.dp)) {
                                    Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween) {
                                        Text("Raw Sensor Acquisition", style = MaterialTheme.typography.titleMedium)
                                        Switch(
                                            checked = state.rawEnabled,
                                            enabled = state.initialized && !state.busy && !state.activeSessionRunning,
                                            onCheckedChange = { m.setRawEnabled(it) }
                                        )
                                    }
                                    Text(
                                        "Collects multi-sample SensorDataPacket data directly from SensorDataRepository without requiring a training session.",
                                        style = MaterialTheme.typography.bodySmall,
                                        color = MaterialTheme.colorScheme.onSurfaceVariant
                                    )
                                }
                            }
                        }

                        if (state.devices.isEmpty()) {
                            item { Text("No sensors available to inspect.") }
                        } else {
                            item {
                                Row(Modifier.horizontalScroll(rememberScrollState()), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                    state.devices.forEach { dev ->
                                        FilterChip(
                                            selected = selectedDevice == dev.id || (selectedDevice.isEmpty() && state.devices.first().id == dev.id),
                                            onClick = { selectedDevice = dev.id },
                                            label = { Text("${dev.name} (${dev.side})") }
                                        )
                                    }
                                }
                            }

                            val activeDev = state.devices.firstOrNull { it.id == selectedDevice } ?: state.devices.firstOrNull()
                            if (activeDev != null) {
                                item {
                                    Text("${activeDev.name} — ${activeDev.role}", style = MaterialTheme.typography.titleLarge)
                                    Text("${activeDev.rawCount} raw packets (${activeDev.rawPacketsPerSecond} pkts/s) | ${activeDev.computedCount} computed occurrences")
                                }

                                if (activeDev.lastPunchReceivedMonotonicMs > 0 && SystemClock.elapsedRealtime() - activeDev.lastPunchReceivedMonotonicMs < 1500) {
                                    item {
                                        Card(colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.primaryContainer)) {
                                            Text("PUNCH DETECTED — ${activeDev.role}", Modifier.padding(20.dp), style = MaterialTheme.typography.headlineSmall)
                                        }
                                    }
                                }

                                item {
                                    SensorValuesView(activeDev)
                                }
                            }
                        }

                        item {
                            Card {
                                Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(8.dp)) {
                                    Text("Computed Punch Session Lifecycle", style = MaterialTheme.typography.titleMedium)
                                    Text(
                                        "Active session state: ${state.activeSessionStateString}",
                                        style = MaterialTheme.typography.bodyMedium,
                                        color = MaterialTheme.colorScheme.primary
                                    )

                                    if (state.activeSessionRunning) {
                                        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                            Button(enabled = !state.busy, onClick = { m.finishComputed() }) {
                                                Text("Finish active session")
                                            }
                                            OutlinedButton(enabled = !state.busy, onClick = { m.deleteComputed() }) {
                                                Text("Discard session")
                                            }
                                        }
                                    } else {
                                        Text(
                                            "An active TrainingSession is required only for computed Punch data. Only one active session is permitted by the SDK.",
                                            style = MaterialTheme.typography.bodySmall,
                                            color = MaterialTheme.colorScheme.onSurfaceVariant
                                        )
                                        OutlinedTextField(value = weight, onValueChange = { weight = it }, label = { Text("Weight (kg, 20-250)") }, modifier = Modifier.fillMaxWidth())
                                        OutlinedTextField(value = height, onValueChange = { height = it }, label = { Text("Height (cm, 50-250)") }, modifier = Modifier.fillMaxWidth())
                                        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                            listOf("MALE", "FEMALE").forEach { g ->
                                                FilterChip(selected = gender == g, onClick = { gender = g }, label = { Text(g) })
                                            }
                                        }
                                        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                            listOf("ALPHA", "DELTA").forEach { f ->
                                                FilterChip(selected = family == f, onClick = { family = f }, label = { Text(f) })
                                            }
                                        }
                                        Button(
                                            enabled = state.initialized && !state.busy && !state.rawEnabled,
                                            onClick = { m.startComputed(family, weight, height, gender) }
                                        ) {
                                            Text("Start computed session")
                                        }
                                    }
                                }
                            }
                        }
                    }

                    "Log" -> {
                        item {
                            Text("Filter by Type", style = MaterialTheme.typography.labelMedium)
                            Row(Modifier.horizontalScroll(rememberScrollState()), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                listOf("All", "Raw", "Computed", "Device", "Error").forEach { f ->
                                    FilterChip(selected = typeFilter == f, onClick = { typeFilter = f }, label = { Text(f) })
                                }
                            }
                            Text("Filter by Device", style = MaterialTheme.typography.labelMedium)
                            Row(Modifier.horizontalScroll(rememberScrollState()), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                FilterChip(selected = deviceFilter.isEmpty(), onClick = { deviceFilter = "" }, label = { Text("All") })
                                state.devices.forEach { d ->
                                    FilterChip(selected = deviceFilter == d.id, onClick = { deviceFilter = d.id }, label = { Text(d.name) })
                                }
                            }
                        }

                        items(state.events.asReversed().filter { e ->
                            (deviceFilter.isEmpty() || e.deviceId == deviceFilter) && when (typeFilter) {
                                "Raw" -> e.type == "RAW_SENSOR"
                                "Computed" -> e.type.startsWith("COMPUTED")
                                "Error" -> e.type == "ERROR"
                                "Device" -> e.type.contains("DEVICE") || e.type.contains("RESULT") || e.type == "DISCOVERED"
                                else -> true
                            }
                        }) { e ->
                            Card {
                                Column(Modifier.padding(12.dp)) {
                                    Text("${e.time} — ${e.role}", style = MaterialTheme.typography.labelMedium)
                                    Text(e.type, style = MaterialTheme.typography.titleSmall)
                                    Text(e.summary, maxLines = 2, style = MaterialTheme.typography.bodySmall)
                                    Detail("Event JSON preview", e.text)
                                }
                            }
                        }
                    }

                    "Sessions" -> {
                        if (state.sessions.isEmpty()) {
                            item { Text("No recorded sessions found.") }
                        } else {
                            items(state.sessions) { name ->
                                val dir = File(m.recorder.root, name)
                                Card {
                                    Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(8.dp)) {
                                        Text(name, style = MaterialTheme.typography.titleSmall)
                                        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                                            Button(
                                                enabled = !(state.recording.recording && state.recording.session == name),
                                                onClick = {
                                                    exportSessionDir = dir
                                                    exportLauncher.launch("DynamicsSDK_$name.zip")
                                                }
                                            ) { Text("Export ZIP") }
                                            TextButton(
                                                enabled = !(state.recording.recording && state.recording.session == name),
                                                onClick = { deleteSessionDir = dir }
                                            ) { Text("Delete") }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (showForgetAllDialog) {
        AlertDialog(
            onDismissRequest = { showForgetAllDialog = false },
            title = { Text("Forget all sensors?") },
            text = { Text("This will delete all saved sensors from the SDK database and deinitialize all active BLE communication.") },
            confirmButton = {
                TextButton(
                    onClick = {
                        showForgetAllDialog = false
                        m.forgetAllSensors()
                    }
                ) { Text("Forget all", color = MaterialTheme.colorScheme.error) }
            },
            dismissButton = {
                TextButton(onClick = { showForgetAllDialog = false }) { Text("Cancel") }
            }
        )
    }

    deleteSessionDir?.let { dir ->
        AlertDialog(
            onDismissRequest = { deleteSessionDir = null },
            title = { Text("Delete recording?") },
            text = { Text(dir.name) },
            confirmButton = {
                TextButton(
                    onClick = {
                        m.command("delete_recording") { m.recorder.delete(dir) }
                        deleteSessionDir = null
                    }
                ) { Text("Delete permanently", color = MaterialTheme.colorScheme.error) }
            },
            dismissButton = {
                TextButton(onClick = { deleteSessionDir = null }) { Text("Cancel") }
            }
        )
    }
}

@Composable
fun ValueRow(label: String, value: String) {
    Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.spacedBy(12.dp)) {
        Text(label, Modifier.weight(1f), style = MaterialTheme.typography.bodySmall, color = MaterialTheme.colorScheme.onSurfaceVariant)
        Text(value, Modifier.weight(1.3f), style = MaterialTheme.typography.bodyMedium)
    }
}

@Composable
fun Detail(title: String, value: String) {
    var open by remember { mutableStateOf(false) }
    Column {
        TextButton(onClick = { open = !open }) {
            Text((if (open) "▼ " else "▶ ") + title)
        }
        if (open) {
            Text(value.ifBlank { "No observed data" }, style = MaterialTheme.typography.bodySmall)
        }
    }
}

@Composable
fun DeviceCard(d: DeviceState, busy: Boolean, m: DynamicsSdkManager) {
    Card {
        Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(6.dp)) {
            Text(d.name, style = MaterialTheme.typography.titleMedium)
            Text(d.role, color = MaterialTheme.colorScheme.primary, style = MaterialTheme.typography.titleSmall)
            ValueRow("Saved", if (d.saved) "YES" else "NO")
            ValueRow("Online", if (d.isOnline) "YES" else "NO")
            ValueRow("Bond", d.bondState)
            ValueRow("PeripheralId", d.id)
            ValueRow("BLE address", d.address)
            ValueRow("Family", d.family)
            ValueRow("Side", d.side)
            ValueRow("State", d.connectionStateString)
            Spacer(Modifier.height(4.dp))
            Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                OutlinedButton(enabled = !busy, onClick = { m.swap(d.id) }) {
                    Text("SWAP SIDE")
                }
                OutlinedButton(
                    colors = ButtonDefaults.outlinedButtonColors(contentColor = MaterialTheme.colorScheme.error),
                    enabled = !busy,
                    onClick = { m.remove(d.id) }
                ) {
                    Text("REMOVE / FORGET")
                }
            }
            Text(
                "Removes the sensor from the SDK and disconnects its BLE communication.",
                style = MaterialTheme.typography.bodySmall,
                color = MaterialTheme.colorScheme.onSurfaceVariant
            )
            Detail("SDK device metadata", d.metadataJson)
        }
    }
}

@Composable
fun SensorValuesView(d: DeviceState) {
    Column(verticalArrangement = Arrangement.spacedBy(12.dp)) {
        Card {
            Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(6.dp)) {
                Text("RAW TELEMETRY STATUS", style = MaterialTheme.typography.titleMedium)
                ValueRow("RAW SUBSCRIPTION", d.rawSubscriptionState)
                ValueRow("CONNECTION", d.connectionStateString)
                ValueRow("SDK OPERATIONAL STATE", d.operationalState)
                ValueRow("RELATIVE TIME COUNTER", d.latestRelativeTimeCounter.ifBlank { "None" })
                if (d.lastRawError.isNotBlank()) ValueRow("LAST RAW ERROR", d.lastRawError)
                ValueRow("PACKETS", "${d.rawCount}")
                ValueRow("PACKET RATE", "${d.rawPacketsPerSecond} packets/sec")
                ValueRow("LAST PACKET", if (d.lastRawReceivedMonotonicMs > 0) "${SystemClock.elapsedRealtime() - d.lastRawReceivedMonotonicMs} ms ago" else "None")
                ValueRow("LAST PACKET MONOTONIC NS", if (d.lastRawElapsedRealtimeNanos > 0) "${d.lastRawElapsedRealtimeNanos}" else "None")
                ValueRow("BLE COUNTER", "${d.latestBleCounter}")
                ValueRow("SAMPLING RATE", d.latestSamplingRate.ifBlank { "None" })
            }
        }

        Card {
            Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(6.dp)) {
                Text("LATEST SENSOR SAMPLES", style = MaterialTheme.typography.titleMedium)
                ValueRow("ACCELEROMETER", d.latestAcc.ifBlank { "None" })
                ValueRow("GYROSCOPE", d.latestGyro.ifBlank { "None" })
                ValueRow("MAGNETOMETER", d.latestMag.ifBlank { "None" })
                ValueRow("BAROMETER", d.latestBaro.ifBlank { "None" })
            }
        }

        if (d.latestPunchJson.isNotBlank()) {
            Card {
                Column(Modifier.padding(16.dp), verticalArrangement = Arrangement.spacedBy(6.dp)) {
                    Text("LATEST COMPUTED PUNCH", style = MaterialTheme.typography.titleMedium)
                    ValueRow("Punch ID", d.lastPunchId)
                    ValueRow("Occurrences", "${d.computedCount}")
                    Detail("Punch payload", d.latestPunchJson)
                }
            }
        }

        Detail("Latest raw packet JSON", d.latestRawJson)
    }
}
