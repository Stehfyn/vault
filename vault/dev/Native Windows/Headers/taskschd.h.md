# taskschd.h

Task Scheduler 2.0 COM API, introduced in Vista, hosted by `taskschd.dll` and the `Schedule` service (`schedsvc`). Five-level object hierarchy: `ITaskService` (root, you `Connect` it) -> `ITaskFolder` (XML-named subfolders under `\`) -> `IRegisteredTask` (an installed task) -> `ITaskDefinition` (its schema) -> `ITrigger` / `IAction` collections. Replaces the brittle 1.0 `ITaskScheduler` from `mstask.h`; the on-disk format is also wholly different (per-task XML files under `%windir%\System32\Tasks\...` versus the old `.job` binary blobs). Beware that registering an `IExecAction` task that runs as `S-1-5-18` (LOCAL_SYSTEM) with `TASK_LOGON_SERVICE_ACCOUNT` is a routine UAC-bypass primitive -- Microsoft has tightened the surface several times.

## References
- <https://learn.microsoft.com/en-us/windows/win32/taskschd/task-scheduler-start-page>
