<!-- generated-from-dump2 -->
# fping — Parallel ICMP Sweep

Replacement for `ping` that runs a parallel sweep across an arbitrary number of hosts: `fping -g 10.0.0.0/24` pings every address in a subnet at once and reports per-host RTT in a single table. Useful for quickly mapping reachable hosts on a LAN or running periodic availability checks from a monitoring script. Implementation is one raw ICMP socket + a state machine; sequence-number-keyed match of replies to outstanding pings.

```text
# Sweep an entire /24 and show per-host RTT:
$ fping -g 10.0.0.0/24 -r 1
10.0.0.1 is alive  (0.5 ms)
10.0.0.2 is alive  (0.8 ms)
10.0.0.7 is unreachable
...

# Continuous mode (re-run every interval, used by monitoring scripts):
$ fping -l -p 1000 host1 host2 host3
host1 : [0], 84 bytes, 0.30 ms (0.30 avg, 0% loss)
host2 : [0], 84 bytes, 0.42 ms (0.42 avg, 0% loss)
...
```

## References
- <https://github.com/schweikert/fping>
