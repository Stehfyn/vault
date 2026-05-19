<!-- generated-from-dump2 -->
# STrace — DTrace on Windows

Mandiant's reimplementation of Solaris/Linux **DTrace** for Windows, layered on top of Microsoft's `dtrace.sys` (which Microsoft shipped in 2018 but exposed via a small, awkward command-line tool). STrace adds the parts you actually want: scriptable probe definitions in a more useful DSL, programmable plugin DLLs that can be invoked at syscall enter/exit and at arbitrary kernel function probes, and full output streaming. The high-value capability is doing syscall-level instrumentation without writing a kernel driver — `dtrace.sys` is the gatekeeper, STrace is the toolchain on top. Useful for malware analysis (see what syscalls a suspicious process is hitting) and root-cause debugging that's currently driver-territory on Windows.

```text
# STrace script flavor (real DSL is similar in spirit to dtrace.d):
#
#   probe syscall::NtCreateFile:entry
#       /arg2 != 0/                          // FILE_OBJECT name pointer non-null
#       {
#           printf("%lu: %ws", pid(), wstring(arg2));
#       }
#
# Loaded as a plugin DLL (C++) so you can do arbitrary work in the probe:
#   extern "C" __declspec(dllexport)
#   void StpCallbackEntry(unsigned long syscallId, unsigned long argCount,
#                         ULONG_PTR* args, char* /*name*/) {
#       if (syscallId == g_NtCreateFile) {
#           // walk OBJECT_ATTRIBUTES->ObjectName, log, etc.
#       }
#   }
```

## References
- <https://github.com/mandiant/STrace>
