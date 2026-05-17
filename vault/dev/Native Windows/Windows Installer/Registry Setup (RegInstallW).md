## References
- https://learn.microsoft.com/en-us/windows/win32/api/advpub/nf-advpub-reginstallw

RegInstallW applies registry updates described in a module’s RegInstall sections, using a string table to substitute values at install time.

```c
#include <advpub.h>

STRTABLEW table[] = {
    { L"INSTALLDIR", L"C:\\Program Files\\MyApp" },
    { NULL, NULL }
};

HRESULT hr = RegInstallW(hModule, L"RegInstall", table);
```
