<!-- generated-from-dump2 -->
# librepods — Reverse-Engineered AirPods BLE Protocol

Reverse-engineered AirPods BLE protocol; documents battery, lid, and in-ear status packets.

```kotlin
fun parseBattery(data: ByteArray): Triple<Int, Int, Int> {
  val left = (data[2].toInt() and 0xF0) shr 4
  val right = (data[2].toInt() and 0x0F)
  val case = (data[3].toInt() and 0xF0) shr 4
  return Triple(left * 10, right * 10, case * 10)
}
```

## References
- <https://github.com/kavishdevar/librepods>
