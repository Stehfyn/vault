# commdlg.h

The Win32 Common Dialog Box Library header -- `GetOpenFileNameW`, `GetSaveFileNameW`, `ChooseColorW`, `ChooseFontW`, `FindTextW`, `PrintDlgW`, `PageSetupDlgW` -- shipped in `comdlg32.dll` since Windows 3.1 and still the path of least resistance when you do not want to take a dependency on IFileDialog/COM. The two gotchas everybody hits: (1) `OPENFILENAMEW::lpstrFile` must point to a writable buffer that you have to pre-null-terminate (and that comdlg32 *modifies in place*), and (2) the filter string is a double-null-terminated `\0`-separated pair list, not a comma list -- a single wrong terminator and the dialog silently shows no filters. For modern apps prefer `IFileOpenDialog` (Vista+), but `GetOpenFileNameW` is still 4 lines instead of 40.

## References
- commdlg.h
