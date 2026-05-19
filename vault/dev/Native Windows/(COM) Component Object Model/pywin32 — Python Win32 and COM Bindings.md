# pywin32 - Python Win32 and COM Bindings

pywin32 is the canonical Python bridge to Win32 and classic COM: `win32api`, `win32gui`, `win32con`, service helpers, MAPI/ADSI/WMI bindings, and the `pythoncom` / `win32com.client` stack for Automation. Its COM support is the important part for this directory: late-bound `IDispatch`, generated `makepy` wrappers from type libraries, and pure-Python COM server registration all expose the same mechanics that C++ clients hide behind ATL or smart pointers.

Use pywin32 as a diagnostic and automation tool, not just an application dependency. It is often the quickest way to enumerate windows, inspect registry/service state, drive Office/Explorer automation, or reproduce a COM activation problem before writing the native repro. Pair it with the "COM in plain C" and Toast entries: pywin32 sits at the other end of the same ABI, trading control for speed of experimentation.

## References
- <https://github.com/mhammond/pywin32> - maintained Python extensions for Win32, COM, and related Windows automation APIs.
