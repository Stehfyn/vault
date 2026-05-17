Win32 port of sxhkd (simple X hotkey daemon) that uses the `RegisterHotKey` API to bind global hotkeys to shell commands. Supports optional UNIX-style virtual desktop switching via the `VirtualDesktopAccessor` DLL. Configuration is done by editing `config.h` at compile time, matching sxhkd's static key-table style.

```cpp
// Register a global hotkey (Alt+Q), then dispatch in the message loop
RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 'Q');

MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    if (msg.message == WM_HOTKEY) {
        int id = (int)msg.wParam;
        // id maps to an entry in the keys[] table from config.h
        HandleHotkey(id);
    }
}

UnregisterHotKey(NULL, 1);
```

```c
// config.h — compile-time key binding table (sxhkd style)
static Key keys[] = {
    /* modifier          key        function        argument */
    { MOD_ALT,           'Q',      killForeground, {0} },
    { MOD_ALT,           VK_RETURN, spawn,         {.v = termcmd} },
    { MOD_ALT|MOD_SHIFT, 'E',      toggleexplorer, {0} },
};
```

## References

- <https://github.com/theSoberSobber/sxhkd-win32>
