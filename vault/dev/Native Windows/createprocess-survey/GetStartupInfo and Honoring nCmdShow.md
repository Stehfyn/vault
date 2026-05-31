# GetStartupInfo and Honoring nCmdShow

`GetStartupInfoW` is not a syscall. It is a pure read of the **PEB**: `gs:[0x60]` -> PEB -> `PEB+0x20` (`ProcessParameters`, an `RTL_USER_PROCESS_PARAMETERS`) -> field copies into `STARTUPINFOW`. The launcher (`CreateProcess`/`RtlCreateUserProcess`) writes those fields at process creation; the app reads them back. Verified from `kernelbase!GetStartupInfoW` (kernel32's export is a thunk to it):

- `si->wShowWindow = ProcessParameters->ShowWindowFlags` (`PP+0xA8`, WORD)
- `si->dwFlags     = ProcessParameters->WindowFlags`     (`PP+0xA4`); `STARTF_USESHOWWINDOW` is bit 0
- `si->cb` is hardcoded to `0x68` (104); std handles copied only if `WindowFlags & 0x700`

So "honoring the requested show state" is just: `nCmdShow = (dwFlags & STARTF_USESHOWWINDOW) ? wShowWindow : SW_SHOWDEFAULT;` and passing that to the first `ShowWindow`. A CRT `WinMain` does exactly this; a custom/no-CRT entry must do it itself (or read `PP->ShowWindowFlags` directly). The `RTL_USER_PROCESS_PARAMETERS` layout lives in `vendor/phnt/ntrtl.h`.

## The show-state is launcher-dependent

Link: https://stackoverflow.com/questions/7362866/getstartupinfo-differs-according-to-the-explorer-the-app-is-launching-from

Contribution: concrete evidence that `wShowWindow`/`STARTF_USESHOWWINDOW` you read back depends entirely on what the *parent* put in `STARTUPINFO`. Explorer double-click, shortcut (`.lnk` has its own "Run: minimized/maximized" field), `cmd start`, and a debugger each seed different `ShowWindowFlags`. The app is not "wrong" when it varies — it is faithfully reflecting the launcher's request. Pairs with `../Shell/Shell Shortcuts.md` (the `.lnk` `nShow`/`IShellLink::SetShowCmd` is one of these sources).

## Honoring the request is the app's job

Link: https://visualstudiomagazine.com/articles/2010/05/04/honoring-startup-requests.aspx

Contribution: the rationale and pattern for actually consuming `nCmdShow` instead of forcing `SW_SHOW`/`SW_SHOWNORMAL`. Explains why `SW_SHOWDEFAULT` exists (it tells the window manager to consult `STARTUPINFO` itself on the first `ShowWindow`) and why ignoring it breaks "start minimized" shortcuts and shell automation.

## A real-world regression: Go ignored it

Link: https://github.com/golang/go/issues/31316

Contribution: case study of a runtime/toolchain that did *not* honor the startup show request for GUI apps — Go binaries ignored `STARTF_USESHOWWINDOW`/`wShowWindow`, so "start minimized" etc. had no effect. Useful as the failure mode this note prevents, and as confirmation that this is a real, shipped-software pitfall, not a theoretical one.

## Connections
- `kernelbase GetStartupInfoW Disassembly (PEB Read).md` — full annotated reverse + the PP offset map summarized above.
- `README.md` / the survey markers (`01_rtl_create_user_process` ...) — the *producer* side that fills `ProcessParameters`.
- `vendor/phnt/ntrtl.h` — `RTL_USER_PROCESS_PARAMETERS` field offsets used above.
- `../Shell/Shell Shortcuts.md` — `.lnk` show-command as one launcher source.
