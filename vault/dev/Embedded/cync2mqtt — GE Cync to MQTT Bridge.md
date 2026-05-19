<!-- generated-from-dump2 -->
# cync2mqtt — GE Cync to MQTT Bridge

Python bridge from GE Cync (formerly C by GE) smart bulbs to MQTT, primarily so they can be driven from Home Assistant without going through GE/Cync's cloud. Cync bulbs form a Bluetooth Low Energy **mesh**, and one of the bulbs (the "gateway") is also Wi-Fi-connected and proxies the mesh up to GE's cloud. cync2mqtt logs in with your Cync credentials to fetch the mesh topology + per-bulb mesh IDs and shared secret, then connects directly to one of the bulbs over BLE and injects mesh control packets — completely bypassing the cloud once you have the keys. Useful as a reference for reverse-engineered BLE-mesh control and for getting cloud-dependent IoT off the internet.

```python
# Conceptual flow (real impl in cync2mqtt/cync_mesh.py):
# 1. Authenticate to api.gelighting.com -> get user + meshes + bulbs metadata.
# 2. For each mesh: read mesh name, the AES key, and per-bulb IDs.
# 3. Connect over BLE to the first reachable bulb in the mesh (it'll relay).
# 4. Send encrypted mesh-control packets:
#       Set brightness:  opcode 0xD2, payload [meshId, brightness%]
#       Set color (RGB): opcode 0xE2, payload [meshId, r, g, b]
# 5. Re-publish bulb state to MQTT topics like  cync2mqtt/<mesh>/<bulb>/state.
```

## References
- <https://github.com/juanboro/cync2mqtt>
