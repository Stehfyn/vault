# Story Routes

Use this page as a triage checklist and implementation backlog. For any Native Windows note, ask four concrete questions before adding prose:

- What object or context has to be valid first: `HWND`, thread DPI context, COM apartment, package graph, adapter `LUID`, process handle, service handle, ETW session, device handle?
- Which API proves that state: `GetWindowLongPtr`, `DwmDefWindowProc`, `QueryInterface`, `RoGetActivationFactory`, `IDXGIAdapter::GetDesc`, `OpenProcess`, `QueryServiceStatusEx`, `ProcessTrace`, `DeviceIoControl`?
- What breaks if you pick the wrong layer: no Snap, wrong hit-test coordinates, cross-adapter copy, missing WinRT class, CRT heap corruption, hidden service state, dropped ETW events, unsafe IOCTL access?
- What is the smallest code probe that proves or falsifies the note?

## Editorial Standard: Claims Become Probes

Forum threads, issue comments, Reddit discussions, and old blog comments are not weak sources by default. They are often where the real claim appears: "this accessor is expensive," "DWM owns that timing," "the hook DLL will not unload yet," "WinRT is just COM," "this capture path cannot see protected content." Do not paraphrase those claims as lore. Convert them into a verification route.

Use this shape when a discussion makes a claim worth preserving:

```text
Claim: the assertion from the discussion, stated narrowly.
Why it matters: the code decision it changes.
Verify: source file, disassembly range, ETW/WPA trace, WinDbg break, Spy++ route, or small probe.
Snippet: the smallest code/pseudocode that exercises the claim.
Interpret: what confirms it, what falsifies it, and which Windows build/tool version was observed.
```

Prefer claims that can be independently checked. Good enhancements name exact functions, structs, offsets, events, flags, symbols, build switches, HRESULTs, `NTSTATUS` values, or command lines. If the linked source does not support the note's claim, say so explicitly and narrow the claim rather than padding the article with summary.

## 1. A Window Is Behavior Before It Is Appearance

Do not start with colors, glass, or rounded corners. Start with the mechanical contract that makes a window behave like a window: `HWND`, class procedure, default processing, DPI context, and DWM delegation. Microsoft documents message routing and window procedures as the behavioral substrate: a message carries the target window handle and is dispatched to a window procedure, while nonqueued messages can bypass the thread queue entirely ([About Messages and Message Queues](https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues), [About Window Procedures](https://learn.microsoft.com/en-us/windows/win32/winmsg/about-window-procedures)).

Custom chrome works only when it respects the split. USER32 asks for client/non-client geometry with `WM_NCCALCSIZE`; DWM owns enough of the modern non-client surface that custom frames should first offer hit-test and caption-button messages to `DwmDefWindowProc`; DPI awareness can be bound to the window's creation context, with per-monitor behavior changing coordinate interpretation ([WM_NCCALCSIZE](https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-nccalcsize), [DwmDefWindowProc](https://learn.microsoft.com/en-us/windows/win32/api/dwmapi/nf-dwmapi-dwmdefwindowproc), [Custom Window Frame Using DWM](https://learn.microsoft.com/en-us/windows/win32/dwm/customframe), [High DPI improvements](https://learn.microsoft.com/en-us/windows/win32/hidpi/high-dpi-improvements-for-desktop-applications)).

Actionable nibbles:
- If a custom titlebar does not resize or Snap correctly, inspect `WM_NCCALCSIZE`, `WM_NCHITTEST`, `WS_THICKFRAME`, and `SWP_FRAMECHANGED` before touching paint code.
- If caption buttons stop working, call `DwmDefWindowProc` first for non-client hit-test messages, then fall back to your own hit testing or `DefWindowProc`.
- If hit-test rectangles drift between monitors, trace the window's creation DPI context and the thread DPI context used during the window procedure.
- If a control looks correct but sends no useful notifications, inspect the parent `WM_NOTIFY`/`WM_COMMAND` route; drawing and command routing are separate.

Code to write next:
- `hwnd_contract_probe.cpp`: create one normal window and one borderless window; log `WM_NCCALCSIZE`, `WM_NCHITTEST`, `WM_GETMINMAXINFO`, `WM_DPICHANGED`, and whether `DwmDefWindowProc` handled each non-client message.
- `dpi_hit_test_grid.cpp`: draw the computed resize/caption rectangles over the client area and move the window between monitors; expose where logical and physical coordinates diverge.
- `control_notify_spy.cpp`: subclass a `ListView`/toolbar parent and print every `WM_COMMAND`/`WM_NOTIFY` with sender HWND, ID, and notification code.

Route through the vault: `Message Queue/` -> `Common Controls/Window Messaging.md` -> `DPI Awareness/` -> `Common Controls/Borderless Window.md` -> `Custom Frame/` -> `(DWM) Desktop Window Manager/Title Bar Customization.md`.

## 2. Pixels Have Several Owners

Before choosing a rendering or capture API, answer: am I selecting a GPU/output, presenting buffers, arranging visuals, reading the composed desktop, reading a window, or measuring timing? Those are different decisions. DXGI names adapters/outputs and swap chains. DirectComposition arranges retained visuals. DWM composes the desktop. Capture APIs observe different images. Timing APIs expose different clocks.

The public documentation supports that separation. DXGI enumerates adapters and outputs and handles presentation concerns ([DXGI overview](https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi)); `CreateSwapChainForComposition` hands Direct3D content into DirectComposition/XAML/WinUI composition ([IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition)); DirectComposition composes bitmaps into a retained visual tree that DWM consumes ([DirectComposition basic concepts](https://learn.microsoft.com/en-us/windows/win32/directcomp/basic-concepts), [IDCompositionVisual::SetContent](https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-idcompositionvisual-setcontent)); DWM redirects windows to off-screen surfaces and composes the desktop ([Desktop Window Manager](https://learn.microsoft.com/en-us/windows/win32/dwm/dwm-overview)).

Capture is where wrong assumptions become obvious. GDI capture, DXGI desktop duplication, Windows Graphics Capture, and private DWM redirection-surface tricks are not interchangeable. Desktop Duplication returns updates to the composed desktop image as a DXGI surface, scoped by output; Windows Graphics Capture uses a user-consented `GraphicsCaptureItem` and frame pool; private DWM capture is reverse-engineered and not first-party documented ([Desktop Duplication API](https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/desktop-dup-api), [IDXGIOutput1::DuplicateOutput](https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-duplicateoutput), [Screen capture](https://learn.microsoft.com/en-us/windows/uwp/audio-video-camera/screen-capture)).

Actionable nibbles:
- If `OpenSharedResource` fails, compare adapter `LUID`s before debugging texture formats.
- If capture misses occluded windows, distinguish final-desktop capture from per-window redirection-surface capture.
- If a window capture API blacks out protected content, stop treating it as a bug in your copy path; the compositor/content-protection layer may be the answer.
- If frame pacing looks wrong, compare `IDXGISwapChain::Present` sync behavior with DWM timing counters; they are related evidence, not the same clock ([IDXGISwapChain::Present](https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present), [DWM_TIMING_INFO](https://learn.microsoft.com/en-us/windows/win32/api/dwmapi/ns-dwmapi-dwm_timing_info)).
- If GL/D3D/DComp interop flickers or copies unexpectedly, verify the adapter and shared-resource route before profiling shaders.

Code to write next:
- `adapter_luid_probe.cpp`: enumerate DXGI adapters/outputs, create D3D/DComp devices, and print every `LUID`/output pair used by render, composition, and capture code.
- `capture_matrix.cpp`: capture the same target through GDI, DXGI Desktop Duplication, Windows Graphics Capture, and any private DWM path already in the vault; record occlusion/protection/latency differences in one table.
- `present_timing_logger.cpp`: call `Present`, `DwmGetCompositionTimingInfo`, and QPC around frames; write CSV rows for sync interval, present count, missed frames, and observed frame duration.

Route through the vault: `(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` -> `(DX) DirectX/Windows Composition Engine.md` -> `(DWM) Desktop Window Manager/DWM Internals Documentation.md` -> `(DX) DirectX/DXGI Output Duplication Capture.md` -> `(DWM) Desktop Window Manager/VBlank Wait.md`.

## 3. Modern Windows Is COM Plus Identity, Not a Replacement for Win32

When a modern Windows API fails, do not ask only "is this Win32 or WinRT?" Ask which identity is missing: COM object identity, activation factory, package graph, app identity, HWND host, or apartment/threading setup.

COM identity is explicit: `QueryInterface(IID_IUnknown)` must return a stable identity pointer for a COM object ([Rules for Implementing QueryInterface](https://learn.microsoft.com/en-us/windows/win32/com/rules-for-implementing-queryinterface)). Shell modernization stays on that substrate: `IShellItem` inherits from `IUnknown`, and the Common Item Dialog uses COM creation and shell items rather than inventing a new object system ([IShellItem](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nn-shobjidl_core-ishellitem), [Common Item Dialog](https://learn.microsoft.com/en-us/windows/win32/shell/common-file-dialog)).

WinRT looks different mostly because projections hide the ABI. Microsoft states C++/WinRT is a projection over Windows Runtime, and `IInspectable` still inherits from `IUnknown`; activation is factory-based through `IActivationFactory` ([Introduction to C++/WinRT](https://learn.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt), [IInspectable](https://learn.microsoft.com/en-us/windows/win32/api/inspectable/nn-inspectable-iinspectable), [IActivationFactory](https://learn.microsoft.com/en-us/windows/win32/api/activation/nn-activation-iactivationfactory)).

The emerging idea is that app identity is now as important as object identity. Package identity is a concrete tuple, and the package graph controls access to framework packages, DLLs, content, and runtime class declarations; `DesktopWindowXamlSource` shows the other side of the bridge by hosting WinUI/XAML inside HWND-associated desktop UI ([Package identity overview](https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/package-identity-overview), [Framework packages and dynamic dependencies](https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/framework-packages/framework-packages-overview), [DesktopWindowXamlSource](https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.hosting.desktopwindowxamlsource)).

Actionable nibbles:
- If a Shell object comparison is wrong, compare `IUnknown` identity, not wrapper object addresses.
- If a WinRT class cannot be activated, check `RoGetActivationFactory` failure, package graph/runtime binding, and apartment setup before blaming C++/WinRT.
- If a XAML Island renders but input/focus/DPI are broken, debug the HWND host boundary, not the XAML control first.
- If a file picker result behaves unlike a path, keep it as `IShellItem` until the last responsible moment; Shell namespace identity can be richer than filesystem identity.
- If an unpackaged app sees fewer APIs than a packaged app, inspect package identity and dynamic dependencies.

Code to write next:
- `com_identity_probe.cpp`: request multiple interfaces from the same object, compare `IUnknown` pointers, and print wrapper pointer versus identity pointer.
- `winrt_activation_probe.c`: call `RoGetActivationFactory` for a small set of WinRT/WinAppSDK classes before and after bootstrap/runtime binding; print HRESULTs and activation class names.
- `xaml_island_host_probe.cpp`: host one XAML island in a Win32 child HWND and log focus, DPI, size, and message routing transitions at the host boundary.
- `shell_item_probe.cpp`: open a file dialog, keep the result as `IShellItem`, and print `SIGDN_*` names plus selected property keys before converting to a path.

Route through the vault: `Shell/Shell COM WinRT UI Connection Routes.md` -> `(COM) Component Object Model/COM in plain C.md` -> `(WinRT) Windows Runtime/WinRT is fundamentally COM.md` -> `(WinRT) Windows Runtime/Windows App SDK Bootstrapper.md` -> `(WinRT) Windows Runtime/Xaml Islands Minimal Win32 Host.md`.

## 4. Compatibility Is a Pipeline, Not a Switch

Compatibility starts before runtime and fails in layers. `WINVER`, `_WIN32_WINNT`, and `sdkddkver.h` decide which declarations appear at compile time; PE metadata and imports decide loader-facing shape; DLL search order decides what module is actually loaded; CRT linkage decides ownership of heap/state across DLL boundaries ([Update WINVER and _WIN32_WINNT](https://learn.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=msvc-170), [PE Format](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format), [Dynamic-link library search order](https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order), [/MD, /MT, /LD](https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170)).

The CRT boundary is one of the easiest to miss and one of the most expensive to debug. Microsoft warns that separate CRT copies have separate state and heaps; passing CRT objects or allocated memory across incompatible boundaries can corrupt state or fail unpredictably ([Potential errors passing CRT objects across DLL boundaries](https://learn.microsoft.com/en-us/cpp/c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries?view=msvc-170)).

Installer and package metadata add another layer. MSI `AppSearch` derives properties from files, registry entries, directories, and INI data; MSIX gives desktop apps package identity and changes file/registry assumptions; Package Support Framework applies runtime fixups without changing source; classic AppCompat fixes intercept APIs to emulate older behavior ([AppSearch Table](https://learn.microsoft.com/en-us/windows/win32/msi/appsearch-table), [Packaged desktop apps behind the scenes](https://learn.microsoft.com/en-us/windows/msix/desktop/desktop-to-uwp-behind-the-scenes), [Package Support Framework](https://learn.microsoft.com/en-us/windows/msix/psf/package-support-framework), [Custom compatibility fix](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/deployment/compatibility/creating-a-custom-compatibility-fix-in-compatibility-administrator)).

Caveat: the native API layer is only partly documentable. `RTL_USER_PROCESS_PARAMETERS` is first-party documented only in reserved/fractured form, and `NtCreateUserProcess` is not first-party documented as a stable Win32 API ([RTL_USER_PROCESS_PARAMETERS](https://learn.microsoft.com/en-us/windows/win32/api/Winternl/ns-winternl-rtl_user_process_parameters)).

Actionable nibbles:
- If code does not compile, inspect `_WIN32_WINNT` before searching for missing SDKs.
- If code compiles but fails to launch, inspect imports, API-set resolution, and DLL search order.
- If a DLL API returns memory to the caller, verify the CRT/heap ownership rule before changing allocators.
- If an app works unpackaged but fails packaged, inspect file/registry virtualization, package identity, and PSF fixups.
- If an old app works only with a shim, classify whether the shim changes API return values, paths, version checks, or loader behavior.
- If a note depends on `NtCreateUserProcess`, mark the undocumented part explicitly; first-party docs only cover nearby structures such as `RTL_USER_PROCESS_PARAMETERS`.

Code to write next:
- `compat_import_probe.cpp`: dump `_WIN32_WINNT`, selected header availability macros, import table entries, delay-load entries, and runtime `GetProcAddress` success for the same API set.
- `crt_heap_boundary_probe.cpp`: build `/MD` and `/MT` DLL/EXE pairs and intentionally allocate/free across module boundaries under page heap or Application Verifier.
- `dll_search_order_probe.cpp`: create a controlled executable directory, app directory, and PATH case; print the actual loaded module path for the same DLL name.
- `msix_psf_probe.md`: document a minimal packaged/unpackaged file-write repro, then record which behavior changes under MSIX and PSF fixups.

Route through the vault: `Headers/sdkddkver.h.md` -> `Headers/winnt.h.md` -> `(CRT) C Runtime/CRT Linkage (MD MT DLL).md` -> `(PE) Portable Executable Format/` -> `Windows Installer/` -> `App Compatibility/`.

## 5. Diagnostics Are Planes of Observation

Diagnostics fails when the tool does not match the question. First decide whether you need event history, current service state, management inventory, in-process API arguments, or post-capture timeline analysis.

ETW is the event plane: providers call `EventWrite`; consumers receive `EVENT_RECORD` payloads through trace sessions and decode them through APIs such as TDH; WPR records ETW data and WPA analyzes ETL files ([EventWrite](https://learn.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventwrite), [EVENT_RECORD](https://learn.microsoft.com/en-us/windows/win32/api/relogger/ns-relogger-event_record), [Consuming Events](https://learn.microsoft.com/en-us/windows/win32/etw/consuming-events), [Windows Performance Recorder](https://learn.microsoft.com/en-us/windows-hardware/test/wpt/windows-performance-recorder), [Windows Performance Analyzer](https://learn.microsoft.com/en-us/windows-hardware/test/wpt/windows-performance-analyzer)).

The caveats matter. ETW sessions can lose events when throughput exceeds buffering/flushing capacity, and provider discovery via `tracelog -enumguid` or `logman query providers` is not a complete inventory ([Sessions](https://learn.microsoft.com/en-us/windows-hardware/test/wpt/sessions), [Tracelog Enumguid Display](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/tracelog-enumguid-display)).

SCM and WMI are state/control planes. The Service Control Manager owns the installed-service database and status/control path; `QueryServiceStatusEx` returns the most recent status reported to SCM; WMI's `Win32_Service` gives management inventory and methods across a broader management surface ([Service Control Manager](https://learn.microsoft.com/ga-ie/windows/win32/services/service-control-manager), [QueryServiceStatusEx](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-queryservicestatusex), [Win32_Service](https://learn.microsoft.com/en-us/windows/win32/cimwin32prov/win32-service)).

Actionable nibbles:
- If you need "what happened over time", start with ETW/WPR, not WMI.
- If you need "what is the service state now", ask SCM with `QueryServiceStatusEx`; WMI is useful inventory, not the same authority.
- If provider discovery misses something, do not assume the provider does not exist; Microsoft documents discovery incompleteness.
- If an ETL trace lacks expected events, check lost-event counters before building a theory from absence.
- If you need exact arguments inside one process, use local instrumentation; ETW may show behavior without call-site argument fidelity.

Code to write next:
- `etw_min_provider_consumer.cpp`: emit one manifest-free provider event, consume it live, and print `EVENT_RECORD` header fields plus decoded payload.
- `service_state_probe.cpp`: query the same service through SCM, WMI, and event logs; record where state, PID, start type, and recent transitions disagree.
- `etl_loss_probe.ps1`: start a deliberately undersized ETW session, generate high-rate events, and show lost-event counters so absence is not misread as proof.
- `trace_plane_matrix.md`: for each tool note, record whether it observes provider events, process-local calls, current state, inventory, or post-capture ETL.

Route through the vault: `Tools/Diagnostics Observability Routes.md` -> `(ETW) Event Tracing For Windows/EventWrite.md` -> `(ETW) Event Tracing For Windows/evntcons.h - ETW Consumer Header.md` -> `Services/Win32 Service Template.md` -> `(WMI) Windows Management Instrumentation/WMI C++ Usage.md`.

## 6. OpSec Notes Are Boundary Notes

For OpSec, Tricks, and Esoteric APIs, the useful question is not "is this scary?" It is "which authority check moved?" Process access, page protection, device IOCTL dispatch, driver load policy, package file reach, VSS coordination, and MSDelta buffer ownership are all inspectable contracts.

Process access is a security boundary: process objects have access rights such as VM read/write/operation, duplicate-handle, and protected-process restrictions ([Process Security and Access Rights](https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights)). Memory APIs are protection-boundary APIs: allocation, commit, page protections, executable memory, and instruction-cache coherency are part of the contract ([VirtualAlloc](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc)).

Drivers expose another boundary. `DeviceIoControl` sends control codes through a device handle to a driver, while Microsoft driver guidance treats IOCTL definition and validation as a security problem, not a formatting problem ([DeviceIoControl](https://learn.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), [Security Issues for I/O Control Codes](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/security-issues-for-i-o-control-codes)). Kernel-mode signing and Microsoft recommended driver block rules form the first-party policy layer under BYOVD discussions ([Kernel-Mode Code Signing Requirements](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/kernel-mode-code-signing-requirements--windows-vista-and-later-), [Microsoft recommended driver block rules](https://learn.microsoft.com/en-us/windows/security/application-security/application-control/windows-defender-application-control/design/microsoft-recommended-driver-block-rules)).

Not every case is a security incident. AppContainer-aware file APIs constrain file reach; VSS coordinates consistent snapshots; MSDelta owns source/delta/target buffer contracts and output freeing ([CreateFile2FromAppW](https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-createfile2fromappw), [File access permissions](https://learn.microsoft.com/en-us/windows/apps/develop/files/file-access-permissions), [Volume Shadow Copy Service](https://learn.microsoft.com/en-us/windows-server/storage/file-server/volume-shadow-copy-service), [ApplyDeltaB](https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta-applydeltab)).

Caveat: Microsoft documents the legitimate contracts and policy layers. It does not document arbitrary kernel read/write primitives, `PreviousMode` abuse, PPL bypass chains, anti-cheat driver abuse, or vulnerable-driver exploit procedures. Those notes should stay anchored to the boundary they cross, not to step-by-step exploitation.

Actionable nibbles:
- If a tool reads another process, separate handle rights from page protections: `PROCESS_VM_READ` and executable/writable page state answer different questions.
- If memory access comes through a driver, record device path, driver image, IOCTL value, caller PID, and buffer sizes; that is the useful boundary metadata.
- If a signed driver is involved, do not infer safety from signing alone; compare code-signing policy and driver block rules.
- If AppContainer code reaches a file, inspect capabilities, picker-granted access, package location rules, and `CreateFile2FromAppW` behavior.
- If VSS or MSDelta appears, classify it as snapshot/update coordination first; treat malicious use as a second-layer interpretation.

Code to write next:
- `handle_rights_probe.cpp`: open the same process with escalating rights, print success/failure, and separate access-denied causes from page-protection failures.
- `memory_protection_probe.cpp`: allocate pages with read/write/execute combinations, test `VirtualProtect`, and log when `FlushInstructionCache` is required for generated code.
- `ioctl_metadata_logger.cpp`: for legitimate test devices only, wrap `DeviceIoControl` calls and print device path, control code, input/output sizes, caller PID, and HRESULT.
- `msdelta_roundtrip.cpp`: produce/apply a tiny delta and explicitly show source buffer, delta buffer, target buffer, and `DeltaFree` ownership.

Route through the vault: `OpSec/References.md` -> `OpSec/VirtualAlloc Memory API Header.md` -> `OpSec/Win32 Process Snippet Utilities.md` -> `OpSec/Cheat Driver (IOCTL Memory R W).md` -> `Esoteric APIs/File API From App.md` -> `Tricks/AlphaVSS - .NET Binding for Volume Shadow Copy.md`.

## Editorial Use

When adding a new Native Windows note, write one actionable line before any commentary:

- `HWND/message`: "Check `WM_NCCALCSIZE`, `WM_NCHITTEST`, DPI context, and `DefWindowProc` before paint."
- `COM/identity`: "Check `IUnknown` identity, factory activation, package graph, and apartment before wrapper syntax."
- `graphics`: "Check adapter `LUID`, swap-chain model, visual content, capture point, and timing source."
- `compatibility`: "Check declaration gate, import/load path, CRT ownership, installer search, package identity, and shim."
- `diagnostics`: "Check whether the question is event history, current state, inventory, local arguments, or ETL analysis."
- `trust`: "Check handle rights, page protection, device IOCTL, driver policy, package capability, and buffer ownership."

For experiment sections, use this compact shape:

- `Hypothesis`: the behavior being tested.
- `Steps`: numbered procedure; prefer commands and observable state.
- `Snippet`: minimal code or pseudocode only, not a full project.
- `Measure`: CSV fields, counters, HRESULTs, ETW views, registry values, or visible UI behavior.
- `Interpret`: what proves the hypothesis, what falsifies it, and what common confounder to rule out.
- `References`: existing note links first, Microsoft docs where the API contract matters.

Then add one of these implementation tags:

- `Probe`: code that prints state and validates assumptions.
- `Repro`: minimal app that demonstrates a failure mode.
- `Bridge`: sample that crosses two APIs, such as Win32 to WinRT or GDI to D3D.
- `Matrix`: comparison harness that runs several APIs against the same target.
- `Forensics`: read-only code that classifies existing process, service, package, graphics, or trace state.

This keeps links from becoming trivia. Each source should either show a call shape, identify state to inspect, name a failure mode it prevents, or become a concrete probe/repro/bridge/matrix/forensics artifact.
