# 7-Zip NSIS Build Recipe

Build scripts and patched NSIS installer recipe for producing optimized 7-Zip MSVC binaries (LTCG, PGO) plus the matching .exe installer. The installer half is a worked example of NSIS-from-source: macros for ACL-elevated install, registry registration of the shell DLL via `regsvr32`, and silent uninstall via `UnRegisterServer`. Useful if you need to ship a Win32 shell extension and want a known-good NSIS template.

```nsis
; Register shell extension DLL on install, unregister on uninstall
Section -RegisterDLL
  ExecWait '"$SYSDIR\regsvr32.exe" /s "$INSTDIR\7-zip.dll"'
SectionEnd
Section -un.UnregisterDLL
  ExecWait '"$SYSDIR\regsvr32.exe" /s /u "$INSTDIR\7-zip.dll"'
SectionEnd
```

## References
- <https://github.com/myfreeer/7z-build-nsis>
