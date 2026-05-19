<!-- generated-from-dump2 -->
# laurel — Cync BLE Smart Bulb Driver

Reverse-engineered Python library to drive C by GE / Cync Bluetooth smart bulbs directly over BLE GATT, bypassing the cloud/app entirely. Matthew Garrett (mjg59) did the protocol RE because the official app required Internet round-trips for what is fundamentally a local BLE control problem. The library handles the proprietary auth handshake the bulbs require and exposes brightness / RGB / on-off as Python coroutines using `bleak` as the BLE transport. Cited frequently in Home Assistant integrations that want true local control of these bulbs.

```python
import asyncio
from laurel import LaurelDevice

async def main():
    dev = LaurelDevice("AA:BB:CC:DD:EE:FF")   # bulb MAC
    await dev.connect()
    await dev.set_power(True)
    await dev.set_brightness(50)              # 0-100
    await dev.set_color(255, 64, 0)           # warm orange
    await dev.disconnect()

asyncio.run(main())
```

## References
- <https://github.com/mjg59/python-laurel>
