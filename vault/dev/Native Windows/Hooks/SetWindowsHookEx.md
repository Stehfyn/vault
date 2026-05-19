# SetWindowsHookEx

`SetWindowsHookEx` installs hook procedures into USER32-defined event paths: keyboard, mouse, CBT, shell, call-window-proc, get-message, and related categories. The key distinction is thread-specific versus global. Thread hooks can live in the installing process when the target thread is local; global hooks that must run in other processes require a DLL that USER32 can map into those processes.

Hooks are synchronous enough to be dangerous. A slow or reentrant hook can stall input or window dispatch, and hook procedures must preserve the chain contract by passing unhandled events onward. Bitness, desktop/session isolation, integrity levels, and UIAccess rules also affect which processes can be hooked. This is a message-system facility first and an injection primitive only as a consequence of how global hooks are implemented.

## Connections
- WinSpy++ is a legitimate inspection use case for message hooks.
- `Injected DLL Unload` covers teardown behavior after a global hook has mapped a DLL elsewhere.
- `System-Defined Messages` and `Message Queue Implementation` explain what the hooks are observing.

## References
- Microsoft Docs: About Hooks (hook procedure signature, call chain, global vs. thread-specific)
  https://learn.microsoft.com/en-us/windows/win32/winmsg/about-hooks
