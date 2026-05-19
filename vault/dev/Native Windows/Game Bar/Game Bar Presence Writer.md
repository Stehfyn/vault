# Game Bar Presence Writer

`IPresenceWriter` is the narrow customization point behind Game Bar presence updates: an out-of-process COM server receives focus/close events and can translate a window, AUMID, and app identity into richer presence state than the default shell heuristics can infer. The interesting part is not the call shape but the registration model: the server path lives under `HKLM\SOFTWARE\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer\ExePath`, so this is machine-level integration rather than a per-game plugin.

Use this entry as the missing bridge between desktop HWND lifecycle and the Xbox/Game Bar identity stack. It pairs naturally with `XboxGameBarSamples` for widget activation, `xbox-live-api` for service-side presence, and `HaloMCC-DiscordRPC` for the same concept implemented outside the Microsoft widget surface.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter>
