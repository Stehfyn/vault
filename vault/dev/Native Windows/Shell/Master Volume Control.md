# Master Volume Control

Per-link references for endpoint volume control.

## mastervol.c sample
Link: https://raw.githubusercontent.com/myfreeer/mastervol/master/mastervol.c
Brief: Use IAudioEndpointVolume to set master volume.
```cpp
CoInitialize(NULL);
IMMDeviceEnumerator* en = NULL;
IMMDevice* dev = NULL;
IAudioEndpointVolume* vol = NULL;
CoCreateInstance(&CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL,
                 &IID_IMMDeviceEnumerator, (void**)&en);
en->GetDefaultAudioEndpoint(eRender, eConsole, &dev);
dev->Activate(&IID_IAudioEndpointVolume, CLSCTX_ALL, NULL, (void**)&vol);
vol->SetMasterVolumeLevelScalar(0.5f, NULL);
```

## __uuidof in C workaround
Link: https://stackoverflow.com/questions/47012491/uuidof-in-c-master-volume-windows/47014922#47014922
Brief: Include initguid.h and use &CLSID_*/&IID_*.
```cpp
#include <initguid.h>
#include <mmdeviceapi.h>
IMMDeviceEnumerator* en = NULL;
HRESULT hr = CoCreateInstance(&CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL,
                              &IID_IMMDeviceEnumerator, (void**)&en);
if (SUCCEEDED(hr)) { en->Release(); }
```

## SndVol.exe notes
Link: https://learn.microsoft.com/en-us/windows/win32/devnotes/sndvol32-exe-
Brief: Launch the legacy UI with command-line switches.
```cpp
STARTUPINFO si = { sizeof(si) };
PROCESS_INFORMATION pi = {};
CreateProcessW(L"C:\\Windows\\System32\\SndVol.exe",
               L" -r", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
CloseHandle(pi.hThread);
CloseHandle(pi.hProcess);
```

