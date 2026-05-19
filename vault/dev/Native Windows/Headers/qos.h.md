# qos.h

The original Generic QoS (GQoS) types -- `FLOWSPEC`, `QOS`, `SERVICETYPE_*` (`SERVICETYPE_GUARANTEED`, `SERVICETYPE_CONTROLLEDLOAD`, `SERVICETYPE_BESTEFFORT`) -- used by the Win2K-era RSVP/Winsock 2 integration: `WSAIoctl(SIO_SET_QOS, ...)` would take a `QOS` structure built from these constants. Almost completely superseded by qWAVE (`qos2.h`) in Vista, but the structures still appear because (a) Winsock 2 layered providers continue to expose `SIO_GET_QOS` / `SIO_SET_QOS`, (b) some legacy WMI / NDIS interfaces re-export `FLOWSPEC` shapes. The 30-second history: GQoS was designed as the user-space half of RSVP; RSVP did not deploy at internet scale; the API stuck around as DSCP marking with a more elaborate vocabulary than it needed.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/qos/>
- <https://learn.microsoft.com/en-us/windows/win32/winsock/quality-of-service-2>
