## References
- https://learn.microsoft.com/en-us/windows/win32/api/fdi/ns-fdi-fdicabinetinfo

FDICABINETINFO carries cabinet metadata returned by FDIIsCabinet, such as total size and file count.

```c
#include <fdi.h>

FDICABINETINFO info = {0};
if (FDIIsCabinet(hfdi, hFile, &info)) {
    printf("cab bytes=%ld files=%u\n", info.cbCabinet, info.cFiles);
}
```
