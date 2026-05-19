# Esoteric API Index

This note is a triage map for APIs that are real, documented or semi-documented, but too narrow to deserve first-class treatment until a concrete use case appears. Keep links here only if the code shape teaches a subsystem boundary. Generic Win32 calls belong in `Native Windows.md`; registry material belongs in `(REG) Windows Registry`; display/power/input topics should move to their dedicated folders once they grow.

## Network and session state
Links:
- https://learn.microsoft.com/en-us/windows/win32/api/intshcut/nf-intshcut-inetisoffline
- https://learn.microsoft.com/en-us/windows/win32/api/_termserv/

Contribution: `InetIsOffline` is the old Internet Explorer offline-state gate; WTS APIs expose terminal-services/session identity. They are useful together when a shell/helper process must decide whether user-facing network work should be attempted in the current interactive session.

```cpp
if (InetIsOffline(0)) {
    return DeferNetworkWork();
}

LPWSTR user = nullptr;
DWORD bytes = 0;
if (WTSQuerySessionInformationW(WTS_CURRENT_SERVER_HANDLE,
        WTS_CURRENT_SESSION, WTSUserName, &user, &bytes)) {
    WTSFreeMemory(user);
}
```

## Driver and graphics DDI archaeology
Link: https://learn.microsoft.com/en-us/windows/win32/api/winddi/

Contribution: `winddi.h` is not an application graphics API. It is the old GDI display-driver DDI: `DrvBitBlt`, `DrvTextOut`, `Eng*` helper calls, and `SURFOBJ`/`CLIPOBJ` structures. It belongs near GDI/dxgkernel notes because it explains why old drivers and ReactOS/Wine code discuss GDI operations below user mode.

```cpp
BOOL APIENTRY DrvBitBlt(SURFOBJ* dst, SURFOBJ* src, SURFOBJ* mask,
                        CLIPOBJ* clip, XLATEOBJ* xlate, RECTL* bounds,
                        POINTL* src_pt, POINTL* mask_pt,
                        BRUSHOBJ* brush, POINTL* brush_org, ROP4 rop) {
    return EngBitBlt(dst, src, mask, clip, xlate, bounds,
                     src_pt, mask_pt, brush, brush_org, rop);
}
```

## Restart Manager and setup coordination
Link: https://learn.microsoft.com/en-us/windows/win32/api/_rstmgr/

Contribution: Restart Manager is the installer/updater coordination layer. It lets setup code register files/services and ask which processes hold them so the updater can shut down/restart applications without blind process killing.

```cpp
DWORD session = 0;
wchar_t key[CCH_RM_SESSION_KEY + 1] = {};
if (RmStartSession(&session, 0, key) == ERROR_SUCCESS) {
    LPCWSTR files[] = { LR"(C:\Program Files\App\app.dll)" };
    RmRegisterResources(session, ARRAYSIZE(files), files, 0, nullptr, 0, nullptr);
    RmEndSession(session);
}
```

## Multimedia leftovers
Links:
- https://learn.microsoft.com/en-us/windows/win32/api/_multimedia/
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh828933(v=vs.85)

Contribution: the multimedia catalog covers WinMM-era devices (`waveOut*`, `mixer*`, timers); `IMediaRenderer::GetVolumeAsync` is a WinRT/Media Renderer remnant. Keep these as historical boundary markers. Modern audio code should normally move to WASAPI/XAudio2/Media Foundation notes.

```cpp
WAVEOUTCAPSW caps = {};
for (UINT i = 0, n = waveOutGetNumDevs(); i < n; ++i) {
    if (waveOutGetDevCapsW(i, &caps, sizeof(caps)) == MMSYSERR_NOERROR) {
        // caps.szPname is the legacy device display name.
    }
}
```

## Bluetooth local service registration
Link: https://learn.microsoft.com/en-us/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_local_service_info_struct

Contribution: `BluetoothSetLocalServiceInfo` is the local SDP/service-advertisement surface. It is not device pairing; it controls whether a local service instance is enabled and how it is described to peers.

```cpp
BLUETOOTH_LOCAL_SERVICE_INFO info = {};
info.Enabled = TRUE;
info.btServiceClassId = service_guid;
StringCchCopyW(info.szName, ARRAYSIZE(info.szName), L"My RFCOMM Service");
DWORD err = BluetoothSetLocalServiceInfo(nullptr, &service_guid, 0, &info);
```

## Thread-pool waits and idle presence
Links:
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms687066(v=vs.85)
- https://learn.microsoft.com/en-us/windows/win32/api/winnt/ne-winnt-user_activity_presence

Contribution: `WAITORTIMERCALLBACK` is the callback signature behind registered waits; `USER_ACTIVITY_PRESENCE` is a low-level enum used by power/user-presence APIs. Put them near message-loop/power notes, not beside UI code.

```cpp
void CALLBACK OnEvent(PVOID context, BOOLEAN timed_out) {
    SetEvent(static_cast<HANDLE>(context));
}

HANDLE wait = nullptr;
RegisterWaitForSingleObject(&wait, source_event, OnEvent,
                            completion_event, INFINITE, WT_EXECUTEDEFAULT);
```

## Nano Server and product gating
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/mt708812(v=vs.85)

Contribution: the old Nano Server guidance is mostly a reminder that product/SKU gating is not the same as API availability. Prefer feature detection and delay-loading when possible; use SKU checks only when deployment policy really differs.

```cpp
DWORD product = 0;
if (GetProductInfo(10, 0, 0, 0, &product) &&
    product == PRODUCT_NANO_SERVER) {
    DisableGuiOnlyFeature();
}
```

Connections: `Power State APIs.md`, `(WMI) Windows Management Instrumentation/WMI C++ Usage.md`, `Headers/winddi`-adjacent GDI notes, and Windows Installer notes are the natural homes when any item here stops being miscellaneous.
