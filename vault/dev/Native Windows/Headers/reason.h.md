# reason.h

Defines the `SHTDN_REASON_MAJOR_*` / `SHTDN_REASON_MINOR_*` bit-flag constants that `InitiateSystemShutdownExW`, `ExitWindowsEx`, and the shutdown event tracker dialog all expect. The reason is a packed DWORD: high bits are flags (`SHTDN_REASON_FLAG_USER_DEFINED`, `SHTDN_REASON_FLAG_PLANNED`, `SHTDN_REASON_FLAG_CLEAN_UI`), then a 16-bit major category (`APPLICATION`, `HARDWARE`, `OPERATINGSYSTEM`, `POWER`, `SOFTWARE`, `SYSTEM`), then a 16-bit minor category (`HUNG`, `BLUESCREEN`, `INSTALLATION`, `MAINTENANCE`, etc.). The shutdown event tracker (server SKUs and joined workstations) consults these codes to decide whether to display the "why are you shutting down" dialog and what entries to show. Pair with `winuser.h`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/shutdown/system-shutdown-reason-codes>
