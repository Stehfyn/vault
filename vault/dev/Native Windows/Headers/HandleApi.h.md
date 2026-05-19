# HandleApi.h

The handle-lifetime corner of `kernel32`: `CloseHandle`, `DuplicateHandle`, `GetHandleInformation`, `SetHandleInformation`, `CompareObjectHandles` (Win10+). `DuplicateHandle` is more interesting than it looks -- it can target a different process (you must have `PROCESS_DUP_HANDLE` on both ends), can drop or add access rights, and is the supported way to give a child process a specific handle without making every inheritable handle inheritable. `CompareObjectHandles` is the one and only way to ask "do these two HANDLEs refer to the same kernel object?" -- every other approach (kernel-object-pointer comparison via NtQuerySystemInformation, etc.) is unsupported. `HANDLE_FLAG_PROTECT_FROM_CLOSE` is a trap door: turn it on with `SetHandleInformation` and `CloseHandle` will succeed but the handle stays open, which produces some delightfully confusing leak hunts in production code that flips it accidentally.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/handleapi/>
