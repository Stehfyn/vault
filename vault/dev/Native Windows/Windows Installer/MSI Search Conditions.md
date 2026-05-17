## References
- https://learn.microsoft.com/en-us/windows/win32/msi/searching-for-existing-applications-files-registry-entries-or--ini-file-entries
- https://youtu.be/xzIeQWLDSu4?si=A0l3-D_urNPBWldO&t=2462
- [[dev/Native Windows/(INI) Windows INI/unsorted|unsorted]]

Windows Installer’s AppSearch action consults AppSearch, Signature, and locator tables (RegLocator/IniLocator/DrLocator) to find files, registry values, or INI entries and sets properties when found.

```text
; AppSearch table
Property    Signature_
MYAPPDIR    MyAppSig

; Signature table
Signature   FileName
MyAppSig    MyApp.exe

; RegLocator table (fallback)
Signature_  Root  Key                Name
MyAppSig    2     Software\MyApp     InstallDir
```
