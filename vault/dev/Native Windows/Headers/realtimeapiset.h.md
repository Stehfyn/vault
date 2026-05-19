# realtimeapiset.h

The Windows 8.1+ "precise" timing surface. `QueryInterruptTime` / `QueryUnbiasedInterruptTime` (and their `Precise` variants on Win8.1+) return the OS interrupt clock -- KeQueryInterruptTime under the hood -- at 100 ns resolution; the `Precise` versions promise sub-tick accuracy by synchronizing against the hardware counter without paying the cost of a full `QueryPerformanceCounter` round-trip. `QueryUnbiasedInterruptTime*` is the right call for measuring elapsed wall time across sleep/connected-standby -- it does not advance while the machine is in S0ix/Modern Standby, whereas `GetTickCount64` does, which is a frequent source of subtle bugs in alarm / scheduling code on laptops. Cluster: `profileapi.h` (`QueryPerformanceCounter`), `sysinfoapi.h` (`GetSystemTimePreciseAsFileTime`).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/realtimeapiset/>
- <https://learn.microsoft.com/en-us/windows/win32/sysinfo/acquiring-high-resolution-time-stamps>
