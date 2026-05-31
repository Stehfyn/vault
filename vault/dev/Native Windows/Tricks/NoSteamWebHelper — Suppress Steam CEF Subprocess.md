# NoSteamWebHelper — Suppress Steam CEF Subprocess

Suppresses Steam's `steamwebhelper.exe` (the embedded Chromium/CEF subprocess that renders the library, store, and overlay UI). Steam normally relaunches the helper if you kill it, so the trick is intercepting at startup before CEF spins up — the project ships a stub that takes the helper's place and exits immediately, dropping Steam's resident memory by hundreds of MB at the cost of CEF-only views (store, library grid) being unavailable. Useful on low-RAM boxes and headless gaming setups where the storefront is unwanted overhead.

```text
// Build: produces a tiny exe to substitute for steamwebhelper.exe under
//   <Steam>\bin\cef\cef.win7x64\steamwebhelper.exe (path varies by branch).
// Effect: Steam falls back to its legacy native UI for windows that still
//   have one; CEF-only views (store, library grid) won't render.
```

## Discussion Claim To Verify

Claim implied by the project: replacing or suppressing `steamwebhelper.exe` reduces Steam overhead without breaking the parts you care about.

Why it matters: the real boundary is not "CEF bad." It is which Steam windows and overlay paths are native, which are CEF-only, and whether Steam's updater restores or rejects the substituted binary.

Verification route:

```powershell
Get-Process steam,steamwebhelper -ErrorAction SilentlyContinue |
  Select-Object Name, Id, WorkingSet64, Path

Get-FileHash "$env:ProgramFiles(x86)\Steam\bin\cef\cef.win7x64\steamwebhelper.exe" -ErrorAction SilentlyContinue
```

ProcMon filters:

```text
Process Name is steam.exe
Operation is Process Create
Path contains steamwebhelper.exe
```

Interpretation:
- `steam.exe` repeatedly creates `steamwebhelper.exe`: suppression is fighting a supervisor loop, not disabling a static optional component.
- Working set drops but Library/Store/overlay surfaces fail: the source supports a resource tradeoff, not a free optimization.
- Hash/path changes after Steam update: the substitution is not durable without revalidation.

## References
- <https://github.com/Aetopia/NoSteamWebHelper>
