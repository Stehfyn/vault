# MFC Zip

The CodeProject ZipArchive article/library is a period piece but still explains a common MFC-era pattern: wrap a native file format library in `CString`, `CFile`, progress callbacks, and exception conventions that fit an MFC application instead of exposing a lower-level zlib-style API. Its value is in the integration style, not in proving ZIP itself is hard.

Use this note when reviewing older utilities that bundle compression directly into an MFC UI. The questions to ask are encoding (`TCHAR`/Unicode paths), ZIP64 support, password/encryption expectations, large-file behavior, and whether the app should now use a maintained library or Windows Shell compression APIs instead.

## References
- <https://www.codeproject.com/Articles/611/Zip-and-Unzip-in-the-MFC-way> - classic MFC-oriented ZipArchive implementation and usage article.
