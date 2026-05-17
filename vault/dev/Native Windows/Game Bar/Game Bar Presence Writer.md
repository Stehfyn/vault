# Game Bar Presence Writer

Short description: Game Bar Presence Writer is a Windows 10+ component that receives game “presence” state changes. Developers can override the default behavior by implementing an out-of-proc COM server that implements `IPresenceWriter` and handles `UpdatePresence` calls for focus/close events.

Minimal usage pseudo-call:
```cpp
// Called by the Presence Writer server when notified by the system.
presenceWriter->UpdatePresence(hWnd, GotFocus, appId, Aumid);
```

Registry registration:
`HKLM\SOFTWARE\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer\ExePath` (REG_SZ path to the server executable).

Reference: https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter
