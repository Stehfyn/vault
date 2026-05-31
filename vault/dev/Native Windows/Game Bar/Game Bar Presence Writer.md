# Game Bar Presence Writer

`IPresenceWriter` is the narrow customization point behind Game Bar presence updates: an out-of-process COM server receives focus/close events and can translate a window, AUMID, and app identity into richer presence state than the default shell heuristics can infer. The interesting part is not the call shape but the registration model: the server path lives under `HKLM\SOFTWARE\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer\ExePath`, so this is machine-level integration rather than a per-game plugin.

Use this entry as the missing bridge between desktop HWND lifecycle and the Xbox/Game Bar identity stack. It pairs naturally with `XboxGameBarSamples` for widget activation, `xbox-live-api` for service-side presence, and `HaloMCC-DiscordRPC` for the same concept implemented outside the Microsoft widget surface.

## Source Shape

The public devnote exposes the registration shape more than a rich SDK surface. Treat the implementation as an out-of-process COM server with a Windows Runtime server registration. The actionable skeleton is: register the server path, implement `IPresenceWriter`, translate focus/close callbacks into presence state, and keep machine-wide install/update behavior explicit.

```reg
HKLM\SOFTWARE\Microsoft\WindowsRuntime\Server\
  Windows.Gaming.GameBar.Internal.PresenceWriterServer
    ExePath = "C:\Path\PresenceWriter.exe"
```

```cpp
struct PresenceWriter : winrt::implements<PresenceWriter, IPresenceWriter>
{
    HRESULT OnGameFocus(/* hwnd, aumid, process/app identity */);
    HRESULT OnGameClose(/* identity */);
};
```

## Connections

- `XboxGameBarSamples - Widget Reference Code.md` is the packaged overlay UI route.
- `xbox-live-api - Official Xbox Live Bindings.md` is the Xbox service/presence data route.
- `gameux.h - Legacy Games Explorer API.md` is the old shell-registration generation of the same "what game is this executable?" problem.
- `../Shell/Windows Explorer Integration.md` is the generic shell window identity route; Presence Writer is the Game Bar-specific specialization.

## Experiment Harness

Goal: validate registration and callback reachability before implementing presence policy.

```powershell
Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer' |
  Select ExePath
```

Probe shape: server starts, logs process ID, logs each focus/close callback identity tuple, then exits cleanly when idle.

Measured signal: registry path, server process launch, callback count, HWND/AUMID/process identity observed, elevation needed to register.

Failure interpretation: no process launch means registration/activation failure; launch with no callbacks means Game Bar did not classify the target as a presence candidate. Reference: <https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter>.

## Verification Route

Claim to verify: the registry `ExePath` is sufficient for Game Bar to activate the out-of-process presence writer.

Why it matters: this is a machine-level WinRT server registration, so failure can be registry, COM/WinRT activation, process launch, callback classification, or Game Bar policy. A working executable alone proves almost nothing.

Probe:

```powershell
reg query "HKLM\SOFTWARE\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer" /v ExePath

Get-WinEvent -LogName Microsoft-Windows-AppModel-Runtime/Admin -MaxEvents 50 |
  Select-Object TimeCreated, Id, ProviderName, Message
```

Minimal server logging:

```cpp
int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    OutputDebugStringW(L"presence writer process launched\n");
    // Register class factory / WinRT server, then log each callback tuple:
    // hwnd, pid, aumid, executable path, callback kind.
}
```

Interpretation:
- No process launch: registration or activation failed before interface code ran.
- Launch but no callbacks: Game Bar did not classify the foreground HWND/app as a presence candidate.
- Callbacks arrive without usable AUMID: presence code must tolerate classic Win32 identity gaps.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter>
