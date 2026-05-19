# WIL (Windows Implementation Library)

WIL is Microsoft's header-only C++ library for making ordinary Windows API code survivable. It is not a UI framework. Its core contribution is resource and error discipline: `wil::unique_handle`, `wil::unique_hkey`, `wil::com_ptr`, `unique_cotaskmem_string`, scope-exit helpers, registry wrappers, and the `THROW_IF_FAILED` / `RETURN_IF_FAILED` / `LOG_IF_FAILED` families that standardize HRESULT and last-error handling.

Place it near COM, WTL, Win32xx, and sktoolslib. WTL/Win32xx wrap windows; WIL wraps the failure-prone substrate underneath them. The practical rule is simple: modern C++ Win32 code should have a reason not to use WIL for lifetime and error paths, especially around COM, handles, registry, and cleanup-on-failure code.

## References
- <https://github.com/microsoft/wil> - Microsoft-maintained Windows C++ helper library for RAII resources, COM pointers, registry helpers, and error macros.
