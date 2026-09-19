@file:OptIn(kotlin.uuid.ExperimentalUuidApi::class, kotlin.time.ExperimentalTime::class)
package com.digitaldojo.sdkinspector

import android.Manifest
import android.app.Application
import android.bluetooth.BluetoothManager
import android.content.Context
import android.content.pm.PackageManager
import android.location.LocationManager
import android.os.Build
import android.os.SystemClock
import com.boxreha.dynamics.Sdk0256Compat
import com.boxreha.dynamics.SdkDeviceOperations
import com.riseworld.dynamics.composite.ble.Glove
import com.riseworld.dynamics.composite.ble.isOnline
import com.riseworld.dynamics.composite.ble.isConnecting
import com.riseworld.dynamics.composite.ble.isBonded
import com.riseworld.dynamics.composite.ble.isNotBonded
import com.riseworld.dynamics.composite.ble.isOfflineError
import com.riseworld.dynamics.composite.ble.isOfflineOutOfRange
import com.riseworld.dynamics.composite.ble.isBatteryLow
import com.riseworld.dynamics.composite.ble.isCharging
import com.riseworld.dynamics.composite.ble.isChargerAttached
import com.riseworld.dynamics.composite.ble.isBaroAttached
import com.riseworld.dynamics.models.PeripheralDto
import com.riseworld.dynamics.models.Side
import com.riseworld.dynamics.models.ble.data.SensorDataPacket
import com.riseworld.dynamics.models.ble.data.Vector3d
import com.riseworld.dynamics.models.ble.nearby.NearbyGlove
import com.riseworld.dynamics.models.domain.profile.body.Gender
import com.riseworld.dynamics.models.domain.punch.Power
import com.riseworld.dynamics.models.domain.punch.Punch
import com.riseworld.dynamics.models.domain.session.TrainingSessionSensorType
import com.riseworld.dynamics.multiplatform.di.*
import com.riseworld.dynamics.multiplatform.settings.DynamicsSettings
import com.riseworld.launchpad.ble.multiplex.models.domain.ScannerState
import com.russhwolf.settings.SharedPreferencesSettings
import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.sync.Mutex
import kotlinx.coroutines.sync.withLock
import org.json.JSONArray
import org.json.JSONObject
import java.time.Instant
import kotlin.time.DurationUnit
import kotlin.uuid.Uuid

data class DeviceState(
    val id: String,
    val name: String,
    val address: String = "",
    val family: String = "UNKNOWN",
    val side: String = "UNKNOWN",
    val saved: Boolean = true,
    val isOnline: Boolean = false,
    val isConnecting: Boolean = false,
    val bondState: String = "UNKNOWN",
    val connectionStateString: String = "SAVED",
    val rawSubscriptionState: String = "OFF",
    val rawCount: Long = 0,
    val rawPacketsPerSecond: Double = 0.0,
    val lastRawReceivedMonotonicMs: Long = 0,
    val lastRawElapsedRealtimeNanos: Long = 0,
    val latestBleCounter: Int = 0,
    val latestRelativeTimeCounter: String = "",
    val operationalState: String = "UNKNOWN",
    val isCharging: Boolean = false,
    val isChargerAttached: Boolean = false,
    val isBaroAttached: Boolean = false,
    val rawRoute: String = "",
    val rawSubscribedAtMs: Long = 0,
    val lastRawFieldError: String = "",
    val lastRawError: String = "",
    val latestSamplingRate: String = "",
    val latestAcc: String = "",
    val latestGyro: String = "",
    val latestMag: String = "",
    val latestBaro: String = "",
    val latestRawJson: String = "",
    val computedCount: Long = 0,
    val lastPunchReceivedMonotonicMs: Long = 0,
    val lastPunchId: String = "",
    val latestPunchJson: String = "",
    val metadataJson: String = ""
) {
    val role: String get() = when {
        family == "ALPHA" && side == "LEFT" -> "LEFT HAND"
        family == "ALPHA" && side == "RIGHT" -> "RIGHT HAND"
        family == "DELTA" && side == "LEFT" -> "LEFT FOOT"
        family == "DELTA" && side == "RIGHT" -> "RIGHT FOOT"
        family == "ALPHA" -> "UNKNOWN_HAND"
        family == "DELTA" -> "UNKNOWN_FOOT"
        else -> "UNKNOWN"
    }
    fun json(): JSONObject = JSONObject()
        .put("peripheralId", id)
        .put("sdkName", name)
        .put("address", address)
        .put("family", family)
        .put("side", side)
        .put("role", role.replace(' ', '_'))
}

data class UiEvent(val type: String, val role: String, val text: String, val deviceId: String = "", val time: String = "", val summary: String = "")

data class InspectorState(
    val initialized: Boolean = false,
    val scanning: Boolean = false,
    val scannerStateString: String = "Inactive",
    val sdkState: String = "Not initialized",
    val bluetooth: String = "Unknown",
    val devices: List<DeviceState> = emptyList(),
    val nearby: List<Pair<String, String>> = emptyList(),
    val events: List<UiEvent> = emptyList(),
    val message: String = "",
    val sessions: List<String> = emptyList(),
    val permissions: Boolean = false,
    val scanBlocker: String = "Initialize SDK",
    val rawEnabled: Boolean = false,
    val busy: Boolean = false,
    val recording: RecordingStatus = RecordingStatus(),
    val activeSessionRunning: Boolean = false,
    val activeSessionStateString: String = "NO_SESSION",
    val acquisitionMode: String = "IDLE",
    val detectedFamily: String = "UNKNOWN",
    val familyConflict: Boolean = false
)

/** The single authoritative raw acquisition route (see startRaw). */
const val RAW_ROUTE = "SensorDataRepository.observeSensorData(peripheralId)"

private fun <T> sensorField(field: String, errors: JSONArray, get: () -> List<T>): List<T> = try {
    get()
} catch (e: Throwable) {
    if (e is CancellationException) throw e
    errors.put(JSONObject().put("field", field).put("error", e.toString()))
    emptyList()
}

private fun vectorArray(samples: List<*>, field: String, errors: JSONArray): JSONArray {
    val arr = JSONArray()
    for (v in samples) {
        try {
            arr.put(JSONObject().put("x", Sdk0256Compat.vecX(v)).put("y", Sdk0256Compat.vecY(v)).put("z", Sdk0256Compat.vecZ(v)))
        } catch (e: Throwable) {
            if (e is CancellationException) throw e
            errors.put(JSONObject().put("field", field).put("error", e.toString()).put("decodedSamples", arr.length()))
        }
    }
    return arr
}

