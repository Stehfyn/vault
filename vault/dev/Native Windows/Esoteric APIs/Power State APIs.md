# Power State APIs

`SetThreadExecutionState` is the pragmatic API for telling Windows that a thread is doing work that should delay sleep or display idle. It is a cooperative hint, commonly used by media playback, recording, installation, and long-running transfer code; the legacy `SetSystemPowerState` path is much heavier because it attempts to drive suspend/hibernate directly.

The nuance is lifetime and cleanup. Execution-state requests are process/thread-scoped policy hints that should be paired with a clear reset when work ends, otherwise a utility can silently ruin power behavior. This belongs near `MMCSS Research` and low-latency audio because media applications often coordinate scheduler class, timer behavior, and sleep inhibition together.

Minimal shape:

```cpp
EXECUTION_STATE previous =
    SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);

// long-running visible work: playback, recording, presentation, install, transfer

SetThreadExecutionState(ES_CONTINUOUS);
```

Connect this to latency-tuning scripts by separating three concerns: scheduler priority/MMCSS, timer or presentation cadence, and sleep/display-idle inhibition. `SetSystemPowerState` belongs in administrative power-control code, not ordinary "keep this task alive" logic.

## Source Code Reading

Twinkle Tray contributes the observation side: power-setting notifications through a window message, not just execution-state hints.

`src/modules/tt-windows-utils/windows_power_events.cc` exports:

```text
RegisterPowerSettingNotifications(hwnd)
  -> RegisterPowerSettingNotification(hwnd, &GUID_CONSOLE_DISPLAY_STATE, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_MONITOR_POWER_ON, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_SESSION_DISPLAY_STATUS, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_SYSTEM_AWAYMODE, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_LIDSWITCH_STATE_CHANGE, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_SESSION_USER_PRESENCE, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_STANDBY_TIMEOUT, 0)
  -> RegisterPowerSettingNotification(hwnd, &GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS, 0)
  -> ...

GetPowerSetting(lParam)
  -> reinterpret lParam as POWERBROADCAST_SETTING*
  -> StringFromGUID2(setting->PowerSetting)
  -> map known GUID to friendly name
  -> read DWORD from setting->Data
```

That decomposes the notification route:

```text
HWND receives WM_POWERBROADCAST / PBT_POWERSETTINGCHANGE
  -> lParam is POWERBROADCAST_SETTING
  -> PowerSetting GUID names the policy/signal
  -> Data carries a small typed value, often DWORD
  -> app translates GUID and value into UI/state changes
```

`SetThreadExecutionState` and `RegisterPowerSettingNotification` are orthogonal. The former asserts "do not idle out while this thread is doing work." The latter observes "the system/session/display/lid/policy state changed."

Verifiable assertions to drive:

```text
claim: execution-state requests are visible as power requests
probe: call `SetThreadExecutionState`; compare `powercfg /requests` before/during/after

claim: display/session changes arrive through HWND notifications
probe: register GUIDs, handle `WM_POWERBROADCAST`, print GUID string plus DWORD data

claim: execution-state hints are not scheduler tuning
probe: compare thread priority/MMCSS state before and after `SetThreadExecutionState`
```

Source files read:
- `twinkle-tray/src/modules/tt-windows-utils/windows_power_events.cc`

## Experiment Harness

Goal: verify execution-state lifetime and distinguish idle-timer hints from scheduler tuning.

Procedure:

```cpp
EXECUTION_STATE prev = SetThreadExecutionState(ES_CONTINUOUS |
                                               ES_SYSTEM_REQUIRED |
                                               ES_DISPLAY_REQUIRED);
printf("set prev=0x%08lx gle=%lu\n", prev, prev ? 0 : GetLastError());

Sleep(30000);

EXECUTION_STATE cleared = SetThreadExecutionState(ES_CONTINUOUS);
printf("clear prev=0x%08lx gle=%lu\n", cleared, cleared ? 0 : GetLastError());
```

Verification commands:

```powershell
powercfg /requests
powercfg /lastwake
```

Signals to record: flags set, previous state returned, duration, `powercfg /requests` before/during/after, display timeout policy, sleep timeout policy, and whether the thread exits without clearing. Expected baseline: `ES_CONTINUOUS | ES_SYSTEM_REQUIRED` appears as a temporary execution request while active and disappears after clear/process exit. `ES_USER_PRESENT` should fail when combined with other flags. This API does not raise priority, fix underruns, or stop an explicit user sleep request.

## Discussion Claim Verification

Claim: "`SetThreadExecutionState` keeps my program running."

Why it matters for new diagnostic code: the API is an idle-policy request, not a scheduler guarantee, process watchdog, or immunity from explicit suspend/shutdown. Media and diagnostic tools need to separate sleep inhibition from priority, timer resolution, and MMCSS.

How to verify:
1. Run the probe with no flags, with `ES_SYSTEM_REQUIRED`, and with `ES_DISPLAY_REQUIRED`.
2. Capture `powercfg /requests` before/during/after each run.
3. Register `WM_POWERBROADCAST` notifications and log display/session state changes.
4. Record thread priority/MMCSS status separately to prove it did not change.

Minimal code/pseudocode:

```cpp
SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
system("powercfg /requests");

// independent observation route
case WM_POWERBROADCAST:
  if (wParam == PBT_POWERSETTINGCHANGE) {
    auto* s = (POWERBROADCAST_SETTING*)lParam;
    log_guid_and_dword(s->PowerSetting, s->Data);
  }

SetThreadExecutionState(ES_CONTINUOUS);
```

Interpretation: the Microsoft `SetThreadExecutionState` link supports execution-state requests. The `SetSystemPowerState` link is a different, heavier administrative power-control route and should not be used to explain ordinary media/playback sleep inhibition. Power notification code verifies observation; it does not create a power request.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setthreadexecutionstate>
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setsystempowerstate>
