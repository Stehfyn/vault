# App Compat Cache

`BaseFlushAppcompatCache` is an internal/devnote-level function for flushing the application compatibility cache. The useful fact is that app-compat state is not purely a file-on-disk database; Windows keeps runtime cache state that can affect whether shims and compatibility decisions appear to "stick" during testing.

This belongs near VxKex and OneCoreAPI because all three entries deal with compatibility layers, but at different levels: cache invalidation for Windows' own shim machinery, per-process API extension, and system-wide DLL replacement. Treat the function as a diagnostic lever, not a normal application API.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/baseflushappcompatcache>
