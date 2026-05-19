# Anti-Debug Check Catalog

This catalog is best treated as a taxonomy of observable anti-analysis signals, not as durable protection. It groups the standard checks: debug-port/process queries, PEB flags, heap-debug metadata, hardware breakpoint registers, hidden-thread tricks, timing skew, and debugger-window/process fingerprints.

The defensive value is mapping each check to where it can be observed or neutralized. API-level checks are easy to shim, direct PEB reads survive naive hooks, hardware-register checks require thread-context visibility, and timing checks create noisy false positives under virtualization. Connect this to `Anti-Tamper Anti-Debug Library`, `Windows Kernel Exploitation Resources`, and ETW/debugger notes when building lab detections.

## References
- <https://github.com/BaumFX/cpp-anti-debug>
