<!-- generated-from-dump2 -->
# TF2 Rich Presence — Discord Status from Console Log

Python sidecar that tails `console.log` from a running TF2 client to produce Discord Rich Presence (map, gamemode, class, server name, time on map). The clever-ish bit: TF2 has no Rich Presence API of its own and Valve's `-condebug` flag is the only sanctioned hook, so the project boots the game with `-condebug -conclearlog` to guarantee an open log file, then polls it for chat/score/map-changed lines. Class detection works by parsing `tf_use_min_viewmodels` and the localized class-change strings. Talks to Discord via the IPC named-pipe (`\\.\pipe\discord-ipc-0` on Windows) using the documented Rich Presence opcodes.

```python
# Sketch (real implementation has resilience for log rotation, mp_paused, etc.)
import time, json, struct, os
PIPE = r"\\.\pipe\discord-ipc-0"
fd = os.open(PIPE, os.O_RDWR | os.O_BINARY)
# 0x00 = HANDSHAKE, 0x01 = FRAME
def send(op, payload):
    data = json.dumps(payload).encode()
    os.write(fd, struct.pack("<II", op, len(data)) + data)

send(0, {"v": 1, "client_id": "<discord-app-id>"})
log = open(r"C:\Program Files (x86)\Steam\steamapps\common\Team Fortress 2\tf\console.log")
log.seek(0, 2)
while True:
    line = log.readline()
    if "Map: " in line:
        send(1, {"cmd": "SET_ACTIVITY", "args": {"pid": os.getpid(),
                 "activity": {"details": line.split("Map: ")[1].strip()}},
                 "nonce": "1"})
    time.sleep(1)
```

## References
- <https://github.com/Kataiser/tf2-rich-presence>
