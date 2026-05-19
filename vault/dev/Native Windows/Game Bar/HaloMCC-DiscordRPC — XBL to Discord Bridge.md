# HaloMCC-DiscordRPC — XBL to Discord Bridge

Python bridge: polls the Xbox Live presence API for the user's Halo MCC session info and pushes it into Discord's local IPC socket as Rich Presence. Useful as a worked example of the XBL OAuth flow + the discord-ipc named-pipe protocol (`\\\\.\\pipe\\discord-ipc-0`), both of which are reusable for any "show what I'm playing" widget.

```python
# Discord RPC over local pipe (Windows: \\.\pipe\discord-ipc-0)
import struct, json, os
pipe = open(r"\\.\pipe\discord-ipc-0", "r+b", buffering=0)
def send(op, payload):
    data = json.dumps(payload).encode()
    pipe.write(struct.pack("<II", op, len(data)) + data)
send(0, {"v": 1, "client_id": CLIENT_ID})           # HANDSHAKE
send(1, {"cmd": "SET_ACTIVITY", "args": {           # FRAME
    "pid": os.getpid(),
    "activity": {"details": "Playing Halo: CE", "state": "Mission 03"}
}, "nonce": "1"})
```

## References
- <https://github.com/kay-el-zed/HaloMCC-DiscordRPC>
