<!-- generated-from-dump2 -->
# Experienceless — Shadowplay Local HTTP API Client

Reverse-engineered client for NVIDIA Shadowplay's local HTTP API — the same one GeForce Experience uses internally to start/stop recording, manage the instant-replay buffer, and capture screenshots. The interesting bit is that this lets you drive Shadowplay's hardware encoder (NVENC, gpu-accelerated) and its game-aware capture without running GeForce Experience or its login layer. The API is undocumented; the project encodes the discovered endpoints (port and bearer-token discovery via the local NVIDIA Container service) and exposes them as a programmable client. Useful for streamers / tools that want to record without giving up the GFE telemetry/login.

```text
# Conceptual flow:
#   1. Locate the NVIDIA Container service local port from the registry
#      (HKLM\SOFTWARE\NVIDIA Corporation\Global\ShadowPlay) or by probing
#      127.0.0.1:<port> for /alive on the GFE-installed ports.
#   2. Read the bearer token from the same local config / file.
#   3. POST /ShadowPlay/Recording/StartRecord  to begin a recording session.
#   4. POST /ShadowPlay/Recording/StopRecord   to flush and save.
#   5. GET  /ShadowPlay/Recording/Status       for current state.
#
# All requests are application/json with `Authorization: Bearer <token>`.
```

## References
- <https://github.com/cm-pony/Experienceless>
