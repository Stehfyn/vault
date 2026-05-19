<!-- generated-from-dump2 -->
# hass-gelight — BLE Control for GE Bulbs

Home Assistant custom component that talks to "C by GE" smart bulbs over Bluetooth locally - bypassing the GE cloud and avoiding the cloud's 200-ms+ command latency. Reverse-engineered the BLE GATT service used by the Cync/C-by-GE official app: a single writeable characteristic that accepts short binary commands (on/off, brightness 0-255, RGB triple, color-temperature). Plug it into HA's `light` platform and you get sub-100-ms local control of bulbs that would otherwise require routing through GE's servers.

```python
# Conceptual command formats (paraphrased):
#   power on:    b"\x01\x00\x00\x05\x00"          -> write to FFE1
#   brightness:  b"\x01\x00\x00\x05\x01" + bytes([lvl])
#   RGB:         b"\x01\x00\x00\x05\x02" + bytes([r,g,b])
#   color temp:  b"\x01\x00\x00\x05\x03" + bytes([k_0_to_100])
async def set_brightness(client, level):
    await client.write_gatt_char(GATT_CONTROL,
        b"\x01\x00\x00\x05\x01" + bytes([level]))
```

## References
- <https://github.com/yangqian/hass-gelight>
