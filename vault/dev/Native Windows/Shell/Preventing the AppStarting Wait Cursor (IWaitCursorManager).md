# Preventing the AppStarting Wait Cursor (IWaitCursorManager)

When a host invokes a shell context-menu verb (`IContextMenu::QueryContextMenu` /
`InvokeCommand`), the shell can flip the cursor to **AppStarting** (the spinning
"busy" pointer). It can be suppressed by handing the context-menu object a **site**
that vends a do-nothing `IWaitCursorManager`.

## Interface (undocumented)

- **IID `IWaitCursorManager`**: `{fc992f1f-debb-4596-b355-50c7a6dd1222}`
- Queried as a **service** through `IServiceProvider::QueryService` using the same GUID
  as the service id (SID == IID here).
- Vtable after `IUnknown` (3 methods):
  - `HRESULT Start(CURSORID id)`
  - `HRESULT Restore()`
  - `HRESULT Stop(CURSORID id)`
- `enum CURSORID { CID_WAIT = 0, CID_APPSTARTING = 1 }`

## Mechanism

1. Build a **site** object implementing `IServiceProvider` **and** `IWaitCursorManager`.
2. In `QueryService`, when asked for `IWaitCursorManager`'s GUID, return `this` (the
   do-nothing impl). Every `IWaitCursorManager` method just `return S_OK;`.
3. Attach the site to the context-menu object via `IObjectWithSite::SetSite(site)`
   **before** invoking it. With no real cursor manager doing work, no AppStarting
   cursor appears.

```csharp
[Guid("fc992f1f-debb-4596-b355-50c7a6dd1222")]
interface IWaitCursorManager { HRESULT Start(CURSORID id); HRESULT Restore(); HRESULT Stop(CURSORID id); }
enum CURSORID { CID_WAIT = 0, CID_APPSTARTING = 1 }

class MySite : IServiceProvider, IWaitCursorManager {
    HRESULT QueryService(Guid sid, Guid iid, out object o) {
        if (iid == typeof(IWaitCursorManager).Guid) { o = this; return 0; }
        o = null; return E_NOINTERFACE;
    }
    HRESULT Start(CURSORID id) => 0;
    HRESULT Restore() => 0;
    HRESULT Stop(CURSORID id) => 0;
}

var ows = (IObjectWithSite)contextMenu;
ows.SetSite(new MySite());   // do this before QueryContextMenu/InvokeCommand
```

## Caveat (scope)

This is **host-side** suppression: it works when *your* code owns the `IContextMenu`
invocation and sets the site on it. It does **not** cover the AppStarting cursor shown
by **Explorer** when Explorer launches a separate process (double-click / verb) — that
path is Explorer's `WaitForInputIdle`-style cursor, not reachable via your site.

## Sources
- Simon Mourier's blog: https://www.simonmourier.com/blog/How-to-prevent-appstarting-cursor-when-calling-IContextMenu-QueryContextMenu/
- StackOverflow 79851038: https://stackoverflow.com/questions/79851038/how-to-prevent-appstarting-cursor-when-calling-icontextmenuquerycontextmenu

## Connections
- `Shell Shortcuts.md` — shortcut property store / `PKEY_AppUserModel_ID` (taskbar identity).
- `Notification Area (Tray).md` — `RegisterShellHookWindow`, `ITaskbarList3` (the shell-hook / taskbar surface).
