# MSTask.h

The original NT-4-era Task Scheduler 1.0 COM API (`ITaskScheduler`, `ITask`, `IScheduledWorkItem`), hosted by `mstask.dll` and persisted as binary `.job` files under `%windir%\Tasks`. Superseded by Task Scheduler 2.0 (`taskschd.h`) in Vista, and the `.job` format has been read-only since Windows 8 -- `Schtasks /Create` and `ITaskService::NewTask` produce only the new XML format. Almost everything you can do here you can do better through `taskschd.h`, but the v1 API still binds against tasks created on legacy systems and is occasionally what you see when binary-spelunking very old NT4 / Win2000 / XP tooling.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/mstask/>