/**
 * Every sample of every field is preserved. A field that is empty (the DELTA reports
 * isBaroAttached = false, so baroData is legitimately empty) or that fails to decode never
 * invalidates the packet: the remaining fields are recorded and the failure is reported in
 * "rawFieldErrors" so the caller can emit RAW_FIELD_ERROR.
 */
fun packetToJson(packet: SensorDataPacket): JSONObject {
    val fieldErrors = JSONArray()
    val accArray = vectorArray(sensorField("accData", fieldErrors) { packet.accData }, "accData", fieldErrors)
    val gyroArray = vectorArray(sensorField("gyroData", fieldErrors) { packet.gyroData }, "gyroData", fieldErrors)
    val magArray = vectorArray(sensorField("magnetoData", fieldErrors) { packet.magnetoData }, "magnetoData", fieldErrors)
    val baroArray = JSONArray()
    for (b in sensorField("baroData", fieldErrors) { packet.baroData }) baroArray.put(b)

    val rateJson = try {
        val rate = packet.samplingRate
        JSONObject().put("name", rate.name).put("imuFrequency", rate.imuFrequency).put("baroFrequency", rate.baroFrequency)
    } catch (e: Throwable) {
        if (e is CancellationException) throw e
        fieldErrors.put(JSONObject().put("field", "samplingRate").put("error", e.toString()))
        JSONObject()
    }

    var seconds = 0.0
    var nanos = 0L
    var packed = 0L
    try {
        seconds = Sdk0256Compat.packetSeconds(packet)
        nanos = Sdk0256Compat.packetRelativeNanos(packet)
        packed = Sdk0256Compat.packetRelativePacked(packet)
    } catch (e: Throwable) {
        if (e is CancellationException) throw e
        fieldErrors.put(JSONObject().put("field", "relativeTimeCounter").put("error", e.toString()))
    }

    val json = JSONObject()
        .put("bleCounter", packet.bleCounter)
        .put("relativeTimeCounterSeconds", seconds)
        .put("relativeTimeCounterNanos", nanos)
        .put("relativeTimeCounter", JSONObject().put("kotlinDurationPacked", packed).put("nanoseconds", nanos))
        .put("units", JSONObject().put("accData", "m/s\u00b2").put("gyroData", "degrees/second").put("magnetoData", "\u00b5T").put("baroData", "Pa"))
        .put("samplingRate", rateJson)
        .put("accData", accArray)
        .put("gyroData", gyroArray)
        .put("magnetoData", magArray)
        .put("baroData", baroArray)
    if (fieldErrors.length() > 0) json.put("rawFieldErrors", fieldErrors)
    return json
}

fun punchToJson(punch: Punch): JSONObject {
    val speed = punch.speed
    val speedJson = JSONObject()
        .put("peakAcceleration", speed.peakAcceleration)
        .put("peakVelocity", speed.peakVelocity)
        .put("displacement", speed.displacement)
        .put("punchDurationSeconds", Sdk0256Compat.punchSeconds(speed))
        .put("contactDurationSeconds", Sdk0256Compat.contactSeconds(speed))

    val family = Sdk0256Compat.family(punch.power)
    // powerIndex keeps its SDK name for DELTA. It is never relabelled force / impact force / Newton.
    val powerJson = JSONObject()
        .put("family", family)
        .put(if (family == "Delta") "powerIndex" else "impact", Sdk0256Compat.primary(punch.power))
        .put("impactOrPowerIndex", Sdk0256Compat.impactOrPowerIndex(punch.power))
        .put("peakForce", Sdk0256Compat.peakForce(punch.power))
    if (family == "Alpha") {
        powerJson.put("peakForceBasedOnBaro", Sdk0256Compat.baro(punch.power))
    }

    val punchId = Sdk0256Compat.punchId(punch)
    val devId = Sdk0256Compat.punchPeripheralUuid(punch).toString()

    return JSONObject()
        .put("id", punchId)
        .put("peripheralId", devId)
        .put("side", punch.side.name)
        .put("timestamp", punch.timestamp.toString())
        .put("areComputedValuesValid", punch.areComputedValuesValid)
        .put("speed", speedJson)
        .put("power", powerJson)
}

fun dtoToJson(dto: PeripheralDto): JSONObject = JSONObject()
    .put("id", Sdk0256Compat.deviceUuid(dto).toString())
    .put("name", dto.name)
    .put("address", dto.address)
    .put("side", dto.side.name)
    .put("bondState", dto.bondState.name)
    .put("isMock", dto.isMock)
    .put("firmwareVersion", dto.firmwareVersion)
    .put("hardwareVersion", dto.hardwareVersion)
    .put("modelNumber", dto.modelNumber)
    .put("manufacturerName", dto.manufacturerName)

fun gloveToJson(g: Glove): JSONObject = JSONObject()
    .put("id", Sdk0256Compat.deviceUuid(g.dto).toString())
    .put("name", g.data?.deviceName ?: g.dto.name)
    .put("address", g.address)
    .put("side", g.dto.side.name)
    .put("family", when (g.data?.sensorType) {
        TrainingSessionSensorType.ALPHA -> "ALPHA"
        TrainingSessionSensorType.DELTA -> "DELTA"
        else -> "UNKNOWN"
    })
    .put("isOnline", g.isOnline)
    .put("isConnecting", g.isConnecting)
    .put("isBonded", g.isBonded)
    .put("isNotBonded", g.isNotBonded)
    .put("isOfflineError", g.isOfflineError)
    .put("isOfflineOutOfRange", g.isOfflineOutOfRange)
    .put("isBatteryLow", g.isBatteryLow)
    .put("isCharging", g.isCharging)
    .put("isChargerAttached", g.isChargerAttached)
    .put("isBaroAttached", g.isBaroAttached)
    .put("operationalState", g.data?.operationalState?.toString() ?: "UNKNOWN")
    .put("dto", dtoToJson(g.dto))

