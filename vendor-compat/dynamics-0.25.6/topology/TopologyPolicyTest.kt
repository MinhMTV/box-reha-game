package com.boxreha.dynamics
import org.junit.Test
import org.junit.Assert.*
/** Collector policy fixtures, not vendor runtime or Bluetooth topology evidence. */
class TopologyPolicyTest {
    private fun check(families: List<String>, sides: List<String>, requested: String, expected: String?) {
        assertEquals(expected, CollectorPolicy.familyError(families,sides,families.map { true },requested))
    }
    @Test fun T1_oneAlpha() = check(listOf("Alpha"),listOf("Left"),"Alpha",null)
    @Test fun T2_alphaPair() = check(listOf("Alpha","Alpha"),listOf("Left","Right"),"Alpha",null)
    @Test fun T3_oneDelta() = check(listOf("Delta"),listOf("Left"),"Delta",null)
    @Test fun T4_deltaPair() = check(listOf("Delta","Delta"),listOf("Left","Right"),"Delta",null)
    @Test fun T5_alphaLeftDeltaLeft() = check(listOf("Alpha","Delta"),listOf("Left","Left"),"Alpha","invalid_sides")
    @Test fun T6_alphaPairDeltaLeft() = check(listOf("Alpha","Alpha","Delta"),listOf("Left","Right","Left"),"Alpha","device_limit_two")
    @Test fun T7_fourDevices() = check(listOf("Alpha","Alpha","Delta","Delta"),listOf("Left","Right","Left","Right"),"Alpha","device_limit_two")
}
