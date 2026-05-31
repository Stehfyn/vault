# Yosifovich System Programming Samples

Pavel Yosifovich's sample code for "Windows 10 System Programming" (Vol 1 and 2). Covers practical examples for jobs/silos, sessions, processes/tokens/SIDs, thread pools, kernel objects + handles, the new `BCryptResolveProviders` style, ETW consumer/producer, AppContainer, RPC and ALPC, structured exception handling for SEH-on-x64, and miscellanea like ETW/TraceLogging providers. If you ever want a working, minimal demo of something you read about in MS Press, this is usually where to look.

```text
# Layout (abridged)
Chapter01-Foundations/
Chapter05-Jobs/           # CreateJobObject, JOBOBJECT_BASIC_LIMIT_INFORMATION, SiloName
Chapter06-Threads/        # CreateThread variants, fibers, UMS, thread pool
Chapter07-Synchronization/# CRITICAL_SECTION vs SRWLock vs CV
Chapter09-Memory/         # VirtualAlloc, AWE, large pages, MEM_REPLACE_PLACEHOLDER
Chapter12-IPC/            # named pipes, mailslots, ALPC sketches
```

## Diagnostics Route

The samples are a bridge between isolated API learning and the observability notes in this folder. Treat the ETW and TraceLogging examples as producer-side companions to krabsetw, Sealighter, wtrace, and ProcMonXv2.

```cpp
// TraceLogging-style producer shape from the Windows system-programming family.
#include <TraceLoggingProvider.h>

TRACELOGGING_DEFINE_PROVIDER(
    g_provider,
    "NativeWindows.Sample",
    (0x01234567, 0x89ab, 0xcdef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef));

TraceLoggingRegister(g_provider);
TraceLoggingWrite(g_provider, "WorkerState",
    TraceLoggingUInt32(GetCurrentProcessId(), "PID"),
    TraceLoggingWideString(L"Running", "State"));
TraceLoggingUnregister(g_provider);
```

```text
learning route:
  threads/thread pools -> service worker lifetime
  handles/tokens/SIDs -> NanaRun and service identity
  IPC/named pipes/ALPC -> NpEtw and ProcMon-style observation
  ETW/TraceLogging -> EventWrite, krabsetw, Sealighter, UIforETW
```

## References
- <https://github.com/zodiacon/Win10SysProgBookSamples>
