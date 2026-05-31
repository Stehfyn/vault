# Cheat Driver (IOCTL Memory R/W)

This is the canonical shape of a kernel assist driver used by game cheats: user mode opens a device object, sends IOCTLs describing a target process/address/range, and the driver performs memory operations the user-mode process could not safely or lawfully do by handle alone. The same architecture appears in many public "learning" drivers.

The defensive lesson is the interface boundary. The driver object name, symbolic link, IOCTL codes, handle-opening process, and target-process access patterns are all observable. Modern variants try to hide or piggyback on vulnerable signed drivers, which connects this entry to `GDRV Loader`, `PPL Killer`, `PreviousMode Flip Memory R W`, and `User-Mode Physical Memory Library`.

Call-shape to compare against ordinary driver clients:

```cpp
HANDLE device = CreateFileW(LR"(\\.\SomeDevice)",
                            GENERIC_READ | GENERIC_WRITE,
                            0, nullptr, OPEN_EXISTING, 0, nullptr);

BOOL ok = DeviceIoControl(device,
                          ioctl_code,
                          &request, sizeof(request),
                          &response, sizeof(response),
                          &bytes_returned,
                          nullptr);
```

For triage, the useful record is not the payload but the boundary metadata: caller PID, device path, service/driver image, IOCTL value, input/output buffer sizes, target PID if present, and whether the caller also holds normal process handles. This separates legitimate device management utilities from tools that use a driver as a substitute for `OpenProcess` plus `ReadProcessMemory`/`WriteProcessMemory`.

## Experiment Harness

Goal: exercise `DeviceIoControl` safely by logging boundary metadata against documented file-system control codes, not unknown third-party drivers.

Procedure:

```cpp
HANDLE f = CreateFileW(L"probe.tmp", GENERIC_READ,
                       FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                       nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

USHORT compression = 0;
DWORD returned = 0;
BOOL ok = DeviceIoControl(f, FSCTL_GET_COMPRESSION,
                          nullptr, 0,
                          &compression, sizeof(compression),
                          &returned, nullptr);

printf("code=0x%08lx method=%lu access=%lu ok=%d bytes=%lu gle=%lu\n",
       FSCTL_GET_COMPRESSION,
       FSCTL_GET_COMPRESSION & 0x3,
       (FSCTL_GET_COMPRESSION >> 14) & 0x3,
       ok, returned, ok ? ERROR_SUCCESS : GetLastError());
```

Signals to record: handle path type, desired access passed to `CreateFileW`, share mode, IOCTL value, decoded method/access bits, input size, output size, bytes returned, elapsed time, and `GetLastError`. Expected baseline: `FSCTL_GET_COMPRESSION` returns a small compression-state value on supporting file systems and fails with a documented filesystem/support error when unsupported. Do not point this harness at arbitrary `\\.\DeviceName` paths; if you need a driver lab, use a purpose-built benign sample driver and log only control-code metadata, access checks, and buffer sizes.

## References
- <https://github.com/nkga/cheat-driver>
- <https://learn.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol>
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/defining-i-o-control-codes>
- <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_get_compression>
