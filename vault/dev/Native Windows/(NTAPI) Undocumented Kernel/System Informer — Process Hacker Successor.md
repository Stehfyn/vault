# System Informer - Process Hacker Successor

System Informer is one of the strongest open-source references for serious Windows inspection tooling. It combines native process/thread/module/handle enumeration, service and driver views, token and object-manager inspection, GUI tooling, and an optional kernel component. It is also the living validation target for phnt headers.

The repository matters because it shows engineering around undocumented APIs rather than isolated snippets: version checks, fallback paths, privilege handling, symbol use, driver/user separation, and UI presentation. When a native structure appears in phnt, System Informer often shows how it is used safely enough for a real tool.

## Connections
- `phnt` is the header foundation.
- `Task Manager Source` is the historical lightweight ancestor of this process-inspection style.
- `Process Dump Tools` and `ProcessSnapshot.h` cover adjacent diagnostic workflows.

## References
- <https://github.com/winsiderss/systeminformer>
