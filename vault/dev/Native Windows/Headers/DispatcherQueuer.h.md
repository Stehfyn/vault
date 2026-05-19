# DispatcherQueuer.h

Misspelt include for `DispatcherQueue.h` (the canonical SDK name has no trailing "r"). Declares `CreateDispatcherQueueController` and the COM ABI for `IDispatcherQueueController` / `IDispatcherQueue`, the WinRT message-loop primitive used by `Microsoft.UI.Composition`, `Microsoft.UI.Xaml.Window`, and the Windows.System dispatcher queue API. Host one on any thread you want to drive Composition islands, XAML, or input from -- `CoreDispatcher` is the legacy CoreWindow-bound variant, `DispatcherQueue` is the modern free-threaded one. Ships in Windows 10 1709+ via `coremessaging.dll`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dispatcherqueue/>
- <https://learn.microsoft.com/en-us/uwp/api/windows.system.dispatcherqueue>
