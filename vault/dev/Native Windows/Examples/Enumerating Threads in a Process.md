Use `CreateToolhelp32Snapshot` with `TH32CS_SNAPTHREAD` to get a snapshot of all threads system-wide, then iterate with `Thread32First`/`Thread32Next`, filtering on `th32OwnerProcessID` to isolate threads belonging to a specific process.

```cpp
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

void EnumProcessThreads(DWORD dwPID)
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hSnap == INVALID_HANDLE_VALUE)
        return;

    THREADENTRY32 te;
    te.dwSize = sizeof(te);

    if (Thread32First(hSnap, &te))
    {
        do
        {
            if (te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32OwnerProcessID)
                             + sizeof(te.th32OwnerProcessID))
            {
                if (te.th32OwnerProcessID == dwPID)
                    printf("Thread 0x%04x\n", te.th32ThreadID);
            }
            te.dwSize = sizeof(te);
        }
        while (Thread32Next(hSnap, &te));
    }

    CloseHandle(hSnap);
}
```

## References
- https://devblogs.microsoft.com/oldnewthing/20060223-14/?p=32173
