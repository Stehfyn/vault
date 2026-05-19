# ActivityCoordinator.h

WinRT activity-coordinator surface -- `IActivityCoordinator` and related interfaces that arbitrate background-task scheduling for modern app activities. The OS uses it to decide whether to allow a `BackgroundTask` to run "now" or to defer it under power throttling / Modern Standby / connected standby constraints; apps almost never instantiate it themselves. Tightly coupled to `applicationstatecontract`, `BackgroundTaskBuilder`, the Resource Manager, and the `Microsoft.System.DispatcherQueue` energy hints. Practically: this is a header you find by including `<inspectable.h>`-style WinRT-internal projection files and then never touch again.

## References
- <https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.background>
