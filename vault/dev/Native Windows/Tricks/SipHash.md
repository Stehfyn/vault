# SipHash

SipHash is a small keyed hash designed for hash-table hardening against collision-flooding attacks. Its point is not cryptographic storage; it is making attacker-chosen keys unpredictable to bucket placement by seeding the hash with a per-process secret.

Keep this as a defensive runtime primitive. It connects to Native Windows code wherever a server, parser, IPC broker, or GUI app stores untrusted strings in hash maps and cannot let one hostile input set degrade lookup to pathological behavior.

Code contribution: wire a per-process secret key into the `SipHash` call used by hash-map buckets for untrusted strings, IPC names, or parsed protocol keys.

## References
- <https://github.com/veorq/SipHash?tab=readme-ov-file>
