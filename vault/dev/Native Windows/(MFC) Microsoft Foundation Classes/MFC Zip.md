# MFC Zip

## References
- https://www.codeproject.com/Articles/611/Zip-and-Unzip-in-the-MFC-way

## ZipArchive usage snippet
```cpp
#include "ZipArchive.h"

CZipArchive zip;
zip.Open(_T("archive.zip"), CZipArchive::zipCreate);
zip.AddFile(_T("input.txt"), _T("input.txt"));
zip.Close();

CZipArchive unzip;
unzip.Open(_T("archive.zip"), CZipArchive::zipOpenReadOnly);
unzip.ExtractFile(0, _T("output.txt"));
unzip.Close();
```
