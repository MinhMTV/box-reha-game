package com.boxreha.dynamics

import com.riseworld.dynamics.models.PeripheralDto
import com.riseworld.dynamics.multiplatform.repository.GloveRepository
import com.riseworld.launchpad.resource.Resource
import kotlin.coroutines.intrinsics.suspendCoroutineUninterceptedOrReturn

/** Exact SDK 0.25.6 suspend ABI, including synchronous return and COROUTINE_SUSPENDED. */
object SdkDeviceOperations {
    suspend fun remove(repository: GloveRepository, dto: PeripheralDto): Resource =
        suspendCoroutineUninterceptedOrReturn { Sdk0256Compat.deleteDevice(repository, dto, it) }
    suspend fun swap(repository: GloveRepository, dto: PeripheralDto): Resource =
        suspendCoroutineUninterceptedOrReturn { Sdk0256Compat.swapDevice(repository, dto, it) }
    suspend fun deleteAll(repository: GloveRepository): Resource =
        suspendCoroutineUninterceptedOrReturn { Sdk0256Compat.deleteAllDevices(repository, it) }
}

