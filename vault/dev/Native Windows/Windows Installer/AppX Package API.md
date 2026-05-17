## References
- https://learn.microsoft.com/en-us/windows/win32/api/_appxpkg/

The AppX packaging APIs live in appxpackaging.h and provide COM interfaces like IAppxFactory for reading package manifests.

```c
#include <appxpackaging.h>

IAppxFactory* factory = nullptr;
CoCreateInstance(__uuidof(AppxFactory), nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&factory));

IAppxPackageReader* reader = nullptr;
factory->CreatePackageReader(stream, &reader);
```
