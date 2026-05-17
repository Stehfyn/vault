# Process Dump Tools

MiniDump APIs (`MiniDumpWriteDump`) write structured crash dumps for post-mortem debugging. The dump type controls what's included: `MiniDumpWithFullMemory` captures all readable memory; `MiniDumpNormal` captures just the stack frames needed for basic analysis.

```cpp
// Write a full memory minidump of a target process
HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetPid);
HANDLE hFile = CreateFileW(L"dump.dmp", GENERIC_WRITE, 0, nullptr,
    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
MINIDUMP_TYPE type = (MINIDUMP_TYPE)(MiniDumpWithFullMemory |
    MiniDumpWithHandleData | MiniDumpWithUnloadedModules);
MiniDumpWriteDump(hProcess, targetPid, hFile, type, nullptr, nullptr, nullptr);
CloseHandle(hFile);
CloseHandle(hProcess);
```

## References
- https://github.com/qi7chen/calmdump
