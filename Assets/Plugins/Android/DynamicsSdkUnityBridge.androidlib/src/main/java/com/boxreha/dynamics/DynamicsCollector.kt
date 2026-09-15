@file:OptIn(kotlin.uuid.ExperimentalUuidApi::class, kotlin.time.ExperimentalTime::class)
@file:Suppress("DEPRECATION")
package com.boxreha.dynamics

import android.Manifest
import android.app.Activity
import android.app.Application
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.os.SystemClock
import com.unity3d.player.UnityPlayer
import com.russhwolf.settings.SharedPreferencesSettings
import com.riseworld.dynamics.multiplatform.di.*
import com.riseworld.dynamics.multiplatform.settings.DynamicsSettings
import com.riseworld.dynamics.composite.ble.Glove
import com.riseworld.dynamics.composite.ble.BleGloveState
import com.riseworld.dynamics.models.ble.nearby.NearbyGlove
import com.riseworld.dynamics.models.PeripheralDto
import com.riseworld.dynamics.models.Side
import com.riseworld.dynamics.models.domain.profile.body.*
import com.riseworld.dynamics.models.domain.punch.Power
import com.riseworld.dynamics.models.domain.punch.Punch
import com.riseworld.dynamics.models.domain.session.*
import com.riseworld.dynamics.models.domain.unit.Centimeter
import com.riseworld.dynamics.models.domain.unit.Kilogram
import com.riseworld.launchpad.ble.multiplex.models.domain.ScannerState
import com.riseworld.launchpad.ble.multiplex.models.exception.ScannerError
import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.sync.Mutex
import kotlinx.coroutines.sync.withLock
import org.json.JSONArray
import org.json.JSONObject
import java.util.UUID
import kotlin.time.DurationUnit
import kotlin.uuid.Uuid

