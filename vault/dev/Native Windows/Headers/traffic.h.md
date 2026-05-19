# traffic.h

The original Traffic Control / GQoS API in `traffic.dll` (NT 5.x / Windows 2000 era), built on the IETF RSVP signalling model. Apps would `TcRegisterClient`, open an interface, install a per-flow `TC_GEN_FLOW` describing token-bucket / peak-rate parameters, then add `TC_GEN_FILTER` records pinning that flow to specific 5-tuples -- and the OS would, in theory, push the same parameters out via RSVP signalling so routers along the path could reserve bandwidth. In practice the broader internet never deployed RSVP at scale and the signalling fell back to local-only DSCP marking. Superseded in Vista by qWAVE (`qos2.h`); kept around for back-compat. You almost certainly want qos2.h instead unless you are reverse-engineering an NT5-era IP telephony product.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/traffic/>
