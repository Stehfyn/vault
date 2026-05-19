# Proxy-DLL-Loads - NtCreateSection Loader Path

Proxy-DLL-Loads is useful because it centers the native section-object path for image mapping. Windows loads executable images through section objects and mapped views; higher-level loader metadata is layered on top. Working at the `NtCreateSection`/`NtMapViewOfSection` level highlights the difference between "there is an executable image mapping" and "the loader has registered this module normally."

For research, the key question is artifact alignment: file object, section object, mapped image, PEB loader lists, DLL notifications, ETW image-load events, and import resolution should tell a coherent story. When they do not, PE and memory-forensics tools have something to investigate.

## Connections
- `perfect-loader` tries to preserve more official loader behavior while changing what is loaded.
- `ManualMap` and `MemJect` show cases where private mappings replace image-section semantics.

## References
- <https://github.com/kleiton0x00/Proxy-DLL-Loads>
