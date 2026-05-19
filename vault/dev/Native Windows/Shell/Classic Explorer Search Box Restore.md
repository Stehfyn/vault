# Classic Explorer Search Box Restore

Restores the pre-19H2 Explorer search box (an actual editable edit control, queries done in-process) on Windows 10 19H2+ where Microsoft replaced it with a passthrough that opens the system-wide Cortana / Windows Search UI. Works by injecting into `explorer.exe`, locating the `WorkerW`/address-bar control hierarchy and recreating the legacy `UniversalSearchBand` window, then handling `WM_COMMAND` to forward typed text directly to `IShellFolder::ParseDisplayName` + folder enumeration instead of the modern search-host pipe.

## References
- <https://github.com/krlvm/ClassicSearch>
