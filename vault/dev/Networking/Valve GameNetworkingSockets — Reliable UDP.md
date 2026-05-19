<!-- generated-from-dump2 -->
# Valve GameNetworkingSockets — Reliable UDP

Valve's reliable+unreliable message transport over UDP, extracted from Steam Networking and open-sourced. Handles fragmentation/reassembly, AES-GCM encryption, NAT punching via Steam datagram relay (optional), and a BSD-sockets-like API. Used by CS:GO, Dota 2, and many indie titles.

```cpp
SteamNetworkingIPAddr addr; addr.Clear();
addr.ParseString("127.0.0.1:27015");

ISteamNetworkingSockets* api = SteamNetworkingSockets();
HSteamNetConnection h = api->ConnectByIPAddress(addr, 0, nullptr);

// Send a reliable message.
const char* msg = "hello";
api->SendMessageToConnection(h, msg, 5,
    k_nSteamNetworkingSend_Reliable, nullptr);
```

## References
- <https://github.com/ValveSoftware/GameNetworkingSockets>
