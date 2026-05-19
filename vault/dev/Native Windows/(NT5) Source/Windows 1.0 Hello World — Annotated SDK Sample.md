# Windows 1.0 Hello World - Annotated SDK Sample

The annotated Windows 1.0 sample matters because it shows the original shape of the programming model before Win32 cleaned up the calling conventions and headers: class registration, exported window procedures, `WinMain`, message loops, resource conventions, and cooperative UI assumptions. The surprising part is continuity. A modern minimal Win32 app still registers a class, creates a window, dispatches messages, and delegates default behavior to the system.

Read it as lineage, not nostalgia. Many odd Win32 names and contracts make more sense once seen as preserved compatibility layers from Win16: `hInstance`, class atoms, system metrics, message constants, and the strict separation between app code and the default window procedure.

## Connections
- `Winuser Header` is the modern public surface descended from this model.
- `WOW Message Dispatching` shows how NT carried Win16 compatibility forward.

## References
- <https://github.com/NCommander/win1-hello-world-annotations>
