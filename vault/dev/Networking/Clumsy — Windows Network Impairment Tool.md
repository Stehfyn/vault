<!-- generated-from-dump2 -->
# Clumsy — Windows Network Impairment Tool

Windows-only network impairment tool that injects realistic flaws into your local traffic: drop, lag, throttle, duplicate, reorder, corrupt, set bandwidth caps, and tag with a BPF-style filter so you can apply impairment to only one process / port / direction. The interesting bit is *how* it works: built on **WinDivert**, a user-mode packet-interception driver that hooks the Windows TCP/IP stack's WFP (Windows Filtering Platform) callouts — so packets are diverted to clumsy in user mode, mangled, and re-injected, all without rewriting your application. Indispensable for QA-testing voice/video/game code against the kind of WAN behaviour you can't easily reproduce on a healthy LAN.

```text
# WinDivert filter language is BPF-flavored. Examples used in clumsy:
#   outbound and tcp.DstPort == 443           -> only HTTPS uploads
#   inbound and udp                            -> all incoming UDP
#   ip.SrcAddr == 8.8.8.8 or ip.DstAddr == 8.8.8.8
#
# Effects you can stack live:
#   Lag         (ms delay; queue up packets and release after delay)
#   Drop        (probabilistic packet drop)
#   Throttle    (bandwidth cap per direction)
#   Duplicate   (re-emit same packet to test idempotency)
#   Out of order (intentionally permute queue)
#   Tamper      (flip random bytes - useful for codecs / checksums)
```

## References
- <https://github.com/jagt/clumsy>
