# NoSteamWebHelper — Suppress Steam CEF Subprocess

Suppresses Steam's `steamwebhelper.exe` (the embedded Chromium/CEF subprocess that renders the library, store, and overlay UI). Steam normally relaunches the helper if you kill it, so the trick is intercepting at startup before CEF spins up — the project ships a stub that takes the helper's place and exits immediately, dropping Steam's resident memory by hundreds of MB at the cost of CEF-only views (store, library grid) being unavailable. Useful on low-RAM boxes and headless gaming setups where the storefront is unwanted overhead.

```text
// Build: produces a tiny exe to substitute for steamwebhelper.exe under
//   <Steam>\bin\cef\cef.win7x64\steamwebhelper.exe (path varies by branch).
// Effect: Steam falls back to its legacy native UI for windows that still
//   have one; CEF-only views (store, library grid) won't render.
```

## References
- <https://github.com/Aetopia/NoSteamWebHelper>
