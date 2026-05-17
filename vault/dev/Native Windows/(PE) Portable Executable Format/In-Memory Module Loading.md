# In-Memory Module Loading

MemoryModule loads a DLL directly from a memory buffer without writing it to disk.

## Usage snippet
```c
data = ReadLibrary(&size);
handle = MemoryLoadLibrary(data, size);
addNumber = (addNumberProc)MemoryGetProcAddress(handle, "addNumbers");
_tprintf(_T("From memory: %d\n"), addNumber(1, 2));
MemoryFreeLibrary(handle);
```
Source: https://raw.githubusercontent.com/fancycode/MemoryModule/master/example/DllLoader/DllLoader.cpp

## References
- https://github.com/fancycode/MemoryModule

