<!-- generated-from-dump2 -->
# FreeRDP Client and Server

Open-source implementation of Microsoft's Remote Desktop Protocol. Ships a client (`xfreerdp`, `wlfreerdp`, `mstsc`-style on Windows) and a server framework. Reference for RDP wire format, NLA/CredSSP auth, RemoteFX/AVC codecs, virtual channels, and clipboard/drive redirection. Backbone of basically every non-Microsoft RDP client.

```bash
# Connect with NLA, dynamic resolution, audio, clipboard, and drive share.
xfreerdp /v:host.example.com /u:user /d:CORP \
         /dynamic-resolution /audio-mode:0 +clipboard \
         /drive:home,/home/me/share /sec:nla
```

## References
- <https://github.com/FreeRDP/FreeRDP>
