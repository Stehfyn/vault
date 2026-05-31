# Shell COM WinRT UI Connection Routes

This is the cross-topic map for notes where Shell, COM, WinRT, and UI frameworks overlap. Use it to decide where a new source belongs before expanding a local note.

## Overarching Routes

1. Shell namespace route: `Known Folders.md` -> `Shell Items and Folders.md` -> `Windows Explorer Integration.md` -> `Explorer++ (Tabbed Win32 Explorer).md`. This route starts with stable folder identity, moves through `IShellItem`/PIDL objects, then reaches Explorer windows, context menus, drag/drop, and replacement file managers.

2. COM ABI route: `../(COM) Component Object Model/COM in plain C.md` -> `../(COM) Component Object Model/basetyps.h - COM IDL Typedefs.md` -> `../(WinRT) Windows Runtime/WinRT is fundamentally COM.md`. This is the vtable, `IUnknown`, `IInspectable`, factory, HRESULT, and lifetime route. When a note says "wrapper", this route explains what is being wrapped.

3. WinRT activation route: `../(WinRT) Windows Runtime/Consume Windows Runtime APIs from pure C.md` -> `../(WinRT) Windows Runtime/Win32 To WinRT.md` -> `../(WinRT) Windows Runtime/Windows App SDK Bootstrapper.md` -> `../(WinRT) Windows Runtime/WinUI 3 in Pure C (No cppwinrt).md`. This route separates ABI possibility from deployment reality: a class can be callable only after the process has the right apartment, package/runtime binding, metadata, and activation context.

4. HWND hosting route: `../(WTL) Windows Template Library/WTL Examples.md` -> `../(MFC) Microsoft Foundation Classes/MFCStoreClient - MFC to WinRT Store Bridge.md` -> `../(WinRT) Windows Runtime/Xaml Islands Minimal Win32 Host.md` -> `../(WPF) Windows Presenation Format/Aero Theme.md`. This route compares native window frameworks with XAML/WPF retained UI. The key question is who owns input, focus, DPI, rendering, and object lifetime.

5. Packaged identity route: `../(WinRT) Windows Runtime/Sandboxing Win32 Apps via MSIX.md` -> `../(WinRT) Windows Runtime/Windows App SDK Feature Samples.md` -> `../Game Bar/XboxGameBarSamples - Widget Reference Code.md` -> `../Game Bar/Game Bar Presence Writer.md`. This route explains why modern shell/game surfaces care about AUMIDs, manifests, app extensions, package identity, and brokered activation rather than only HWNDs and EXEs.

6. Runtime patching route: `Explorer Patcher (Win11 Shell Restore).md` -> `DUI70 - Shell DirectUI Framework.md` -> `../libvalinet - ExplorerPatcher Helpers.md`. This route is unsupported but high-signal: private shell UI, version-keyed offsets, import patching, injected helpers, and rollback behavior.

## Editorial Rule

Prefer a source-derived call shape over a paragraph when the source exposes one. Keep prose for the decision point: what the sample proves, what it does not prove, and which neighboring note should be read next.

## Experiment Harness Matrix

Use these as small probes before writing a larger app. Each probe should print HRESULTs, pointer/handle values, elapsed time, and the Windows build number.

| Route | Harness | Measured signal | Failure interpretation |
|---|---|---|---|
| COM ABI | Query two interfaces, query both back to `IUnknown`, compare controlling-unknown pointers. | same `IUnknown`, stable `E_NOINTERFACE`, balanced debug refcount | Wrapper confusion, aggregation bug, wrong IID, or not the same object instance |
| Shell namespace | Create `IShellItem` from path, known folder, and dialog result; print `SIGDN_FILESYSPATH` and `SIGDN_DESKTOPABSOLUTEPARSING`. | filesystem paths only for filesystem-backed objects; parsing names survive more cases | Treating shell identity as only a path |
| WinRT activation | `RoInitialize` -> `RoGetActivationFactory` for one OS class and one WinAppSDK class, before/after bootstrapper. | OS class activates without WinAppSDK; `Microsoft.UI.*` needs runtime/package graph | Missing runtime, wrong apartment, wrong class name, or no framework dependency |
| HWND hosting | Attach `DesktopWindowXamlSource`, print parent HWND, island HWND, focus state, resize deltas. | child HWND exists, resizes with parent, expected keys are consumed | Wrong thread/top-level window, missing XAML initialization, bad focus routing |
| Game Bar identity | Inspect manifest extensions, launch activation args, AUMID/package family name. | widget appears only when package identity and extension are correct | Plain EXE/window is not a widget; discovery is manifest/package-driven |
| Runtime patching | Dry-run PE/import/signature scan, no writes; log module version and match offsets. | exact module version plus unique matches | Build drift or ambiguous signatures; do not patch until deterministic |

Primary Microsoft anchors: [COM `QueryInterface` rules](https://learn.microsoft.com/en-us/windows/win32/com/rules-for-implementing-queryinterface), [Shell drag/drop data objects](https://learn.microsoft.com/windows/win32/shell/dragdrop), [DesktopWindowXamlSource](https://learn.microsoft.com/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.hosting.desktopwindowxamlsource), [Windows App SDK bootstrapper](https://learn.microsoft.com/windows/windows-app-sdk/api/win32/mddbootstrap/nf-mddbootstrap-mddbootstrapinitialize), and [Game Bar widget overview](https://learn.microsoft.com/gaming/game-bar/overview).
