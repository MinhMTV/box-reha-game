package com.boxreha.dynamics;

import com.riseworld.dynamics.models.PeripheralDto;
import com.riseworld.dynamics.models.PeripheralId;
import com.riseworld.dynamics.models.domain.punch.*;
import com.riseworld.dynamics.models.domain.profile.body.*;
import com.riseworld.dynamics.models.domain.session.*;
import com.riseworld.launchpad.ble.multiplex.models.domain.ScannerState$Error;
import java.lang.reflect.Method;
import java.lang.reflect.InvocationTargetException;
import com.riseworld.dynamics.multiplatform.repository.GloveRepository;
import com.riseworld.dynamics.multiplatform.repository.SensorDataRepository;
import com.riseworld.dynamics.models.ble.data.SensorDataPacket;
import kotlin.coroutines.Continuation;
import kotlinx.coroutines.flow.Flow;
import java.util.List;
import kotlin.uuid.Uuid;
import kotlin.time.Duration;
import kotlin.time.DurationUnit;

/** SDK 0.25.6 Android ABI adapter. No patched vendor classes or reconstructed metadata.
 * Java handles stripped nested-class metadata. Reflection is restricted to the listed public,
 * mangled value-class methods; lookup and invocation failures always fail closed. */
public final class Sdk0256Compat {
    private Sdk0256Compat() {}
    private static Method method(Class<?> owner, String name, Class<?> returns, Class<?>... args) {
        try {
            Method m = owner.getMethod(name, args);
            if (m.getReturnType() != returns) throw new IllegalStateException("Return descriptor changed: " + name);
            return m;
        } catch (ReflectiveOperationException e) { throw new IllegalStateException("SDK 0.25.6 ABI mismatch: " + owner.getName() + "." + name, e); }
    }
    private static Object invoke(Method m, Object receiver, Object... args) {
        try { return m.invoke(receiver, args); }
        catch (InvocationTargetException e) { throw new IllegalStateException("SDK 0.25.6 call failed: " + m.getName(), e.getCause()); }
        catch (ReflectiveOperationException e) { throw new IllegalStateException("SDK 0.25.6 ABI invocation failed: " + m.getName(), e); }
    }
    private static final Method DEVICE_ID = method(PeripheralDto.class, "getId-WPD2SKI", Uuid.class);
    private static final Method UNBOX_ID = method(PeripheralId.class, "unbox-impl", Uuid.class);
    public static Uuid pairedUuid(Object id) {
        if (id instanceof com.riseworld.launchpad.resource.Resource) {
            id = ((com.riseworld.launchpad.resource.Resource)id).getOrThrow();
        }
        if (id instanceof PeripheralId) return (Uuid)invoke(UNBOX_ID, id);
        if (id instanceof Uuid) return (Uuid)id;
        throw new IllegalStateException("Pair result is not PeripheralId or Uuid: " + id);
    }
    private static final Method PUNCH_ID = method(Punch.class, "getId-x1nF_Dg", Uuid.class);
    private static final Method PUNCH_DEVICE = method(Punch.class, "getPeripheralId-WPD2SKI", Uuid.class);
    private static final Method PACKET_TIME = method(SensorDataPacket.class, "getRelativeTimeCounter-UwyO8pc", long.class);
    private static final Method PUNCH_DURATION = method(Speed.class, "getPunchDuration-UwyO8pc", long.class);
    private static final Method CONTACT_DURATION = method(Speed.class, "getContactDuration-UwyO8pc", long.class);
    private static final Method DURATION_SECONDS = method(Duration.class, "toDouble-impl", double.class, long.class, DurationUnit.class);
    private static final Method DELETE = method(GloveRepository.class, "deleteGloveById-gP7SR54", Object.class, Uuid.class, Continuation.class);
    private static final Method DELETE_ALL = method(GloveRepository.class, "deleteAllGloves", Object.class, Continuation.class);
    private static final Method SWAP = method(GloveRepository.class, "swapGloveSideForId-gP7SR54", Object.class, Uuid.class, Continuation.class);
    private static final Method RAW = method(SensorDataRepository.class, "observeSensorData-16HgSWs", Flow.class, Uuid.class);
    private static final Method RAW_ALL = method(SensorDataRepository.class, "observeSensorDataFromAllGloves", Flow.class);
    private static final Method PAIR = method(com.riseworld.dynamics.multiplatform.repository.PairingRepository.class, "pair", Object.class,
        com.riseworld.dynamics.models.ble.nearby.NearbyGlove.class, String.class, com.riseworld.dynamics.models.Side.class, Continuation.class);
    private static final Method DURATION_LONG = method(Duration.class, "toLong-impl", long.class, long.class, DurationUnit.class);
    public static Object deleteDevice(GloveRepository repository, PeripheralDto dto, Continuation<?> continuation) {
        return invoke(DELETE, repository, deviceUuid(dto), continuation);
    }
    public static Object deleteAllDevices(GloveRepository repository, Continuation<?> continuation) {
        return invoke(DELETE_ALL, repository, continuation);
    }
    public static Object swapDevice(GloveRepository repository, PeripheralDto dto, Continuation<?> continuation) {
        return invoke(SWAP, repository, deviceUuid(dto), continuation);
    }
    @SuppressWarnings("unchecked")
    public static Flow<List<SensorDataPacket>> raw(SensorDataRepository repository, PeripheralDto dto) {
        return (Flow<List<SensorDataPacket>>)invoke(RAW, repository, deviceUuid(dto));
    }
    public static void verifyAbi() { /* Initialization resolves every required reflective descriptor. */ }
    public static Uuid deviceUuid(PeripheralDto dto) { return (Uuid)invoke(DEVICE_ID, dto); }
    public static String punchId(Punch p) { return invoke(PUNCH_ID, p).toString(); }
    public static Uuid punchPeripheralUuid(Punch p) { return (Uuid)invoke(PUNCH_DEVICE, p); }
    public static double packetSeconds(SensorDataPacket p) { return (Double)invoke(DURATION_SECONDS, null, invoke(PACKET_TIME, p), DurationUnit.SECONDS); }
    public static long packetRelativeNanos(SensorDataPacket p) { return (Long)invoke(DURATION_LONG, null, invoke(PACKET_TIME, p), DurationUnit.NANOSECONDS); }
    public static long packetRelativePacked(SensorDataPacket p) { return (Long)invoke(PACKET_TIME, p); }
    public static BodyProfile body(Uuid id, String name, double kg, double cm, Gender gender) { return new BodyProfile(id,name,kg,cm,gender,null); }
    @SuppressWarnings("unchecked")
    public static boolean validBody(double kg, double cm) { return BodyProfileValidation.Companion.getWeightRange().contains(kg) && BodyProfileValidation.Companion.getHeightRange().contains(cm); }
    public static TrainingSessionSettings freeSession() { return new TrainingSessionSettings$Free(false); }
    public static boolean scannerActive(Object state) {
        return state instanceof com.riseworld.launchpad.ble.multiplex.models.domain.ScannerState$Active;
    }
    public static boolean scannerError(Object state) { return state instanceof ScannerState$Error; }
    public static String sessionState(Object state) {
        if (state instanceof TrainingSessionExtendedState$Resumed) return "Resumed";
        if (state instanceof TrainingSessionExtendedState$Ready) return "Ready";
        if (state instanceof TrainingSessionExtendedState$Paused) return "Paused";
        if (state instanceof TrainingSessionExtendedState$Initializing) return "Initializing";
        return "Unknown";
    }
    public static String family(Power p) {
        if (p instanceof Power$Alpha) return "Alpha";
        if (p instanceof Power$Delta) return "Delta";
        throw new IllegalStateException("Unsupported SDK power type");
    }
    public static double primary(Power p) {
        if (p instanceof Power$Alpha) return ((Power$Alpha)p).getImpact();
        if (p instanceof Power$Delta) return ((Power$Delta)p).getPowerIndex();
        throw new IllegalStateException("Unsupported SDK power type");
    }
    /** Base-class quantities kept for BOTH families; DELTA's powerIndex is never renamed. */
    public static double impactOrPowerIndex(Power p) { return p.getImpactOrPowerIndex(); }
    public static double peakForce(Power p) { return p.getPeakForce(); }
    public static double baro(Power p) { if (!(p instanceof Power$Alpha)) throw new IllegalArgumentException("ALPHA required"); return ((Power$Alpha)p).getPeakForceBasedOnBaro(); }
    public static double punchSeconds(Speed s) { return (Double)invoke(DURATION_SECONDS,null,invoke(PUNCH_DURATION,s),DurationUnit.SECONDS); }
    public static double contactSeconds(Speed s) { return (Double)invoke(DURATION_SECONDS,null,invoke(CONTACT_DURATION,s),DurationUnit.SECONDS); }
    public static double vecX(Object v) {
        if (v instanceof com.riseworld.dynamics.models.ble.data.Vector3d) {
            Object val = ((com.riseworld.dynamics.models.ble.data.Vector3d)v).getX();
            if (val instanceof Number) return ((Number)val).doubleValue();
        }
        return 0.0;
    }
    public static double vecY(Object v) {
        if (v instanceof com.riseworld.dynamics.models.ble.data.Vector3d) {
            Object val = ((com.riseworld.dynamics.models.ble.data.Vector3d)v).getY();
            if (val instanceof Number) return ((Number)val).doubleValue();
        }
        return 0.0;
    }
    public static double vecZ(Object v) {
        if (v instanceof com.riseworld.dynamics.models.ble.data.Vector3d) {
            Object val = ((com.riseworld.dynamics.models.ble.data.Vector3d)v).getZ();
            if (val instanceof Number) return ((Number)val).doubleValue();
        }
        return 0.0;
    }
}
