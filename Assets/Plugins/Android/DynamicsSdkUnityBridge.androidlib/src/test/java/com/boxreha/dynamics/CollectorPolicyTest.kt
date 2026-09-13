package com.boxreha.dynamics

import org.junit.Assert.*
import org.junit.Test

class CollectorPolicyTest {
    @Test fun capacityFailureIsExplicitAndResumeCannotResetDeduplication() {
        val p = CollectorPolicy(identityLimit = 2)
        assertTrue(p.consume("one")); assertTrue(p.consume("two"))
        assertFalse(p.consume("one")); assertFalse(p.isSaturated)
        assertFalse(p.consume("three")); assertTrue(p.isSaturated)
        p.arm(1000.0, 10.0)
        assertFalse(p.consume("four")); assertTrue(p.isSaturated)
    }
    @Test fun aNewSdkSessionResetsCapacityButStillRequiresAQualifiedResume() {
        val p = CollectorPolicy(identityLimit = 1)
        p.consume("one"); p.consume("two")
        p.resetForNewSession()
        assertFalse(p.isSaturated)
        assertTrue(p.consume("new-session-event"))
        assertNull(p.sourceAge(1000.0, 1000.1, 10.1))
    }
    @Test fun validSourceAgeKeepsActualUnixTimestamp() {
        val p = CollectorPolicy()
        p.arm(1_800_000_000.0, 20.0)
        assertEquals(0.125, p.sourceAge(1_800_000_000.125, 1_800_000_000.250, 20.250)!!, 0.000001)
    }
    @Test fun staleFutureAndPreResumeSnapshotsAreRejected() {
        val p = CollectorPolicy()
        p.arm(1000.0, 10.0)
        assertNull(p.sourceAge(999.9, 1000.1, 10.1))
        assertNull(p.sourceAge(1000.2, 1000.1, 10.1))
        assertNull(p.sourceAge(1000.0, 1000.501, 10.501))
    }
    @Test fun clockStepFailsClosedUntilExplicitResume() {
        val p = CollectorPolicy()
        p.arm(1_800_000_000.0, 20.0)
        assertNull(p.sourceAge(1_800_000_001.0, 1_800_000_001.0, 20.5))
        assertNull(p.sourceAge(1_800_000_001.1, 1_800_000_001.1, 21.1))
        p.arm(1_800_000_002.0, 22.0)
        assertNotNull(p.sourceAge(1_800_000_002.1, 1_800_000_002.2, 22.2))
    }
    @Test fun invalidAndReversedClocksCannotQualify() {
        val p = CollectorPolicy()
        p.arm(1000.0, 10.0)
        assertNull(p.sourceAge(Double.NaN, 1000.1, 10.1))
        assertNull(p.sourceAge(1000.0, 1000.0, 9.0))
        p.arm(Double.NaN, 10.0)
        assertNull(p.sourceAge(1000.0, 1000.1, 10.1))
    }
    @Test fun pauseDiscardsEventsButRetainsUuidDeduplication() {
        val p = CollectorPolicy()
        p.arm(1000.0, 10.0)
        assertTrue(p.consume("sdk-punch-1"))
        p.disarm()
        assertNull(p.sourceAge(1000.1, 1000.2, 10.2))
        p.arm(1001.0, 11.0)
        assertFalse(p.consume("sdk-punch-1"))
        assertTrue(p.consume("sdk-punch-2"))
        assertFalse(p.consume(""))
    }
    @Test fun aSingleDeviceOrSameFamilyPairIsExplicitlySupported() {
        assertNull(CollectorPolicy.familyError(listOf("Alpha"), listOf("Left"), listOf(true), "Alpha"))
        assertNull(CollectorPolicy.familyError(listOf("Delta", "Delta"), listOf("Left", "Right"), listOf(true, true), "Delta"))
    }
    @Test fun mixedFamiliesAndDowngradeAreRejected() {
        assertEquals("mixed_families_unsupported", CollectorPolicy.familyError(listOf("Alpha", "Delta"), listOf("Left", "Right"), listOf(true, true), "Delta"))
        assertEquals("family_downgrade_refused", CollectorPolicy.familyError(listOf("Alpha"), listOf("Left"), listOf(true), "Delta"))
    }
    @Test fun thirdDeviceCannotMasqueradeAsSupportedPair() {
        assertEquals("device_limit_two", CollectorPolicy.familyError(listOf("Alpha", "Alpha", "Delta"), listOf("Left", "Right", "Left"), listOf(true, true, true), "Alpha"))
    }
    @Test fun offlineUnknownAndDuplicateSideRequireCorrection() {
        assertEquals("device_offline", CollectorPolicy.familyError(listOf("Alpha"), listOf("Left"), listOf(false), "Alpha"))
        assertEquals("unknown_family", CollectorPolicy.familyError(listOf("Unknown"), listOf("Left"), listOf(true), "Alpha"))
        assertEquals("invalid_sides", CollectorPolicy.familyError(listOf("Alpha", "Alpha"), listOf("Left", "Left"), listOf(true, true), "Alpha"))
        assertEquals("invalid_family", CollectorPolicy.familyError(emptyList(), emptyList(), emptyList(), "Unknown"))
    }
}
