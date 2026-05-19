<!-- generated-from-dump2 -->
# GoodbyeDPI — Anti-Censorship DPI Evader

Windows utility that defeats common ISP/state DPI-based blocking by manipulating outgoing TLS ClientHello / HTTP Host headers (fragmenting, fake-TTL, TCP-split, replacing Host case). Runs as a service using WinDivert to capture and reinject packets in user space.

```text
# Run with the standard "Russian provider" preset.
goodbyedpi.exe -5

# Or tune manually:
goodbyedpi.exe -p -q -e 2 -f 2 --reverse-frag --frag-by-sni --auto-ttl
```

## References
- <https://github.com/ValdikSS/GoodbyeDPI>
