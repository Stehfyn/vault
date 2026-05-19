# CustCntl.h - Legacy Custom Control Protocol

`custcntl.h` is not a normal custom-control programming model. It is the old SDK protocol that let third-party Win16/early-Win32 controls describe their styles and design-time behavior to Visual Workbench / Dialog Editor. Structures such as `CCSTYLE`, flags such as `CCF_NOTEXT`, and `CCHOOKPROC` callbacks are about design-time metadata and style editing, not about runtime `WM_NOTIFY` control APIs.

The header is useful mainly for archaeology: old control DLLs, early dialog-resource tooling, and SDK samples may reference it, while modern custom controls use direct window classes, COMCTL32 conventions, ActiveX, WPF, or XAML. Compare it with mCtrl and the WTL owner-drawn control notes: those are runtime control libraries, while `custcntl.h` is a dead design-time integration surface.

## References
- `CustCntl.h` - Windows SDK header for the legacy custom-control design-time protocol.