class DynamicsSdkManager(val app: Application) {
    val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main.immediate)
    val recorder = SensorRecorder(app)
    val state = MutableStateFlow(InspectorState())
    private val commands = Mutex()
    private val eventGate = Mutex()
    private val devices = linkedMapOf<String, DeviceState>()
    private val dtos = linkedMapOf<String, PeripheralDto>()
    private val nearby = linkedMapOf<String, NearbyGlove>()
    private val recent = ArrayDeque<UiEvent>()
    private val jobs = linkedMapOf<String, Job>()
    private val rawJobs = linkedMapOf<String, Job>()
    private val packetReceipts = mutableMapOf<String, ArrayDeque<Long>>()
    private val seenPunchIds = hashSetOf<String>()
    private val runtimeIds = hashSetOf<String>()
    private val lastRawPreview = mutableMapOf<String, Long>()
    private var acquisitionMode = "IDLE"

    private var initialized = false
    private var scanning = false
    private var scannerStateString = "Inactive"
    private var sdkState = "Not initialized"
    private var message = ""
    private var sequence = 0L
    private var activeSessionRunning = false
    private var activeSessionStateString = "NO_SESSION"
    private val started = Instant.now().toString()
    private var settings: DynamicsSettings? = null
    private var recordingTimeoutExtended = false
    private var rawEnabled = false
    private var busy = false

    init {
        scope.launch {
            while (isActive) {
                delay(100)
                if (recordingTimeoutExtended && recorder.status.value.failure.isNotEmpty()) {
                    settings?.setBackgroundDisconnectTimeoutInSeconds(1)
                    recordingTimeoutExtended = false
                }
                state.value = InspectorState(
                    initialized = initialized,
                    scanning = scanning,
                    scannerStateString = scannerStateString,
                    sdkState = sdkState,
                    bluetooth = bluetooth(),
                    devices = devices.values.map { d ->
                        d.copy(rawPacketsPerSecond = packetReceipts[d.id]?.count { SystemClock.elapsedRealtime() - it <= 1000 }?.toDouble() ?: 0.0)
                    },
                    nearby = nearby.map { it.key to (it.value.advertisingName ?: "Dynamics") },
                    events = recent.toList(),
                    message = message,
                    sessions = recorder.sessions().map { it.name },
                    permissions = missingPermissions().isEmpty(),
                    scanBlocker = scanBlocker(),
                    rawEnabled = rawEnabled,
                    busy = busy,
                    recording = recorder.status.value,
                    activeSessionRunning = activeSessionRunning,
                    activeSessionStateString = activeSessionStateString,
                    acquisitionMode = acquisitionMode,
                    detectedFamily = detectedFamily(),
                    familyConflict = observedFamilies(true).size > 1
                )
            }
        }
        scope.launch { emit("APP_STARTED", payload = JSONObject().put("startedUtc", started)) }
    }

    /**
     * Families as the SDK itself reports them (TrainingSessionSensorType on the connected Glove).
     * Nothing is defaulted to ALPHA: a device whose family the SDK has not reported yet stays UNKNOWN.
     */
    fun observedFamilies(onlineOnly: Boolean): Set<String> =
        devices.values
            .filter { it.saved && (!onlineOnly || it.isOnline) }
            .map { it.family }
            .filter { it == "ALPHA" || it == "DELTA" }
            .toSet()

    /** Connected hardware wins; saved-but-offline is only used when nothing is connected. */
    fun detectedFamily(): String {
        val online = observedFamilies(true)
        if (online.size == 1) return online.first()
        if (online.size > 1) return "MIXED"
        val saved = observedFamilies(false)
        return when {
            saved.size == 1 -> saved.first()
            saved.size > 1 -> "MIXED"
            else -> "UNKNOWN"
        }
    }

    /** deleteGloveById and pairing are incompatible with a running computed session; finish it first. */
    private suspend fun finishIncompatibleSession(operation: String) {
        check(initialized) { "Initialize SDK first" }
        if (trainingSessionRepository.activeTrainingSessionTime.first() == null) return
        trainingSessionRepository.finishActiveTrainingSession().getOrThrow()
        withTimeout(5000) { trainingSessionRepository.activeTrainingSessionTime.first { it == null } }
        acquisitionMode = "IDLE"
        emit("SESSION_STATE", payload = JSONObject().put("phase", "FINISHED").put("operation", operation)
            .put("reason", "active computed session is incompatible with $operation"))
    }

    fun missingPermissions(): List<String> = (if (Build.VERSION.SDK_INT >= 31)
        listOf(Manifest.permission.BLUETOOTH_SCAN, Manifest.permission.BLUETOOTH_CONNECT)
    else listOf(Manifest.permission.ACCESS_FINE_LOCATION)).filter { app.checkSelfPermission(it) != PackageManager.PERMISSION_GRANTED }

    fun scanBlocker(): String = when {
        !app.packageManager.hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE) -> "Bluetooth LE not supported"
        missingPermissions().isNotEmpty() -> "Grant Bluetooth / location permissions"
        bluetooth() != "ON" -> "Enable Bluetooth"
        Build.VERSION.SDK_INT < 31 && !androidx.core.location.LocationManagerCompat.isLocationEnabled(app.getSystemService(LocationManager::class.java)) -> "Enable location services for BLE discovery"
        !initialized -> "Initialize SDK"
        else -> ""
    }

    fun bluetooth(): String = try {
        if (app.getSystemService(BluetoothManager::class.java)?.adapter?.isEnabled == true) "ON" else "OFF"
    } catch (e: SecurityException) { "Permission required" }

    fun command(name: String, block: suspend () -> Unit) {
        scope.launch {
            commands.withLock {
                emit("DEVICE_OPERATION", payload = JSONObject().put("operation", name).put("phase", "requested"))
                busy = true
                try {
                    withTimeout(90000) { block() }
                    emit("SDK", payload = JSONObject().put("operation", name).put("phase", "completed"))
                } catch (e: Throwable) {
                    if (e is CancellationException && e !is TimeoutCancellationException) throw e
                    error(name, e)
                } finally {
                    busy = false
                }
            }
        }
    }

    suspend fun error(name: String, e: Throwable) {
        val root = generateSequence(e) { it.cause }.last()
        message = "$name: ${root.javaClass.simpleName}: ${root.message}"
        android.util.Log.e("DynamicsInspector", message, e)
        val errObj = JSONObject()
            .put("operation", name)
            .put("exceptionClass", root.javaClass.name)
            .put("message", root.message)
            .put("stackTrace", root.stackTraceToString())
        emit("ERROR", payload = errObj)
    }

    suspend fun emit(type: String, id: String? = null, payload: Any? = null, sdkTimestamp: Any? = null, preview: Boolean = true,
                     flowEmissionSequence: Long? = null, packetIndexInEmission: Int? = null,
                     receivedNanos: Long = SystemClock.elapsedRealtimeNanos(), receivedUtc: String = Instant.now().toString()) {
        val utc = receivedUtc
        val nano = receivedNanos
        eventGate.withLock {
            val d = devices[id]
            val device = d?.json() ?: JSONObject().put("peripheralId", id ?: JSONObject.NULL).put("address", "").put("family", "UNKNOWN").put("side", "UNKNOWN").put("role", "UNKNOWN")
            val record = JSONObject()
                .put("schemaVersion", 2)
                .put("sequence", ++sequence)
                .put("eventType", type)
                .put("utcTimestamp", utc)
                .put("elapsedRealtimeNanos", nano)
                .put("device", device)
                .put("sdkTimestamp", sdkTimestamp ?: JSONObject.NULL)
                .put("payload", payload ?: JSONObject.NULL)
            if (flowEmissionSequence != null) record.put("flowEmissionSequence", flowEmissionSequence)
            if (packetIndexInEmission != null) record.put("packetIndexInEmission", packetIndexInEmission)
            val line = withContext(Dispatchers.Default) { record.toString() }
            try {
                recorder.append(line)
            } catch (e: Throwable) {
                message = "Recording failure: $e"
                if (e is CancellationException) throw e
            }
            if (!preview) return@withLock
            recent.addLast(
                UiEvent(
                    type = type,
                    role = d?.role ?: "UNKNOWN",
                    text = if (line.length > 8192) line.take(8192) + " … [UI preview truncated; full event in JSONL]" else line,
                    deviceId = id ?: "",
                    time = utc.substringAfter("T").take(12),
                    summary = when (type) {
                        "RAW_SENSOR" -> "Sensor packet (BLE counter: ${d?.latestBleCounter ?: 0})"
                        "COMPUTED_EVENT" -> "SDK Punch snapshot"
                        else -> payload.toString().take(90)
                    }
                )
            )
            while (recent.size > 1000) recent.removeFirst()
        }
    }

    fun watch(name: String, block: suspend () -> Unit) {
        jobs[name]?.cancel()
        jobs[name] = scope.launch {
            try { block() }
            catch (e: CancellationException) { throw e }
            catch (e: Throwable) { error(name, e) }
        }
    }

    fun initialize() = command("initialize") {
        if (!initialized) {
            Sdk0256Compat.verifyAbi()
            settings = DynamicsSettings(SharedPreferencesSettings(app.getSharedPreferences("sdk", Context.MODE_PRIVATE))).also {
                it.setDebuggingMode(false)
                it.setDummyImpactDataEnabled(false)
                it.setAcceptAllPunches(false)
                it.setKeepAllPunchDetails(true)
                it.setBackgroundDisconnectTimeoutInSeconds(1)
                initSdk(dynamicsSettings = it)
            }
            initialized = true
            sdkState = "Initialized / COMPATIBILITY"
        }
        observe()
    }

    private fun observe() {
        watch("saved") {
            gloveRepository.savedPeripherals.collect { saved ->
                emit("SAVED_DEVICES", payload = JSONArray().also { arr -> saved.forEach { arr.put(dtoToJson(it)) } })
                val currentIds = saved.map { Sdk0256Compat.deviceUuid(it).toString() }.toSet()
                for (id in dtos.keys.toList()) {
                    if (id !in currentIds) {
                        dtos.remove(id)
                        if (id in runtimeIds) devices[id]?.let { devices[id] = it.copy(saved = false, connectionStateString = "REMOVING / DISCONNECTING") }
                        else devices.remove(id)
                        rawJobs.remove(id)?.cancel()
                        packetReceipts.remove(id)
                    }
                }
                for (dto in saved) {
                    val id = Sdk0256Compat.deviceUuid(dto).toString()
                    dtos[id] = dto
                    val old = devices[id]
                    val updated = (old ?: DeviceState(
                        id = id,
                        name = dto.name,
                        address = dto.address,
                        side = dto.side.name,
                        saved = true,
                        bondState = dto.bondState.name
                    )).copy(
                        saved = true,
                        name = old?.name ?: dto.name,
                        connectionStateString = when {
                            old?.isOnline == true -> "CONNECTED"
                            old?.isConnecting == true -> "CONNECTING"
                            else -> "SAVED / OFFLINE"
                        },
                        address = dto.address,
                        side = dto.side.name,
                        bondState = dto.bondState.name,
                        metadataJson = dtoToJson(dto).toString()
                    )
                    devices[id] = updated
                    if (rawEnabled) startRaw(dto)
                }
            }
        }

        watch("devices") {
            gloveRepository.observeGloves().collect { list ->
                runtimeIds.clear()
                runtimeIds.addAll(list.map { Sdk0256Compat.deviceUuid(it.dto).toString() })
                for (id in devices.keys.toList()) {
                    if (id !in runtimeIds) {
                        if (id !in dtos) devices.remove(id)
                        else devices[id]?.let { devices[id] = it.copy(isOnline = false, isConnecting = false, connectionStateString = "SAVED / OFFLINE") }
                    }
                }
                for (g in list) {
                    val id = Sdk0256Compat.deviceUuid(g.dto).toString()
                    val old = devices[id] ?: DeviceState(
                        id = id,
                        name = g.dto.name,
                        address = g.dto.address,
                        side = g.dto.side.name,
                        saved = true
                    )
                    val family = when (g.data?.sensorType) {
                        TrainingSessionSensorType.ALPHA -> "ALPHA"
                        TrainingSessionSensorType.DELTA -> "DELTA"
                        else -> old.family
                    }
                    val connState = when {
                        g.isOnline -> "CONNECTED"
                        g.isConnecting -> "CONNECTING"
                        g.isOfflineError -> "OFFLINE (Error)"
                        g.isOfflineOutOfRange -> "OFFLINE (Out of range)"
                        else -> "SAVED / OFFLINE"
                    }
                    val bondStr = when {
                        g.isBonded -> "BONDED"
                        g.isNotBonded -> "NOT BONDED"
                        else -> g.dto.bondState.name
                    }
                    devices[id] = old.copy(
                        name = g.data?.deviceName ?: g.dto.name,
                        address = g.address,
                        family = family,
                        side = g.dto.side.name,
                        saved = id in dtos,
                        isOnline = g.isOnline,
                        isConnecting = g.isConnecting,
                        bondState = bondStr,
                        connectionStateString = if (id in dtos) connState else "REMOVING / DISCONNECTING",
                        operationalState = g.data?.operationalState?.toString() ?: "UNKNOWN",
                        isCharging = g.isCharging,
                        isChargerAttached = g.isChargerAttached,
                        isBaroAttached = g.isBaroAttached,
                        metadataJson = gloveToJson(g).toString()
                    )
                    emit("DEVICE_STATE", id, payload = gloveToJson(g))
                }
            }
        }

        watch("scanner") {
            pairingRepository.scannerState.collect { scanner ->
                scanning = Sdk0256Compat.scannerActive(scanner)
                val isError = Sdk0256Compat.scannerError(scanner)
                scannerStateString = when {
                    scanning -> "Active"
                    isError -> "Error: $scanner"
                    else -> "Inactive ($scanner)"
                }
                if (isError) {
                    message = "Scanner: $scannerStateString"
                }
                emit(if (isError) "ERROR" else "SCANNER_STATE", payload = JSONObject().put("scannerState", scannerStateString))
            }
        }

        watch("session") {
            trainingSessionRepository.activeTrainingSessionTime.collect { sessionTime ->
                activeSessionRunning = sessionTime != null
                activeSessionStateString = if (sessionTime == null) "NO_SESSION" else Sdk0256Compat.sessionState(sessionTime.state).uppercase()
                if (sessionTime == null && acquisitionMode == "COMPUTED") acquisitionMode = "IDLE"
                sdkState = if (sessionTime == null) "Ready / COMPATIBILITY" else "Session: $activeSessionStateString"
                emit("SESSION_STATE", payload = JSONObject().put("active", activeSessionRunning).put("state", activeSessionStateString))
            }
        }

        watch("computed") {
            trainingSessionRepository.activeTrainingSessionStats.collect { stats ->
                for (p in stats.punches) {
                    val punch = p as? Punch ?: continue
                    val punchId = Sdk0256Compat.punchId(punch)
                    val devId = Sdk0256Compat.punchPeripheralUuid(punch).toString()
                    val punchJson = punchToJson(punch)
                    val isNew = seenPunchIds.add(punchId)
                    if (isNew) {
                        devices[devId]?.let {
                            devices[devId] = it.copy(
                                computedCount = it.computedCount + 1,
                                lastPunchReceivedMonotonicMs = SystemClock.elapsedRealtime(),
                                lastPunchId = punchId,
                                latestPunchJson = punchJson.toString()
                            )
                        }
                        emit("COMPUTED_EVENT", devId, payload = punchJson, sdkTimestamp = punch.timestamp.toString())
                    }
                }
            }
        }

        watch("phone_barometer") {
            sensorDataRepository.observeSmartphoneBarometer().collect { baro ->
                emit("PHONE_BAROMETER", payload = JSONObject().put("barometerPascal", baro))
            }
        }

        watch("pairs") {
            gloveRepository.observeGlovePairs().collect { pairs ->
                emit("SDK_PAIRS", payload = JSONArray().also { arr ->
                    pairs.forEach { pair ->
                        arr.put(JSONObject().put("name", pair.name).put("id", pair.id.toString()))
                    }
                })
            }
        }
    }

    private fun startRaw(dto: PeripheralDto) {
        val id = Sdk0256Compat.deviceUuid(dto).toString()
        if (!rawEnabled || rawJobs[id]?.isActive == true) return
        devices[id] = devices[id]?.copy(rawSubscriptionState = "STARTING", lastRawError = "", lastRawFieldError = "", rawRoute = RAW_ROUTE) ?: return
        rawJobs[id] = scope.launch {
            try {
                var emission = 0L
                val subscribedAt = SystemClock.elapsedRealtime()
                devices[id]?.let { devices[id] = it.copy(rawSubscriptionState = "SUBSCRIBED", rawSubscribedAtMs = subscribedAt) }
                emit("RAW_STATE", id, JSONObject().put("state", "SUBSCRIBED").put("route", RAW_ROUTE))
                launch { noPacketDiagnostic(id, subscribedAt) }
                Sdk0256Compat.raw(sensorDataRepository, dto)
                    .catch { e ->
                        devices[id] = devices[id]?.copy(rawSubscriptionState = "ERROR", lastRawError = e.toString()) ?: return@catch
                        error("raw/$id", e)
                    }
                    .collect { packets ->
                        emission++
                        for ((packetIndex, packet) in packets.withIndex()) {
                            val receivedNanos = SystemClock.elapsedRealtimeNanos()
                            val receivedUtc = Instant.now().toString()
                            val packetJson = withContext(Dispatchers.Default) { packetToJson(packet) }
                            val fieldErrors = packetJson.optJSONArray("rawFieldErrors")
                            if (fieldErrors != null && fieldErrors.length() > 0) {
                                devices[id]?.let { devices[id] = it.copy(lastRawFieldError = fieldErrors.toString()) }
                                emit("RAW_FIELD_ERROR", id, JSONObject().put("bleCounter", packet.bleCounter).put("fields", fieldErrors))
                            }
                            val now = SystemClock.elapsedRealtime()
                            val previous = devices[id]
                            if (previous != null && previous.rawCount > 0 && packet.bleCounter.toLong() != previous.latestBleCounter.toLong() + 1) {
                                emit("COUNTER_DISCONTINUITY", id, JSONObject().put("previous", previous.latestBleCounter).put("current", packet.bleCounter)
                                    .put("interpretation", "Counter change only; SDK wrap/reset/loss semantics not assumed"))
                            }
                            if (previous?.rawSubscriptionState != "STREAMING") emit("RAW_STATE", id, JSONObject().put("state", "STREAMING"))
                            val receipts = packetReceipts.getOrPut(id) { ArrayDeque() }
                            receipts.addLast(now)
                            while (receipts.isNotEmpty() && now - receipts.first() > 1000) {
                                receipts.removeFirst()
                            }
                            val pps = receipts.size.toDouble()

                            val latestAccStr = packet.accData.lastOrNull()?.let { "x: ${Sdk0256Compat.vecX(it)}, y: ${Sdk0256Compat.vecY(it)}, z: ${Sdk0256Compat.vecZ(it)} m/s²" } ?: "None"
                            val latestGyroStr = packet.gyroData.lastOrNull()?.let { "x: ${Sdk0256Compat.vecX(it)}, y: ${Sdk0256Compat.vecY(it)}, z: ${Sdk0256Compat.vecZ(it)} deg/s" } ?: "None"
                            val latestMagStr = packet.magnetoData.lastOrNull()?.let { "x: ${Sdk0256Compat.vecX(it)}, y: ${Sdk0256Compat.vecY(it)}, z: ${Sdk0256Compat.vecZ(it)} µT" } ?: "None"
                            val latestBaroStr = packet.baroData.lastOrNull()?.let { "$it Pa" } ?: "None"
                            val samplingRateStr = "${packet.samplingRate.name} (IMU: ${packet.samplingRate.imuFrequency}Hz, Baro: ${packet.samplingRate.baroFrequency}Hz)"

                            devices[id]?.let { current ->
                                devices[id] = current.copy(
                                    rawCount = current.rawCount + 1,
                                    rawPacketsPerSecond = pps,
                                    lastRawReceivedMonotonicMs = now,
                                    lastRawElapsedRealtimeNanos = receivedNanos,
                                    latestBleCounter = packet.bleCounter,
                                    latestRelativeTimeCounter = Sdk0256Compat.packetSeconds(packet).toString() + " s",
                                    latestSamplingRate = samplingRateStr,
                                    latestAcc = latestAccStr,
                                    latestGyro = latestGyroStr,
                                    latestMag = latestMagStr,
                                    latestBaro = latestBaroStr,
                                    latestRawJson = packetJson.toString(),
                                    rawSubscriptionState = "STREAMING"
                                )
                            }
                            val preview = now - (lastRawPreview[id] ?: 0) >= 125
                            if (preview) lastRawPreview[id] = now
                            emit("RAW_SENSOR", id, payload = packetJson, sdkTimestamp = Sdk0256Compat.packetSeconds(packet).toString(),
                                preview = preview, flowEmissionSequence = emission, packetIndexInEmission = packetIndex,
                                receivedNanos = receivedNanos, receivedUtc = receivedUtc)
                        }
                    }
            } catch (e: CancellationException) {
                devices[id]?.let { devices[id] = it.copy(rawSubscriptionState = "OFF") }
                throw e
            } catch (e: Throwable) {
                devices[id]?.let { devices[id] = it.copy(rawSubscriptionState = "ERROR", lastRawError = e.toString()) }
                error("raw/$id", e)
            }
        }
    }

    /**
     * Subscribing to the raw Flow does not, on its own, put the firmware into a streaming operational
     * state. Verified against the shipped 0.25.6 bytecode: observeSensorData resolves to
     * GlovePeripheralImpl.getContinuousSensorData(), a plain MutableSharedFlow with no onStart and no
     * characteristic write, and no public SDK operation ever commands ALL_SENSORS_STREAM_STATE or
     * ACC_STREAM. Emitted at most once per subscription; it is never repeated while idle.
     */
    private suspend fun noPacketDiagnostic(id: String, subscribedAt: Long) {
        delay(2500)
        val d = devices[id] ?: return
        if (d.rawCount > 0 || d.rawSubscribedAtMs != subscribedAt) return
        devices[id] = d.copy(rawSubscriptionState = "SUBSCRIBED — NO PACKETS")
        emit("RAW_NO_PACKETS", id, JSONObject()
            .put("peripheralId", d.id)
            .put("family", d.family)
            .put("side", d.side)
            .put("role", d.role.replace(' ', '_'))
            .put("online", d.isOnline)
            .put("bonded", d.bondState)
            .put("operationalState", d.operationalState)
            .put("isCharging", d.isCharging)
            .put("isChargerAttached", d.isChargerAttached)
            .put("isBaroAttached", d.isBaroAttached)
            .put("rawRoute", d.rawRoute)
            .put("msSinceSubscription", SystemClock.elapsedRealtime() - subscribedAt)
            .put("chargerHint", if (d.isChargerAttached) "Sensor reports charger attached. Test off charger if raw streaming remains idle." else JSONObject.NULL)
            .put("sdkNote", "SDK 0.25.6 exposes no documented operation that requests ALL_SENSORS_STREAM_STATE; a Flow subscription alone does not start firmware streaming."))
    }

    fun scan() = command("scan") {
        check(scanBlocker().isEmpty()) { scanBlocker() }
        jobs.remove("scan")?.cancelAndJoin()
        nearby.clear()
        message = "Scanning for nearby sensors"
        watch("scan") {
            try {
                pairingRepository.nearbyGloves.collect { found ->
                    nearby.clear()
                    for (g in found) {
                        nearby[g.address.toString()] = g
                        emit("DISCOVERED", payload = JSONObject().put("address", g.address.toString()).put("name", g.advertisingName ?: "Dynamics"))
                    }
                }
            } finally {
                // scanning status updated reactively via scannerState flow
            }
        }
    }

    fun stopScan() = command("stop_scan") {
        jobs.remove("scan")?.cancelAndJoin()
        message = "Scan stopped"
    }

    fun pair(id: String, left: Boolean) = command("pair_${if (left) "LEFT" else "RIGHT"}") {
        requireNoSession()
        check(!rawEnabled) { "Stop RAW before pairing sensors" }
        check(scanBlocker().isEmpty()) { scanBlocker() }
        val g = nearby[id] ?: error("Discovery expired for $id")
        val side = if (left) Side.LEFT else Side.RIGHT
        val saved = gloveRepository.savedPeripherals.first()
        check(saved.size < 2) { "One same-family LEFT/RIGHT pair is supported. Remove a sensor first." }
        check(saved.none { it.side == side }) { "$side is occupied. Remove that sensor first." }
        val existingFamily = saved.firstOrNull()?.let { devices[Sdk0256Compat.deviceUuid(it).toString()]?.family }
        check(saved.isEmpty() || existingFamily in listOf("ALPHA", "DELTA")) { "Connect the saved sensor first so its family can be verified." }
        val result = pairingRepository.pair(g, g.advertisingName ?: "Dynamics", side)
        val pairedId = Sdk0256Compat.pairedUuid(result)
        emit("PAIR_RESULT", payload = JSONObject().put("status", "SDK_ACKNOWLEDGED").put("peripheralId", pairedId.toString()).put("side", side.name))
        jobs.remove("scan")?.cancelAndJoin()
        withTimeout(10000) {
            gloveRepository.savedPeripherals.first { list ->
                list.any { Sdk0256Compat.deviceUuid(it) == pairedId && it.side == side }
            }
        }
        val confirmed = withTimeout(15000) { gloveRepository.observeGloves().first { list -> list.any { Sdk0256Compat.deviceUuid(it.dto) == pairedId && it.dto.side == side && (saved.isEmpty() || it.data?.sensorType != null) } } }
        val paired = confirmed.first { Sdk0256Compat.deviceUuid(it.dto) == pairedId }
        if (existingFamily != null && paired.data?.sensorType?.name != existingFamily) {
            SdkDeviceOperations.remove(gloveRepository, paired.dto).getOrThrow()
            awaitRemoved(setOf(pairedId.toString()))
            error("Mixed ALPHA/DELTA pairs are unsupported; the new sensor was removed.")
        }
        nearby.clear()
        emit("PAIR_CONFIRMED", pairedId.toString(), JSONObject().put("side", side.name))
        message = "Saved by SDK ($side). Authoritative state updated."
    }

    private suspend fun requireNoSession() {
        check(initialized) { "Initialize SDK first" }
        check(trainingSessionRepository.activeTrainingSessionTime.first() == null) { "Existing active SDK session: use Finish active session first." }
    }

    private suspend fun awaitRemoved(ids: Set<String>) {
        try {
            withTimeout(10000) { gloveRepository.savedPeripherals.first { list -> list.none { Sdk0256Compat.deviceUuid(it).toString() in ids } } }
            withTimeout(10000) { gloveRepository.observeGloves().first { list -> list.none { Sdk0256Compat.deviceUuid(it.dto).toString() in ids } } }
        } catch (e: TimeoutCancellationException) {
            emit("SDK_STATE_INCONSISTENCY", payload = JSONObject().put("operation", "remove").put("ids", JSONArray(ids.toList())))
            throw IllegalStateException("SDK_STATE_INCONSISTENCY: removed sensors still present in SDK flows", e)
        }
    }

    /**
     * GloveRepository.deleteGloveById deletes the persisted glove and deinitializes the underlying BLE
     * communication. Order: stop the raw observer, finish an incompatible computed session, stop the
     * scan, delete, verify Resource.Success, then wait for absence from savedPeripherals and
     * observeGloves before claiming anything.
     */
    fun remove(id: String) = command("remove/$id") {
        check(initialized) { "Initialize SDK first" }
        val dto = dtos[id] ?: error("No saved peripheral with ID $id")
        val before = devices[id]
        val address = before?.address?.ifBlank { dto.address } ?: dto.address
        val bondBefore = before?.bondState ?: dto.bondState.name
        emit("REMOVE_STATE", id, JSONObject().put("phase", "REQUESTED")
            .put("saved", true)
            .put("runtime", id in runtimeIds)
            .put("bond", bondBefore))
        rawJobs.remove(id)?.cancelAndJoin()
        packetReceipts.remove(id)
        finishIncompatibleSession("remove")
        jobs.remove("scan")?.cancelAndJoin()
        nearby.clear()
        val result = SdkDeviceOperations.remove(gloveRepository, dto)
        result.getOrThrow()
        emit("REMOVE_STATE", id, JSONObject().put("phase", "DB_REMOVED"))
        awaitRemoved(setOf(id))
        emit("REMOVE_STATE", id, JSONObject().put("phase", "RUNTIME_REMOVED"))
        dtos.remove(id)
        devices.remove(id)
        emit("REMOVAL_CONFIRMED", id, payload = JSONObject()
            .put("status", "SDK REMOVE CONFIRMED")
            .put("peripheralId", id)
            .put("bondBefore", bondBefore))
        message = "SDK REMOVE CONFIRMED. Verifying rediscovery\u2026"
        verifyRediscovery(id, address, bondBefore)
    }

    /**
     * Uses the normal SDK scanner lifecycle only. A missing LED blink is not SDK state and is never
     * treated as evidence that the removal failed. Android Bluetooth pairing is not touched.
     */
    private suspend fun verifyRediscovery(id: String, address: String, bondBefore: String) {
        val blocker = scanBlocker()
        if (blocker.isNotEmpty() || address.isBlank()) {
            emit("REDISCOVERY_SKIPPED", id, JSONObject().put("reason", blocker.ifBlank { "No BLE address recorded for removed device" }))
            message = "SDK REMOVE CONFIRMED. Rediscovery scan skipped: ${blocker.ifBlank { "no BLE address" }}"
            return
        }
        val seen = withTimeoutOrNull(8000) {
            pairingRepository.nearbyGloves.first { found -> found.any { it.address.toString() == address } }
        } != null
        nearby.clear()
        val verdict = if (seen) "REMOVED + ADVERTISING" else "REMOVED FROM SDK \u2014 NOT CURRENTLY ADVERTISING"
        emit("REMOVE_STATE", id, JSONObject()
            .put("phase", if (seen) "REDISCOVERED" else "NOT_ADVERTISING")
            .put("verdict", verdict)
            .put("address", address)
            .put("savedPeripherals", "removed")
            .put("observeGloves", "removed")
            .put("bondBefore", bondBefore)
            .put("note", "LED behaviour is not authoritative SDK state and is not used as evidence."))
        if (bondBefore == "BONDED") {
            emit("BOND_STATE_AFTER_REMOVE", id, JSONObject()
                .put("bondBefore", bondBefore)
                .put("persistedAfter", false)
                .put("runtimeAfter", false)
                .put("note", "Hardware may remain OS-bonded while no longer persisted by the SDK; Android pairing settings are not modified."))
        }
        message = verdict
    }

    fun forgetAllSensors() = command("forget_all_sensors") {
        finishIncompatibleSession("forget_all_sensors")
        rawEnabled = false
        acquisitionMode = "IDLE"
        rawJobs.values.forEach { it.cancelAndJoin() }
        rawJobs.clear()
        packetReceipts.clear()
        jobs.remove("scan")?.cancelAndJoin()
        nearby.clear()
        val result = SdkDeviceOperations.deleteAll(gloveRepository)
        result.getOrThrow()
        try {
            withTimeout(10000) { gloveRepository.savedPeripherals.first { it.isEmpty() } }
            withTimeout(10000) { gloveRepository.observeGloves().first { it.isEmpty() } }
        } catch (e: TimeoutCancellationException) {
            emit("SDK_STATE_INCONSISTENCY", payload = JSONObject().put("operation", "forget_all"))
            throw IllegalStateException("SDK_STATE_INCONSISTENCY: sensors remain after deleteAllGloves", e)
        }
        dtos.clear()
        devices.clear()
        emit("FORGET_ALL_CONFIRMED", payload = JSONObject().put("status", "SDK REMOVE CONFIRMED (ALL DEVICES)"))
        message = "All sensors forgotten and BLE deinitialized by SDK."
    }

    fun swap(id: String) = command("swap/$id") {
        requireNoSession()
        check(!rawEnabled) { "Stop RAW before swapping sides" }
        jobs.remove("scan")?.cancelAndJoin()
        val dto = dtos[id] ?: error("No saved peripheral with ID $id")
        val oldSide = dto.side
        val expectedSide = if (oldSide == Side.LEFT) Side.RIGHT else Side.LEFT
        val result = SdkDeviceOperations.swap(gloveRepository, dto)
        result.getOrThrow()
        withTimeout(5000) { gloveRepository.savedPeripherals.first { list -> list.any { Sdk0256Compat.deviceUuid(it).toString() == id && it.side == expectedSide } } }
        withTimeout(5000) { gloveRepository.observeGloves().first { list -> list.any { Sdk0256Compat.deviceUuid(it.dto).toString() == id && it.dto.side == expectedSide } } }
        emit("SWAP_CONFIRMED", id, payload = JSONObject().put("status", "SIDE_SWAPPED").put("peripheralId", id).put("newSide", expectedSide.name))
        message = "SDK side swap confirmed; check both members of the pair."
    }

    fun setRawEnabled(enabled: Boolean) = command("raw_stream") {
        if (enabled) requireNoSession()
        acquisitionMode = if (enabled) "RAW" else "IDLE"
        rawEnabled = enabled
        if (rawEnabled) {
            dtos.values.forEach { startRaw(it) }
        } else {
            rawJobs.values.forEach { it.cancelAndJoin() }
            rawJobs.clear()
            devices.keys.forEach { devId ->
                devices[devId] = devices.getValue(devId).copy(rawSubscriptionState = "OFF")
            }
        }
        emit("RAW_OBSERVATION", payload = JSONObject().put("enabled", rawEnabled))
        message = "Raw observation: $rawEnabled"
    }

    /**
     * [requestedFamily] is only a UI hint. The family actually used is the TrainingSessionSensorType the
     * SDK reports for the connected devices, so DELTA-only hardware can never start an ALPHA session.
     */
    fun startComputed(requestedFamily: String, weight: String, height: String, gender: String) = command("computed_start") {
        check(initialized)
        check(!rawEnabled) { "Stop RAW before starting COMPUTED; simultaneous acquisition is unverified." }
        val online = devices.values.filter { it.saved && it.isOnline }
        check(online.isNotEmpty()) { "Connect at least one saved sensor before starting a computed session." }
        val unresolved = online.filter { it.family != "ALPHA" && it.family != "DELTA" }
        check(unresolved.isEmpty()) {
            "SDK has not reported a sensor family yet for ${unresolved.joinToString { it.name }}. Wait for the connection to settle."
        }
        val families = online.map { it.family }.toSet()
        check(families.size == 1) { "Mixed families are connected ($families). Only one family may be active." }
        val family = families.first()
        if (family != requestedFamily) {
            emit("FAMILY_RESOLVED", payload = JSONObject()
                .put("requested", requestedFamily)
                .put("resolved", family)
                .put("source", "TrainingSessionSensorType reported by the connected devices"))
        }
        check(trainingSessionRepository.activeTrainingSessionTime.first() == null) {
            "An active training session already exists. Finish or delete it before starting a new one."
        }
        val kg = weight.toDouble()
        val cm = height.toDouble()
        require(Sdk0256Compat.validBody(kg, cm)) { "Weight must be 20–250 kg, height 50–250 cm" }
        require(gender in listOf("MALE", "FEMALE")) { "Gender must be MALE or FEMALE" }
        val body = Sdk0256Compat.body(Uuid.random(), "Inspector", kg, cm, Gender.valueOf(gender))
        profileRepository.insertOrUpdateBodyProfile(body).getOrThrow()
        withTimeout(5000) { profileRepository.bodyProfile.first { it != null } }
        trainingSessionRepository.initializeActiveTrainingSession(false, Sdk0256Compat.freeSession()).getOrThrow()
        trainingSessionRepository.readyActiveTrainingSession(TrainingSessionSensorType.valueOf(family)).getOrThrow()
        trainingSessionRepository.toggleActiveTrainingSessionState().getOrThrow()
        withTimeout(10000) { trainingSessionRepository.activeTrainingSessionTime.first { it != null && Sdk0256Compat.sessionState(it.state) == "Resumed" } }
        acquisitionMode = "COMPUTED"
        message = "Computed training session started for $family (resolved from connected hardware)."
    }

    fun finishComputed() = command("computed_finish") {
        trainingSessionRepository.finishActiveTrainingSession().getOrThrow()
        withTimeout(5000) { trainingSessionRepository.activeTrainingSessionTime.first { it == null } }
        message = "Computed session finished."
    }

    fun deleteComputed() = command("computed_delete") {
        trainingSessionRepository.deleteActiveTrainingSession().getOrThrow()
        withTimeout(5000) { trainingSessionRepository.activeTrainingSessionTime.first { it == null } }
        message = "Computed session discarded/deleted."
    }

    fun snapshot(): Any = JSONArray().also { a ->
        devices.values.forEach {
            a.put(
                JSONObject()
                    .put("identity", it.json())
                    .put("sdkMetadata", JSONObject(it.metadataJson.ifBlank { "{}" }))
                    .put("latestRawPacket", JSONObject(it.latestRawJson.ifBlank { "{}" }))
                    .put("observedRawCount", it.rawCount)
                    .put("observedComputedOccurrences", it.computedCount)
            )
        }
    }

    suspend fun beginRecording() {
        devices.keys.toList().forEach { id -> devices[id] = devices.getValue(id).copy(rawCount = 0, computedCount = 0) }
        recorder.start(snapshot(), acquisitionMode)
        settings?.setBackgroundDisconnectTimeoutInSeconds(86400)
        recordingTimeoutExtended = true
        emit(
            "RECORDING_STARTED",
            payload = JSONObject()
                .put("applicationStartedUtc", started)
                .put("sdkInitialized", initialized)
                .put("bluetooth", bluetooth())
                .put("devices", snapshot())
                .put("acquisitionMode", acquisitionMode)
        )
    }

    suspend fun endRecording() {
        try {
            emit("RECORDING_STOPPED")
            recorder.stop(snapshot(), acquisitionMode)
        } finally { settings?.setBackgroundDisconnectTimeoutInSeconds(1); recordingTimeoutExtended = false }
    }

    fun marker(label: String, id: String?, text: String = "") {
        val nanos = SystemClock.elapsedRealtimeNanos()
        val utc = Instant.now().toString()
        command("annotation") {
            check(recorder.status.value.recording) { "Start recording before adding annotations" }
            emit("ANNOTATION", id, JSONObject().put("label", label).put("text", text), receivedNanos = nanos, receivedUtc = utc)
        }
    }
}

