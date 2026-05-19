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

## References
- <https://github.com/zodiacon/Win10SysProgBookSamples>
