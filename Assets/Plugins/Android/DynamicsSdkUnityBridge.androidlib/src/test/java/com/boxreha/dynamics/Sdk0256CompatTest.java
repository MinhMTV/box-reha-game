package com.boxreha.dynamics;
import org.junit.Test;
import static org.junit.Assert.*;
import com.riseworld.dynamics.models.domain.punch.*;
import com.riseworld.dynamics.models.domain.profile.body.*;
import kotlin.uuid.Uuid;
import kotlin.time.Duration;
import kotlin.time.DurationUnit;

/** Synthetic ABI unit fixtures only: never emitted to Unity or recorded as physical observations. */
public class Sdk0256CompatTest {
    @Test public void actualVendorAlphaAndDeltaAccessors() {
        Sdk0256Compat.verifyAbi();
        Power alpha = new Power$Alpha(12.5, 8.0);
        Power delta = new Power$Delta(7.25);
        assertEquals("Alpha", Sdk0256Compat.family(alpha));
        assertEquals(12.5, Sdk0256Compat.primary(alpha), 0);
        assertEquals(8, Sdk0256Compat.baro(alpha), 0);
        assertEquals("Delta", Sdk0256Compat.family(delta));
        assertEquals(7.25, Sdk0256Compat.primary(delta), 0);
    }
    @Test public void actualProfileConstructorAndMangledUuidRoundTrip() {
        Uuid id = Uuid.Companion.parse("22222222-2222-4222-8222-222222222222");
        BodyProfile body = Sdk0256Compat.body(id,"unit_fixture",70,170,Gender.MALE);
        assertEquals("unit_fixture", body.getName());
        assertEquals(id, Sdk0256Compat.profileId(body));
        assertTrue(Sdk0256Compat.validName("unit_fixture"));
        assertFalse(Sdk0256Compat.validName(""));
        assertTrue(Sdk0256Compat.validBody(70,170));
        assertFalse(Sdk0256Compat.validBody(1,170));
        assertFalse(Sdk0256Compat.validBody(70,500));
    }
    @Test public void durationUsesKotlinConversionWithoutReinterpretingPackedLong() throws Exception {
        // Use the public Kotlin runtime conversion to construct fixtures, including sub-millisecond values.
        Class<?> kt = Class.forName("kotlin.time.DurationKt");
        long punch = (Long)kt.getMethod("toDuration", double.class, DurationUnit.class).invoke(null,0.125,DurationUnit.SECONDS);
        long contact = (Long)kt.getMethod("toDuration", double.class, DurationUnit.class).invoke(null,0.00025,DurationUnit.SECONDS);
        Speed speed = new Speed(punch,contact,3,4,5,null);
        assertEquals(.125,Sdk0256Compat.punchSeconds(speed),1e-12);
        assertEquals(.00025,Sdk0256Compat.contactSeconds(speed),1e-12);
    }
    @Test(expected=IllegalArgumentException.class) public void deltaCannotBeReadAsAlphaBarometer() { Sdk0256Compat.baro(new Power$Delta(1)); }
    @Test public void unknownStateNeverBecomesResumedOrOnline() {
        assertEquals("Unknown", Sdk0256Compat.sessionState(null));
        assertFalse(Sdk0256Compat.online(new Object()));
        assertNotNull(Sdk0256Compat.freeSession());
    }
}
