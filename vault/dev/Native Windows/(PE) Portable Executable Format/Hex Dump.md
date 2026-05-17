# Hex Dump

## win32CanonicalHexdump Output.cpp (raw)
https://raw.githubusercontent.com/SenpaiSilver/win32CanonHexdump/master/src/win32CanonicalHexdump/Output.cpp  
Brief: Format a single 16-byte line with hex bytes and ASCII gutter.
```cpp
_tprintf(TEXT("%08x  "), addr);
for (unsigned i = 0; i < 16; ++i)
    _tprintf(i < nb ? TEXT("%02X ") : TEXT("   "), buffer[i]);
_tprintf(TEXT("|"));
for (unsigned i = 0; i < nb && i < 16; ++i)
    _tprintf(TEXT("%c"), buffer[i] < ' ' ? '.' : buffer[i]);
```

## win32CanonHexdump repository
https://github.com/SenpaiSilver/win32CanonHexdump  
Brief: Read bytes and emit formatted lines until EOF.
```cpp
DWORD addr = 0, read = 0;
while (ReadFile(hFile, buffer, sizeof(buffer), &read, nullptr) && read)
{
    DumpLine(addr, buffer, read);
    addr += read;
}
```
