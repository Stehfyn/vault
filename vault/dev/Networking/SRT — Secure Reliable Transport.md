<!-- generated-from-dump2 -->
# SRT — Secure Reliable Transport

Secure Reliable Transport — open-source UDP-based protocol from Haivision designed for low-latency live video over the public internet. Recovers from packet loss via ARQ with a configurable latency budget (typically 80-300 ms), encrypts with AES-128/256, and is now an IETF draft. Standard transport for OBS -> ingest, FFmpeg `srt://...`, and broadcast contribution links.

```bash
# Listener (e.g. ingest).
srt-live-transmit srt://:9000?mode=listener file:///tmp/out.ts

# Caller (e.g. encoder on the other side).
ffmpeg -i input.mp4 -c copy -f mpegts \
       "srt://ingest.example.com:9000?mode=caller&latency=200&passphrase=hunter2"
```

## References
- <https://github.com/Haivision/srt>