/** Android-only SDK owner. Main-dispatcher state; serialized commands; fail-closed gameplay gate. */
internal object DynamicsCollector {
    private val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main.immediate)
    private val commands = Mutex()
    private val policy = CollectorPolicy()
    private var initialized = false
    private var observing = false
    private var foreground = true
    private var profileReady = false
    private var profileReference = ""
    private var participant = ""
    private var ownedSession = false
    private var emissionEnabled = false
    private var sessionFamily = ""
    private var sessionState = "idle"
    private var controlRequestId = ""
    private var statusSequence = 0L
    private var state = "uninitialized"
    private var lastStatusCode = "uninitialized"
    private var lastStatusMessage = "SDK nicht initialisiert."
    private var settings: DynamicsSettings? = null
    private var mockSettings = false
    private var deviceRecoveryPending = false
    private var lastHeartbeat = Double.NaN
    private var scanJob: Job? = null
    private val observers = ArrayList<Job>()
    private var gloves: List<Glove> = emptyList()
    private val nearby = linkedMapOf<String, NearbyGlove>()
    private val epochs = hashMapOf<String, Epoch>()
    private val retiredDeviceEpochs = hashMapOf<String, Epoch>()
    private val sequences = hashMapOf<String, Long>()
    private data class Epoch(val id: String, val family: String, val side: String, val provenance: String)
    private val activity: Activity get() = UnityPlayer.currentActivity

    private fun command(code: String, requireInit: Boolean = true, block: suspend () -> Unit) {
        scope.launch {
            commands.withLock {
                try {
                    if (requireInit && !initialized) fail("not_initialized", "SDK zuerst initialisieren.")
                    withTimeout(if (code == "pair") 90_000L else 20_000L) { block() }
                } catch (e: TimeoutCancellationException) {
                    emissionEnabled = false
                    policy.disarm()
                    sessionState = "error"
                    status("error", code + "_timeout", "SDK-Aufruf ohne rechtzeitige Bestätigung. Sitzung prüfen und gegebenenfalls beenden.")
                } catch (e: CancellationException) { throw e
                } catch (e: CollectorFailure) {
                    emissionEnabled = false
                    policy.disarm()
                    status("error", e.code, e.message ?: e.code)
                } catch (e: Throwable) {
                    if (e !is Exception && e !is LinkageError) throw e
                    emissionEnabled = false
                    policy.disarm()
                    status("error", code + "_failed", "SDK-Aufruf fehlgeschlagen: " + e.javaClass.simpleName)
                }
            }
        }
    }
    private class CollectorFailure(val code: String, message: String) : Exception(message)
    private fun fail(code: String, message: String): Nothing = throw CollectorFailure(code, message)

    @JvmStatic fun initialize() = command("initialize", false) {
        if (!initialized) {
            val preferences = activity.getSharedPreferences("dynamics_sdk_settings", Context.MODE_PRIVATE)
            settings = DynamicsSettings(SharedPreferencesSettings(preferences)).also {
                it.setDebuggingMode(false)
                it.setDummyImpactDataEnabled(false)
                it.setAcceptAllPunches(false)
                it.setKeepAllPunchDetails(true)
                it.setBackgroundDisconnectTimeoutInSeconds(1)
                Sdk0256Compat.verifyAbi()
                initSdk(dynamicsSettings = it)
            }
            activity.application.registerActivityLifecycleCallbacks(lifecycle)
            initialized = true
        }
        foreground = true
        observe()
        if (!observing) return@command
        if (!ownedSession && trainingSessionRepository.activeTrainingSessionTime.first() != null) {
            pauseInternal()
            status("ready", "existing_session", "Vorhandene SDK-Sitzung wurde pausiert. Vor einem neuen Start ausdrücklich beenden; Daten bleiben erhalten.")
            return@command
        }
        if (ownedSession && !emissionEnabled) pauseInternal()
        if (missingPermissions().isNotEmpty()) status("permissions_required", "permissions_required", "Bluetooth-Berechtigungen freigeben.")
        else status("ready", "initialized", "Dynamics SDK 0.25.6 initialisiert. Körperprofil und Geräte prüfen.")
    }

    @JvmStatic fun missingPermissions(): Array<String> {
        val required = if (Build.VERSION.SDK_INT >= 31)
            arrayOf(Manifest.permission.BLUETOOTH_SCAN, Manifest.permission.BLUETOOTH_CONNECT)
        else arrayOf(Manifest.permission.ACCESS_FINE_LOCATION)
        return required.filter { activity.checkSelfPermission(it) != PackageManager.PERMISSION_GRANTED }.toTypedArray()
    }

    @JvmStatic fun requestPermissions() = command("permissions", false) {
        if (missingPermissions().isEmpty()) { permissionsChanged(); return@command }
        status("permissions_required", "permissions_requested", "Android-Bluetooth-Berechtigungen werden angefragt.")
        if (activity.fragmentManager.findFragmentByTag("dynamics_permissions") == null)
            activity.fragmentManager.beginTransaction().add(DynamicsPermissionFragment(), "dynamics_permissions").commit()
    }
    @JvmStatic fun permissionsChanged(permanentlyDenied: Boolean = false) {
        scope.launch {
            if (missingPermissions().isEmpty()) status(if (initialized) "ready" else "uninitialized", "permissions_granted", "Berechtigungen erteilt. Gerätesuche starten.")
            else if (permanentlyDenied) status("permissions_required", "permissions_permanently_denied", "Bluetooth-Berechtigungen sind gesperrt. App-Einstellungen öffnen und Geräte in der Nähe freigeben.")
            else status("permissions_required", "permissions_denied", "Bluetooth-Berechtigungen wurden nicht erteilt. Erneut anfragen oder App-Einstellungen öffnen.")
        }
    }

    @JvmStatic fun selectParticipant(studyId: String) = command("participant", false) {
        if (studyId == participant) { status(state, "participant_unchanged", "Aktuelles Studienprofil unverändert."); return@command }
        if (initialized && trainingSessionRepository.activeTrainingSessionTime.first() != null)
            fail("finish_before_participant_change", "SDK-Sitzung vor einem Teilnehmerwechsel beenden.")
        participant = studyId.trim()
        profileReady = false
        profileReference = ""
        status(if (initialized) "ready" else "uninitialized", "profile_required", "SDK-Körperprofil für dieses Studienprofil bestätigen.")
    }

    @JvmStatic fun startScan() = command("scan") {
        requireForeground()
        if (missingPermissions().isNotEmpty()) fail("permissions_required", "Bluetooth-Berechtigungen fehlen.")
        if (scanJob?.isActive == true) { status("scanning", "scan_active", "Gerätesuche läuft."); return@command }
        nearby.clear()
        scanJob = watch("scan") {
            pairingRepository.nearbyGloves.collect { found ->
                val previous = nearby.entries.associate { it.value.address to it.key }
                nearby.clear()
                found.forEach { glove -> nearby[previous[glove.address] ?: UUID.randomUUID().toString()] = glove }
                status("scanning", "scan_results", "Gefundene Geräte einzeln auswählen und Körperseite zuordnen.")
            }
        }
        scanJob!!.start()
        if (scanJob?.isActive != true) return@command
        status("scanning", "scan_started", "Gerätesuche gestartet.")
    }
    private fun stopScanning() { scanJob?.cancel(); scanJob = null; nearby.clear() }
    @JvmStatic fun stopScan() = command("stop_scan") { stopScanning(); status("ready", "scan_stopped", "Gerätesuche beendet.") }

    @JvmStatic fun pair(nearbyId: String, side: String) = command("pair") {
        requireForeground()
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null) fail("finish_before_pairing", "SDK-Sitzung vor Änderungen an Geräten beenden.")
        val selectedSide = parseSide(side)
        val saved = gloveRepository.savedPeripherals.first()
        if (saved.size >= 2) fail("device_limit_two", "Dieser SDK-Collector unterstützt maximal ein Paar. Ein dritter Sensor ist nicht freigegeben.")
        if (saved.any { it.side == selectedSide }) fail("side_already_assigned", "Diese Körperseite ist bereits belegt. Gerät zuerst entfernen.")
        val glove = nearby[nearbyId] ?: fail("scan_selection_expired", "Gerät erneut suchen und auswählen.")
        status("pairing", "pairing", "Gerät wird gekoppelt; SDK-Bestätigung abwarten.")
        if (pairingRepository.pair(glove, glove.advertisingName ?: "Dynamics", selectedSide).getOrNull() == null)
            fail("pair_failed", "SDK-Pairing fehlgeschlagen. Bluetooth, Entfernung und andere Verbindungen prüfen.")
        stopScanning()
        status("ready", "paired", "Gerät gespeichert. Identität und Sensorfamilie werden nach Verbindungsaufbau geprüft.")
    }

    @JvmStatic fun unpair(deviceId: String) = command("unpair") {
        requireForeground()
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null) fail("finish_before_unpair", "Zuerst End SDK session wählen, dann Gerät entfernen. Sitzung bleibt erhalten.")
        val saved = gloveRepository.savedPeripherals.first()
        val dto = saved.firstOrNull { alias(it) == deviceId } ?: fail("device_not_found", "Gespeichertes Gerät nicht gefunden. Neu initialisieren und aktualisieren.")
        val removedEpoch = epochs[deviceId] ?: retiredDeviceEpochs[deviceId]
        status("removing", "removing", "Gespeicherte Kopplung wird entfernt; SDK-Bestätigung abwarten.")
        gloveRepository.deleteGloveById(Sdk0256Compat.peripheralId(dto)).getOrThrow()
        // SDK deletion owns persistent DB removal and BLE deinitialization. Await both published views.
        withTimeout(5000) { gloveRepository.savedPeripherals.first { list -> list.none { Sdk0256Compat.deviceUuid(it) == Sdk0256Compat.deviceUuid(dto) } } }
        val current = withTimeout(5000) { gloveRepository.observeGloves().first { list -> list.none { Sdk0256Compat.deviceUuid(it.dto) == Sdk0256Compat.deviceUuid(dto) } } }
        gloves.filter { alias(it) == deviceId }.forEach(::retire)
        gloves = current
        epochs.remove(deviceId)?.let { DynamicsUnityBridge.sendDeviceState(identity(deviceId, it).put("status", "offline").toString()) }
        removedEpoch?.let { DynamicsUnityBridge.sendDeviceState(identity(deviceId, it).put("status", "removed").toString()) }
        retiredDeviceEpochs.remove(deviceId)
        sequences.remove(deviceId)
        knownFamilies.remove(deviceId)
        stopScanning()
        reconcileConnections()
        status("ready", "unpaired", "Gerät dauerhaft entfernt. Seite ist frei; erneut suchen und zuordnen.")
    }

    @JvmStatic fun changeSide(deviceId: String) = command("change_side") {
        requireForeground()
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null) fail("finish_before_side_change", "SDK-Sitzung vor Seitenwechsel beenden.")
        val dto = gloveRepository.savedPeripherals.first().firstOrNull { alias(it) == deviceId }
            ?: fail("device_not_found", "Gespeichertes Gerät nicht gefunden.")
        val expected = if (dto.side == Side.LEFT) Side.RIGHT else Side.LEFT
        status("changing_side", "changing_side", "Seitenwechsel wird gespeichert.")
        gloveRepository.swapGloveSideForId(Sdk0256Compat.peripheralId(dto)).getOrThrow()
        gloves.forEach(::retire)
        gloves = withTimeout(5000) { gloveRepository.observeGloves().first { list -> list.any { Sdk0256Compat.deviceUuid(it.dto) == Sdk0256Compat.deviceUuid(dto) && it.dto.side == expected } } }
        reconcileConnections()
        status("ready", "side_changed", "Seite geändert; bei zwei Handschuhen wurden Links und Rechts getauscht. Zuordnung prüfen.")
    }

    @JvmStatic fun setBodyProfile(studyId: String, weightKg: Double, heightCm: Double, gender: String) = command("body_profile") {
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null) fail("finish_before_profile_change", "SDK-Sitzung vor Profiländerungen beenden.")
        profileReady = false
        profileReference = ""
        if (studyId != participant || !Sdk0256Compat.validName(participant))
            fail("participant_mismatch", "Aktuelles pseudonymes Studienprofil fehlt oder stimmt nicht überein.")
        if (!weightKg.isFinite() || !heightCm.isFinite() || !Sdk0256Compat.validBody(weightKg, heightCm))
            fail("invalid_body_profile", "SDK-Bereiche: Gewicht 20–250 kg, Körpergröße 50–250 cm.")
        val parsedGender = when (gender) { "MALE" -> Gender.MALE; "FEMALE" -> Gender.FEMALE
            else -> fail("invalid_gender", "SDK 0.25.6 unterstützt MALE oder FEMALE. Keine automatische Zuordnung.") }
        val previous = profileRepository.getBodyProfile().getOrNull() as? BodyProfile
        val id = previous?.takeIf { it.name == participant }?.let { Sdk0256Compat.profileId(it) } ?: Uuid.random()
        val body = Sdk0256Compat.body(id, participant, weightKg, heightCm, parsedGender)
        if (profileRepository.insertOrUpdateBodyProfile(body).getOrNull() == null) fail("body_profile_rejected", "SDK hat das Körperprofil abgelehnt.")
        profileReady = true
        profileReference = id.toString()
        status("ready", "profile_ready", "SDK-Körperprofil lokal gespeichert. Keine Kraftnormalisierung im Spiel.")
    }

    @JvmStatic fun startSession(family: String) = startSession(family, UUID.randomUUID().toString())
    @JvmStatic fun startSession(family: String, requestId: String) = command("start_session") {
        if (requestId.isBlank() || requestId.length > 128) fail("invalid_request_id", "Sitzungsanforderung hat keine gültige ID.")
        requireForeground()
        validateSessionPrerequisites(family)
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null) fail("existing_session", "Vorhandene SDK-Sitzung zuerst ausdrücklich beenden.")
        stopScanning()
        sessionState = "starting"
        status("ready", "session_starting", "SDK-Sitzung wird vorbereitet.")
        if (trainingSessionRepository.initializeActiveTrainingSession(false, Sdk0256Compat.freeSession()).getOrNull() == null)
            fail("session_initialize_failed", "SDK-Sitzung konnte nicht initialisiert werden.")
        ownedSession = true
        policy.resetForNewSession()
        sessionFamily = family
        if (trainingSessionRepository.readyActiveTrainingSession(parseFamily(family)).getOrNull() == null) {
            sessionState = "error"
            fail("session_ready_failed", "SDK-Voraussetzungen nicht erfüllt. Geräte, Familien und Körperprofil prüfen; Sitzung dann beenden.")
        }
        resumeInternal(requestId)
    }

    @JvmStatic fun pauseSession() = command("pause_session") { pauseInternal(); status("ready", "session_paused", "SDK-Sitzung pausiert.") }
    @JvmStatic fun resumeSession() = resumeSession(UUID.randomUUID().toString())
    @JvmStatic fun resumeSession(requestId: String) = command("resume_session") {
        if (requestId.isBlank() || requestId.length > 128) fail("invalid_request_id", "Sitzungsanforderung hat keine gültige ID.")
        resumeInternal(requestId)
    }

    private suspend fun resumeInternal(requestId: String) {
        requireForeground()
        if (!ownedSession) fail("session_not_owned", "Nur eine in dieser App-Ausführung gestartete Sitzung kann fortgesetzt werden.")
        if (policy.isSaturated) fail("identity_capacity_reached", "Ereignis-ID-Kapazität erreicht. SDK-Sitzung beenden und neu starten.")
        validateSessionPrerequisites(sessionFamily)
        val active = trainingSessionRepository.activeTrainingSessionTime.first() ?: fail("no_session", "Keine aktive SDK-Sitzung.")
        // Never replay the SDK's rolling snapshot after a pause/reconnection/start.
        emissionEnabled = false
        if (Sdk0256Compat.sessionState(active.state) != "Resumed") {
            if (Sdk0256Compat.sessionState(active.state) != "Paused" && Sdk0256Compat.sessionState(active.state) != "Ready")
                fail("session_not_ready", "SDK-Sitzung ist noch nicht bereit.")
            if (trainingSessionRepository.toggleActiveTrainingSessionState().getOrNull() == null) fail("resume_failed", "SDK-Sitzung konnte nicht fortgesetzt werden.")
        }
        val confirmed = withTimeout(5000) { trainingSessionRepository.activeTrainingSessionTime.first { Sdk0256Compat.sessionState(it?.state) == "Resumed" } }
        if (confirmed == null) fail("resume_unconfirmed", "SDK hat den Sitzungsstart nicht bestätigt.")
        requireForeground()
        validateSessionPrerequisites(sessionFamily)
        policy.arm(wallSeconds(), monotonicSeconds())
        emissionEnabled = true
        sessionState = "running"
        controlRequestId = requestId
        reconcileConnections()
        status("ready", "session_running", "SDK-Sitzung läuft. Nur frische gültige SDK-Ereignisse werden weitergegeben.")
    }
    private suspend fun pauseInternal() {
        emissionEnabled = false
        policy.disarm()
        val active = trainingSessionRepository.activeTrainingSessionTime.first()
        if (Sdk0256Compat.sessionState(active?.state) == "Resumed") {
            if (trainingSessionRepository.toggleActiveTrainingSessionState().getOrNull() == null) fail("pause_failed", "SDK-Pause fehlgeschlagen; Spieleingaben bleiben gesperrt.")
        }
        sessionState = if (active == null) "idle" else "paused"
    }
    @JvmStatic fun finishSession() = command("finish_session") {
        emissionEnabled = false
        policy.disarm()
        if (trainingSessionRepository.activeTrainingSessionTime.first() != null &&
            trainingSessionRepository.finishActiveTrainingSession().getOrNull() == null)
            fail("finish_failed", "SDK-Sitzung konnte nicht beendet werden.")
        ownedSession = false
        deviceRecoveryPending = false
        sessionFamily = ""
        sessionState = "finished"
        status("ready", "session_finished", "SDK-Sitzung beendet und lokal aufbewahrt. Keine Sitzungsdaten gelöscht.")
    }

    private suspend fun validateSessionPrerequisites(family: String) {
        if (!profileReady || participant.isBlank() || (profileRepository.getBodyProfile().getOrNull() as? BodyProfile)?.name != participant)
            fail("profile_required", "SDK-Körperprofil für das aktuelle Studienprofil bestätigen.")
        if (missingPermissions().isNotEmpty()) fail("permissions_required", "Bluetooth-Berechtigungen fehlen.")
        if (mockSettings || settings!!.isDummyImpactDataEnabled().first() || settings!!.isBatteryMockEnabled().first() || settings!!.acceptAllPunches().first())
            fail("mock_settings_rejected", "Dummy-, Mock- oder gelockerte SDK-Messoptionen sind nicht für physische Messungen freigegeben.")
        val current = gloveRepository.observeGloves().first()
        if (current.any { it.dto.isMock }) fail("mock_device_rejected", "SDK-Mock-Geräte sind nicht als physische Sensoren zugelassen.")
        val error = CollectorPolicy.familyError(current.map(::familyOf), current.map { sideOf(it.dto.side) }, current.map { Sdk0256Compat.online(it.bleGloveState) }, family)
        if (error != null) fail(error, "Geräte müssen online, eindeutig zugeordnet und vom gewählten selben Sensortyp sein. Maximal zwei Geräte; kein stiller Familienwechsel.")
        gloves = current
    }

    private fun observe() {
        if (observing) return
        observing = true
        observers += watch("devices") {
            gloveRepository.observeGloves().collect { current ->
                gloves.filter { old -> current.none { Sdk0256Compat.deviceUuid(it.dto) == Sdk0256Compat.deviceUuid(old.dto) } }.forEach(::retire)
                gloves = current
                reconcileConnections()
                if (emissionEnabled && (current.isEmpty() || current.any { !Sdk0256Compat.online(it.bleGloveState) || familyOf(it) != sessionFamily || it.dto.isMock })) {
                    emissionEnabled = false
                    deviceRecoveryPending = true
                    command("device_loss") { pauseInternal(); status("error", "device_changed", "Geräteverbindung oder Sensorfamilie geändert. Sitzung pausiert; explizit fortsetzen.") }
                } else status(state, "devices_changed", "Gerätestatus aktualisiert.")
            }
        }
        observers += watch("scanner_state") {
            pairingRepository.scannerState.collect { scanner ->
                if (Sdk0256Compat.scannerError(scanner)) {
                    val code = if (Sdk0256Compat.missingScanningRequirements(scanner)) "scanning_requirements_missing" else "scanner_error"
                    status("error", code, "Bluetooth, Berechtigungen und gegebenenfalls Android-Standortdienst prüfen.")
                }
            }
        }
        observers += watch("session_state") {
            trainingSessionRepository.activeTrainingSessionTime.collect { active ->
                // Command handlers await their own authoritative SDK state before acknowledging running.
                if (commands.isLocked) return@collect
                when (Sdk0256Compat.sessionState(active?.state)) {
                    "Resumed" -> if (!emissionEnabled) sessionState = "paused"
                    "Ready", "Paused" -> { emissionEnabled = false; sessionState = "paused" }
                    "Initializing" -> { emissionEnabled = false; sessionState = "starting" }
                    else -> { emissionEnabled = false; if (sessionState != "finished") sessionState = "idle" }
                }
                status(state, if (active != null && !ownedSession) "existing_session" else "session_state", if (active != null && !ownedSession) "Vorhandene SDK-Sitzung zuerst ausdrücklich beenden." else "SDK-Sitzungsstatus aktualisiert.")
            }
        }
        observers += watch("punches") {
            trainingSessionRepository.activeTrainingSessionStats.collect { snapshot -> snapshot.punches.forEach { value -> forwardPunch(value as? Punch ?: error("SDK punch list contains unsupported value")) } }
        }
        observers += watch("physical_settings") {
            combine(settings!!.isDummyImpactDataEnabled(), settings!!.isBatteryMockEnabled(), settings!!.acceptAllPunches()) { dummy, battery, accept -> dummy || battery || accept }.collect { invalid ->
                mockSettings = invalid
                if (invalid) {
                    emissionEnabled = false
                    command("physical_settings_changed") { pauseInternal(); status("error", "mock_settings_rejected", "SDK-Testoption aktiviert. Physische Messungen gesperrt.") }
                }
            }
        }
        observers += watch("heartbeat") { while (isActive) {
            delay(1000)
            if (foreground) {
                val now = monotonicSeconds()
                // A stalled Android main thread can outlive Unity's connection TTL.
                if (lastHeartbeat.isFinite() && now - lastHeartbeat > 5.0) gloves.forEach(::retire)
                lastHeartbeat = now
                reconcileConnections(heartbeat = true)
                if (deviceRecoveryPending && !commands.isLocked && ownedSession && profileReady && !mockSettings && sessionState == "paused"
                    && gloves.none { it.dto.isMock }
                    && CollectorPolicy.familyError(gloves.map(::familyOf), gloves.map { sideOf(it.dto.side) }, gloves.map { Sdk0256Compat.online(it.bleGloveState) }, sessionFamily) == null) {
                    deviceRecoveryPending = false
                    status("ready", "devices_restored", "Geräte wieder bereit. SDK-Sitzung ausdrücklich fortsetzen.")
                }
            }
            status(state, lastStatusCode, lastStatusMessage)
        } }
        // Register every lazy observer before any can fail synchronously on Main.immediate.
        observers.toList().forEach { it.start() }
    }

    private fun watch(code: String, block: suspend CoroutineScope.() -> Unit): Job = scope.launch(start = CoroutineStart.LAZY) {
        try { block() } catch (e: CancellationException) { throw e } catch (e: Throwable) {
                    if (e !is Exception && e !is LinkageError) throw e
            emissionEnabled = false
            policy.disarm()
            // An explicit initialize() can now restart all observers without duplicate subscriptions.
            observers.filter { it != currentCoroutineContext()[Job] }.forEach { it.cancel() }
            observers.clear()
            observing = false
            status("error", code + "_observer_failed", "SDK-Datenkanal unterbrochen: " + e.javaClass.simpleName + ". Collector neu initialisieren.")
        }
    }

    private fun forwardPunch(punch: Punch) {
        val eventId = Sdk0256Compat.punchId(punch)
        if (!policy.consume(eventId)) {
            if (policy.isSaturated && emissionEnabled) {
                emissionEnabled = false
                command("identity_capacity") { pauseInternal(); status("error", "identity_capacity_reached", "Native Ereignis-ID-Kapazität erreicht. SDK-Sitzung beenden und neu starten.") }
            }
            return
        }
        if (!emissionEnabled || !foreground || !ownedSession) return
        val glove = gloves.firstOrNull { Sdk0256Compat.belongsTo(punch, it.dto) } ?: return
        val device = alias(glove)
        val epoch = epochs[device] ?: return
        if (glove.dto.isMock || mockSettings || epoch.provenance != "dynamics_sdk" || !punch.areComputedValuesValid) return
        val powerValue = punch.power
        val family = Sdk0256Compat.family(powerValue)
        if (family != epoch.family || family != sessionFamily || sideOf(punch.side) != epoch.side) {
            emissionEnabled = false
            command("punch_identity") { pauseInternal(); status("error", "punch_identity_mismatch", "SDK-Ereignis passt nicht zur Gerätezuordnung oder Sitzungsfamilie.") }
            return
        }
        val timestamp = punch.timestamp.epochSeconds.toDouble() + punch.timestamp.nanosecondsOfSecond / 1_000_000_000.0
        val wallNow = wallSeconds()
        val emittedAt = monotonicSeconds()
        val sourceAge = policy.sourceAge(timestamp, wallNow, emittedAt)
        if (sourceAge == null) {
            if (!policy.isClockQualified) {
                emissionEnabled = false
                command("clock_changed") { pauseInternal(); status("ready", "clock_changed", "Android-Zeitbasis hat sich geändert. SDK-Sitzung ausdrücklich fortsetzen.") }
            }
            return
        }
        val speed = punch.speed
        val primary = Sdk0256Compat.primary(punch.power)
        val numeric = listOf(primary, speed.peakAcceleration, speed.peakVelocity, speed.displacement,
            Sdk0256Compat.punchSeconds(speed), Sdk0256Compat.contactSeconds(speed))
        if (numeric.any { !it.isFinite() || it < 0 } || primary <= 0 || (family == "Alpha" && (!Sdk0256Compat.baro(powerValue).isFinite() || Sdk0256Compat.baro(powerValue) < 0))) return
        val sequence = (sequences[device] ?: 0) + 1
        sequences[device] = sequence
        val json = identity(device, epoch).put("emittedAndroidMonotonicSeconds", emittedAt).put("eventId", eventId).put("sequence", sequence)
            .put("isValid", true).put("areComputedValuesValid", true).put("validityReason", "sdk_computation_valid")
            .put("timestamp", timestamp).put("timestampClock", "unix_seconds").put("hasTiming", true).put("sourceAgeSeconds", sourceAge)
            .put("unit", "unknown").put("peakAcceleration", speed.peakAcceleration).put("peakVelocity", speed.peakVelocity)
            .put("displacement", speed.displacement).put("punchDurationSeconds", numeric[4]).put("contactDurationSeconds", numeric[5])
        when (family) {
            "Alpha" -> json.put("quantity", "alpha.impact").put("impact", primary).put("peakForceBasedOnBaro", Sdk0256Compat.baro(powerValue))
            "Delta" -> json.put("quantity", "delta.power_index").put("powerIndex", primary)
        }
        DynamicsUnityBridge.sendPunch(json.toString())
    }

    private fun reconcileConnections(heartbeat: Boolean = false) {
        gloves.forEach { glove ->
            val device = alias(glove)
            val family = familyOf(glove)
            val side = sideOf(glove.dto.side)
            val provenance = if (glove.dto.isMock) "sdk_mock" else "dynamics_sdk"
            val old = epochs[device]
            val online = foreground && Sdk0256Compat.online(glove.bleGloveState) && family != "Unknown"
            if (!online) { retire(glove); return@forEach }
            if (old == null || old.family != family || old.side != side || old.provenance != provenance) {
                if (old != null) DynamicsUnityBridge.sendDeviceState(identity(device, old).put("status", "offline").toString())
                val fresh = Epoch(UUID.randomUUID().toString(), family, side, provenance)
                epochs[device] = fresh
                DynamicsUnityBridge.sendDeviceState(identity(device, fresh).put("status", "online").toString())
            } else if (heartbeat) DynamicsUnityBridge.sendDeviceState(identity(device, old).put("status", "online").toString())
        }
    }
    private fun retire(glove: Glove) {
        val device = alias(glove)
        epochs.remove(device)?.let { retiredDeviceEpochs[device] = it; DynamicsUnityBridge.sendDeviceState(identity(device, it).put("status", "offline").toString()) }
    }
    private fun identity(device: String, epoch: Epoch) = JSONObject().put("schemaVersion", 2).put("deviceId", device)
        .put("emittedAndroidMonotonicSeconds", monotonicSeconds())
        .put("connectionId", epoch.id).put("sensorType", epoch.family).put("bodySide", epoch.side).put("provenance", epoch.provenance)
    private fun alias(glove: Glove): String = alias(glove.dto)
    private fun alias(dto: PeripheralDto): String {
        val prefs = activity.getSharedPreferences("dynamics_device_aliases", Context.MODE_PRIVATE)
        val key = Sdk0256Compat.deviceUuid(dto).toString()
        return prefs.getString(key, null) ?: ("sensor_" + UUID.randomUUID().toString()).also { prefs.edit().putString(key, it).apply() }
    }
    private val knownFamilies = hashMapOf<String, String>()
    private fun familyOf(glove: Glove): String {
        val reported = when (glove.data?.sensorType) { TrainingSessionSensorType.ALPHA -> "Alpha"; TrainingSessionSensorType.DELTA -> "Delta"; else -> null }
        val id = alias(glove)
        if (reported != null) knownFamilies[id] = reported
        // Only a previously SDK-reported type for this exact identity; never infer from selected mode/name.
        return reported ?: knownFamilies[id] ?: "Unknown"
    }
    private fun displayName(glove: Glove): String = glove.data?.deviceName?.takeIf { it.isNotBlank() }
        ?: glove.dto.name.takeIf { it.isNotBlank() } ?: "Dynamics device"

    private fun sideOf(side: Side) = when (side) { Side.LEFT -> "Left"; Side.RIGHT -> "Right" }
    private fun parseSide(side: String) = when (side) { "Left" -> Side.LEFT; "Right" -> Side.RIGHT; else -> fail("invalid_side", "Linke oder rechte Körperseite ausdrücklich auswählen.") }
    private fun parseFamily(family: String) = when (family) { "Alpha" -> TrainingSessionSensorType.ALPHA; "Delta" -> TrainingSessionSensorType.DELTA; else -> fail("invalid_family", "Alpha oder Delta ausdrücklich auswählen.") }
    private fun requireForeground() { if (!foreground) fail("application_paused", "App zuerst in den Vordergrund bringen.") }
    private fun wallSeconds() = System.currentTimeMillis() / 1000.0
    private fun monotonicSeconds() = SystemClock.elapsedRealtimeNanos() / 1_000_000_000.0

    private fun status(newState: String, code: String, message: String) {
        state = newState
        lastStatusCode = code
        lastStatusMessage = message
        val devicesJson = JSONArray()
        gloves.forEach { glove -> val device = alias(glove); devicesJson.put(JSONObject().put("id", device)
            .put("name", displayName(glove)).put("side", sideOf(glove.dto.side)).put("family", familyOf(glove))
            .put("online", foreground && Sdk0256Compat.online(glove.bleGloveState)).put("connectionId", epochs[device]?.id ?: "")
            .put("isMock", glove.dto.isMock).put("firmwareVersion", glove.dto.firmwareVersion)) }
        val nearbyJson = JSONArray()
        nearby.forEach { (id, glove) -> nearbyJson.put(JSONObject().put("id", id).put("name", glove.advertisingName ?: "Dynamics-Gerät").put("family", "Unknown")) }
        DynamicsUnityBridge.sendNativeStatus(JSONObject().put("schemaVersion", 1).put("state", newState).put("code", code).put("message", message)
            .put("emittedAndroidMonotonicSeconds", monotonicSeconds())
            .put("statusSequence", ++statusSequence).put("controlRequestId", controlRequestId)
            .put("initialized", initialized && observing).put("permissionsGranted", missingPermissions().isEmpty())
            .put("sdkVersion", "0.25.6").put("sdkBuildMode", BuildConfig.SDK_BUILD_MODE).put("profileReference", if (profileReady) profileReference else "")
            .put("profileStudyId", participant).put("sessionFamily", sessionFamily)
            .put("devices", devicesJson).put("nearby", nearbyJson).put("profileReady", profileReady).put("sessionState", sessionState).toString())
    }

    @JvmStatic fun setApplicationPaused(paused: Boolean) {
        scope.launch {
            if (foreground == !paused) return@launch
            foreground = !paused
            // Close the game gate immediately, even while a pairing/start command is suspended.
            if (paused) { emissionEnabled = false; policy.disarm() }
            if (!initialized) return@launch
            command("application_pause") {
                if (paused) {
                    stopScanning()
                    gloves.forEach(::retire)
                    pauseInternal()
                    status("paused", "application_paused", "App im Hintergrund: Dateneingabe und SDK-Sitzung pausiert.")
                } else {
                    reconcileConnections()
                    status("ready", "application_resumed", "App im Vordergrund. SDK-Sitzung ausdrücklich fortsetzen.")
                }
            }
        }
    }
    @JvmStatic fun shutdown() = command("shutdown") {
        stopScanning()
        pauseInternal()
        gloves.forEach(::retire)
        observers.forEach { it.cancel() }; observers.clear(); observing = false
        status("paused", "collector_stopped", "Collector pausiert. Vorhandene SDK-Sitzung und Daten bleiben erhalten.")
    }
    private val lifecycle = object : Application.ActivityLifecycleCallbacks {
        override fun onActivityPaused(a: Activity) { if (a === UnityPlayer.currentActivity) setApplicationPaused(true) }
        override fun onActivityResumed(a: Activity) { if (a === UnityPlayer.currentActivity) setApplicationPaused(false) }
        override fun onActivityCreated(a: Activity, b: Bundle?) {}
        override fun onActivityStarted(a: Activity) {}
        override fun onActivityStopped(a: Activity) {}
        override fun onActivitySaveInstanceState(a: Activity, b: Bundle) {}
        override fun onActivityDestroyed(a: Activity) { if (a === UnityPlayer.currentActivity) setApplicationPaused(true) }
    }
}
