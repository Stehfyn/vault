# statehelpers.h

Thin internal wrapper around the app-state-change notification API declared in `appnotify.h` (the public surface). UWP / packaged Win32 apps register a callback that fires on `Suspending`, `Resuming`, `LowMemory`, and (Windows 10+) `EnteredBackground` / `LeavingBackground`. The runtime cluster: `appnotify.h` for the entry points (`RegisterAppStateChangeNotification`, `UnregisterAppStateChangeNotification`), `appmodel.h` for package identity, `processthreadsapi.h` for the underlying job-based suspend mechanism. Mostly only relevant if you're targetting AppContainer / Centennial scenarios -- desktop Win32 apps usually use `WM_POWERBROADCAST` or `RegisterPowerSettingNotification` instead.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/appnotify/>
