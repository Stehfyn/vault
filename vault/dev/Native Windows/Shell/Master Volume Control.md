# Master Volume Control

Master volume is a Core Audio endpoint operation, not a mixer-control operation. The useful link between the sample code, the C `__uuidof` workaround, and the `SndVol.exe` note is this split: programmatic control uses COM interfaces, while the shell UI remains a separate process that can be launched when the user needs policy/UI instead of silent state change.

## Endpoint Volume

The `mastervol.c` sample contributes the core call chain: device enumerator, default render endpoint, `IAudioEndpointVolume`, scalar volume. Use a `GUID` event context if you also subscribe to notifications so your own writes can be distinguished from user or system writes.

```cpp
wil::com_ptr<IMMDeviceEnumerator> enumerator;
CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL,
                 IID_PPV_ARGS(&enumerator));

wil::com_ptr<IMMDevice> endpoint;
enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &endpoint);

wil::com_ptr<IAudioEndpointVolume> volume;
endpoint->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr,
                   reinterpret_cast<void**>(&volume));

GUID context = { 0x8f6d4f3b, 0x7b0c, 0x49d4,
                 { 0x9c, 0x4d, 0x9f, 0x40, 0x47, 0x2e, 0x8b, 0x11 } };
volume->SetMasterVolumeLevelScalar(0.35f, &context);
```

## C Without `__uuidof`

The C workaround is not cosmetic. In C, COM activation needs real `CLSID_*` and `IID_*` objects, so include `initguid.h` in exactly one translation unit or link against a library that defines them.

```c
#include <initguid.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

IMMDeviceEnumerator* enumerator = NULL;
HRESULT hr = CoCreateInstance(&CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL,
                              &IID_IMMDeviceEnumerator, (void**)&enumerator);
```

## Shell Volume UI

`SndVol.exe` is the right contribution when the program should hand control to the user rather than impersonate the user. This keeps per-session audio policy, device selection, and accessibility behavior in the shell-owned UI.

```cpp
ShellExecuteW(nullptr, L"open", L"sndvol.exe", nullptr, nullptr, SW_SHOWNORMAL);
```

## Connections

- `Shell Execute.md` is the launch boundary for delegating volume policy to `SndVol.exe`.
- `Notification Area (Tray).md` is where endpoint volume often becomes status UI.
- `Media Foundation` and WASAPI notes use the same endpoint/session split from the rendering side.

## References

- <https://raw.githubusercontent.com/myfreeer/mastervol/master/mastervol.c>
- <https://stackoverflow.com/questions/47012491/uuidof-in-c-master-volume-windows/47014922#47014922>
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/sndvol32-exe->
