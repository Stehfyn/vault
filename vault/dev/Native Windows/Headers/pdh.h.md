# pdh.h

Performance Data Helper -- the user-mode API in `pdh.dll` for consuming Windows Performance Counters (the perfmon.exe data model). Opens a query (`PdhOpenQueryW`), adds counters by their localized or English path (`PdhAddCounterW` for the current locale; `PdhAddEnglishCounterW` to dodge the localization landmine), collects (`PdhCollectQueryData`), and reads typed values (`PdhGetFormattedCounterValue`). For rate counters (`% Processor Time`, `Disk Bytes/sec`) you must collect twice with a delay between, because the counter type encodes a delta and PDH needs two samples to compute it. Modern alternatives are the Win32 `PerfLib v2` API (`PerfQueryCounterSetRegistrationInfo`) and ETW's counter event flow -- but PDH is still the path of least resistance for "give me CPU % right now."

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/pdh/>
- <https://learn.microsoft.com/en-us/windows/win32/perfctrs/using-the-pdh-functions-to-consume-counter-data>
