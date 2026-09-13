package com.boxreha.dynamics

/** Pure transport policies; these tests do not establish Bluetooth or clinical performance. */
internal class CollectorPolicy(private val identityLimit: Int = 100_000) {
    private val consumed = HashSet<String>()
    private var wallAnchor = 0.0
    private var monotonicAnchor = 0.0
    private var resumeCutoff = Double.POSITIVE_INFINITY
    private var clockQualified = false
    val isClockQualified: Boolean get() = clockQualified
    var isSaturated: Boolean = false
        private set
    init { require(identityLimit > 0) }

    /** Only after a genuinely new SDK session was created, never after pause/reconnect. */
    fun resetForNewSession() {
        consumed.clear()
        isSaturated = false
        clockQualified = false
        disarm()
    }

    fun arm(wallSeconds: Double, monotonicSeconds: Double) {
        wallAnchor = wallSeconds
        monotonicAnchor = monotonicSeconds
        resumeCutoff = wallSeconds
        clockQualified = wallSeconds.isFinite() && wallSeconds > 0 && monotonicSeconds.isFinite()
    }

    fun disarm() { resumeCutoff = Double.POSITIVE_INFINITY }

    /** Absolute 100 ms wall/monotonic drift bound; never use relative Unix-time tolerances. */
    fun sourceAge(timestamp: Double, wallNow: Double, monotonicNow: Double): Double? {
        if (!clockQualified || !timestamp.isFinite() || timestamp <= 0 ||
            !wallNow.isFinite() || !monotonicNow.isFinite()) return null
        val elapsed = monotonicNow - monotonicAnchor
        if (elapsed < 0 || kotlin.math.abs((wallNow - wallAnchor) - elapsed) > 0.100) {
            clockQualified = false
            return null
        }
        val age = wallNow - timestamp
        return age.takeIf { timestamp >= resumeCutoff && it >= 0 && it <= 0.500 }
    }

    /** Record before eligibility checks so snapshots rejected during pause cannot become live later. */
    fun consume(id: String): Boolean {
        if (id.isBlank() || consumed.contains(id)) return false
        if (consumed.size >= identityLimit) { isSaturated = true; return false }
        return consumed.add(id)
    }

    companion object {
        fun familyError(families: List<String>, sides: List<String>, online: List<Boolean>, requested: String): String? = when {
            requested != "Alpha" && requested != "Delta" -> "invalid_family"
            families.isEmpty() -> "no_devices"
            families.size > 2 -> "device_limit_two"
            families.size != sides.size || families.size != online.size -> "invalid_devices"
            sides.any { it != "Left" && it != "Right" } || sides.distinct().size != sides.size -> "invalid_sides"
            online.any { !it } -> "device_offline"
            families.any { it != "Alpha" && it != "Delta" } -> "unknown_family"
            families.distinct().size != 1 -> "mixed_families_unsupported"
            families.any { it != requested } -> "family_downgrade_refused"
            else -> null
        }
    }
}
