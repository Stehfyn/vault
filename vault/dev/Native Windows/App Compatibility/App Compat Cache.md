# App Compat Cache

`BaseFlushAppcompatCache` is an internal/devnote-level function for flushing the application compatibility cache. The useful fact is that app-compat state is not purely a file-on-disk database; Windows keeps runtime cache state that can affect whether shims and compatibility decisions appear to "stick" during testing.

This belongs near VxKex and OneCoreAPI because all three entries deal with compatibility layers, but at different levels: cache invalidation for Windows' own shim machinery, per-process API extension, and system-wide DLL replacement. Treat the function as a diagnostic lever, not a normal application API.

## Flush Shape

The documented devnote contract is deliberately tiny: no parameters, administrator caller, `BOOL` result. It is useful after changing shim database inputs during testing, not as an application dependency.

```c
typedef BOOL (WINAPI *BaseFlushAppcompatCacheFn)(void);
BaseFlushAppcompatCacheFn flush =
    (BaseFlushAppcompatCacheFn)GetProcAddress(GetModuleHandleW(L"kernel32.dll"),
                                              "BaseFlushAppcompatCache");
if (flush) {
    BOOL ok = flush();
}
```

## Experiment Harness

Make shim testing observable. Install or edit one compatibility database entry, run the target, flush cache, run again, and compare process behavior plus loader/shim logs.

```powershell
sdbinst.exe test.sdb
.\target.exe
.\flush_appcompat_cache.exe
.\target.exe
sdbinst.exe -u test.sdb
```

Signal: target behavior changes only when the database/shim is active, and stale behavior disappears after uninstall plus flush. Failure interpretation: if behavior persists after uninstall and flush, the cause is probably not the appcompat cache; inspect manifests, package identity, DLL search path, per-user/per-machine SDB registration, or a separate shim layer such as PSF/VxKex.

## Discussion Claim Verification

Claim: "My compatibility fix did not change behavior because Windows cached the old decision."

Why it matters for new code: this is a plausible test-lab failure, but it is also an easy excuse for bad shim targeting. Cache state, SDB registration, executable path matching, manifest state, package identity, and separate shim layers can all produce the same symptom.

How to verify:

```powershell
sdbinst.exe test.sdb
.\target.exe
.\flush_appcompat_cache.exe
sdbinst.exe -u test.sdb
.\target.exe
```

Minimal code/pseudocode:

```text
control: no SDB installed -> record behavior
test:    SDB installed -> record behavior
flush:   call BaseFlushAppcompatCache as admin
remove:  uninstall SDB -> record behavior
```

Interpretation: the devnote verifies that a flush function exists, not that every stale-looking result is cache-driven. Unsupported claim nullified: "flush did not fix it, so the cache is broken." More likely causes are mismatched executable identity, wrong SDB scope, another compatibility layer, or an unrelated loader/runtime issue.

## Connections

- `VxKex` and `VxKex-NEXT` are per-process compatibility layers whose behavior can be confused with stale appcompat decisions during testing.
- `MSIX Package Support Framework` is the packaged-app shim route; appcompat cache flushing is the Windows shim/testing route.
- `MSI Search Conditions` can feed compatibility decisions indirectly when install detection drives which binary, manifest, or shim path is deployed.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/baseflushappcompatcache>
- <https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/deployment/compatibility/creating-a-custom-compatibility-fix-in-compatibility-administrator>
