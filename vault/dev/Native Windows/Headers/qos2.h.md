# qos2.h

qWAVE (Quality Windows Audio/Video Experience) -- the Vista-era replacement for the original RSVP-based QoS in `qos.h` / `traffic.h`. Implemented by `qwave.dll` and the `QWAVE` service; presents a flow-based API (`QOSCreateHandle`, `QOSAddSocketToFlow`, `QOSSetFlow`, `QOSNotifyFlow`) that lets a user-mode app tag traffic with a `QOS_TRAFFIC_TYPE` (`Voice`, `AudioVideo`, `Background`, `BestEffort`, etc.) which the kernel then translates into DSCP markings on the outgoing packets and asks the network stack for latency/bandwidth estimates. Lightly used in practice -- modern apps that want DSCP marking usually just call `setsockopt(IP_TOS)` or use Group Policy-based QoS, and the network estimation side never delivered on its sales pitch.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/qos2/>
