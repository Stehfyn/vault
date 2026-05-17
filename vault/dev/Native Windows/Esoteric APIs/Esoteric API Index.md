# Esoteric API Index

Per-link references for lesser-known Win32 and legacy APIs.

## InetIsOffline
Link: https://learn.microsoft.com/en-us/windows/win32/api/intshcut/nf-intshcut-inetisoffline
Brief: Check offline state before network work.
```cpp
DWORD flags = 0;
BOOL offline = InetIsOffline(flags);
if (offline) {
  // defer network calls
} else {
  // proceed
}
```

## Windows display driver DDI (winddi)
Link: https://learn.microsoft.com/en-us/windows/win32/api/winddi/
Brief: Typical driver DDI entry forwards to Eng* helpers.
```cpp
BOOL APIENTRY DrvBitBlt(SURFOBJ* trg, SURFOBJ* src, SURFOBJ* msk,
                        CLIPOBJ* clip, XLATEOBJ* xlo, RECTL* rcl,
                        POINTL* psrc, POINTL* pmsk, BRUSHOBJ* br,
                        POINTL* pbr, ROP4 rop) {
  return EngBitBlt(trg, src, msk, clip, xlo, rcl, psrc, pmsk, br, pbr, rop);
}
```

## Winreg.h registry helpers
Link: https://learn.microsoft.com/en-us/windows/win32/api/winreg/
Brief: Open a key and write a REG_DWORD value.
```cpp
HKEY key = NULL;
RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\MyApp", 0, KEY_SET_VALUE, &key);
DWORD value = 1;
RegSetValueExW(key, L"Enabled", 0, REG_DWORD, (BYTE*)&value, sizeof(value));
RegCloseKey(key);
```

## Multimedia API catalog
Link: https://learn.microsoft.com/en-us/windows/win32/api/_multimedia/
Brief: Query audio output device capabilities.
```cpp
UINT count = waveOutGetNumDevs();
WAVEOUTCAPSW caps = {};
MMRESULT mmr = waveOutGetDevCapsW(0, &caps, sizeof(caps));
if (count > 0 && mmr == MMSYSERR_NOERROR) {
  // caps.szPname
}
```

## Remote Desktop Services reference
Link: https://learn.microsoft.com/en-us/windows/win32/api/_termserv/
Brief: Read current session user name with WTS.
```cpp
LPWSTR buffer = NULL;
DWORD bytes = 0;
if (WTSQuerySessionInformationW(WTS_CURRENT_SERVER_HANDLE,
    WTS_CURRENT_SESSION, WTSUserName, &buffer, &bytes)) {
  WTSFreeMemory(buffer);
}
```

## Restart Manager reference
Link: https://learn.microsoft.com/en-us/windows/win32/api/_rstmgr/
Brief: Register a file and close the session.
```cpp
DWORD session = 0;
WCHAR key[CCH_RM_SESSION_KEY + 1] = {};
if (RmStartSession(&session, 0, key) == ERROR_SUCCESS) {
  LPCWSTR files[] = { L"C:\\Temp\\file.txt" };
  RmRegisterResources(session, 1, files, 0, NULL, 0, NULL);
  RmEndSession(session);
}
```

## Process Status API (PSAPI)
Link: https://learn.microsoft.com/en-us/windows/win32/api/_psapi/
Brief: Enumerate processes before querying images.
```cpp
DWORD pids[1024] = {};
DWORD needed = 0;
if (EnumProcesses(pids, sizeof(pids), &needed)) {
  DWORD count = needed / sizeof(DWORD);
  // iterate pids and call GetProcessImageFileNameW
}
```

## NetShell helper API
Link: https://learn.microsoft.com/en-us/windows/win32/api/_netshell/
Brief: Provide a basic InitHelperDll export for netsh.
```cpp
NS_HELPER_ATTRIBUTES g_helper = {};
NS_CONTEXT_ATTRIBUTES g_ctx = {};
DWORD WINAPI InitHelperDll(DWORD version, PVOID reserved) {
  g_helper.dwVersion = NS_HELPER_VERSION_1;
  g_helper.pwszCmdGroup = L"myhelper";
  g_ctx.dwVersion = NS_CONTEXT_VERSION_1;
  g_ctx.pwszContext = L"myctx";
  return NO_ERROR;
}
```

## BLUETOOTH_LOCAL_SERVICE_INFO
Link: https://learn.microsoft.com/en-us/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_local_service_info_struct
Brief: Enable a local Bluetooth service instance.
```cpp
BLUETOOTH_LOCAL_SERVICE_INFO info = {};
info.Enabled = TRUE;
info.btServiceClassId = serviceGuid;
info.cInstance = 1;
DWORD err = BluetoothSetLocalServiceInfo(NULL, &serviceGuid, 0, &info);
```

## Nano Server legacy guidance
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/mt708812(v=vs.85)
Brief: Branch on PRODUCT_NANO_SERVER when detected.
```cpp
DWORD product = 0;
if (GetProductInfo(10, 0, 0, 0, &product)) {
  if (product == PRODUCT_NANO_SERVER) {
    // Nano Server specific behavior
  }
}
```

## WAITORTIMERCALLBACK signature
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms687066(v=vs.85)
Brief: Register a wait callback with RegisterWaitForSingleObject.
```cpp
void CALLBACK MyWaitCallback(PVOID ctx, BOOLEAN timedOut) {
  // handle signal
}
HANDLE wait = NULL;
RegisterWaitForSingleObject(&wait, hEvent, MyWaitCallback,
                            NULL, INFINITE, WT_EXECUTEDEFAULT);
UnregisterWait(wait);
```

## IMediaRenderer::GetVolumeAsync
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh828933(v=vs.85)
Brief: Call the async volume getter and release the result.
```cpp
IMediaRenderer* renderer = nullptr;
IMFAsyncCallback* cb = nullptr;
IMFAsyncResult* result = nullptr;
HRESULT hr = renderer->GetVolumeAsync(cb, &result);
if (SUCCEEDED(hr) && result) {
  result->Release();
}
```

## USER_ACTIVITY_PRESENCE enum
Link: https://learn.microsoft.com/en-us/windows/win32/api/winnt/ne-winnt-user_activity_presence
Brief: Switch on user activity presence state.
```cpp
USER_ACTIVITY_PRESENCE presence = UserActivityPresenceUnknown;
switch (presence) {
  case UserActivityPresencePresent: /* active */ break;
  case UserActivityPresenceInactive: /* idle */ break;
  default: break;
}
```
