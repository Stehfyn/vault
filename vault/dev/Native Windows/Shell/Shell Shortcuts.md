# Shell Shortcuts

Per-link references for .lnk operations.

## Shell links overview
Link: https://learn.microsoft.com/en-us/windows/win32/shell/links
Brief: Load and resolve a shortcut target.
```cpp
IShellLinkW* link = NULL;
CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link));
IPersistFile* pf = NULL;
link->QueryInterface(IID_PPV_ARGS(&pf));
pf->Load(L"C:\\Temp\\sample.lnk", STGM_READ);
WCHAR target[MAX_PATH];
link->GetPath(target, MAX_PATH, NULL, 0);
```

## Create a shortcut (Stack Overflow)
Link: https://stackoverflow.com/questions/3906974/how-to-programmatically-create-a-shortcut-using-win32
Brief: Build a shortcut and save it with IPersistFile.
```cpp
IShellLinkW* link = NULL;
CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link));
link->SetPath(L"C:\\Tools\\app.exe");
link->SetArguments(L"--help");
IPersistFile* pf = NULL;
link->QueryInterface(IID_PPV_ARGS(&pf));
pf->Save(L"C:\\Temp\\app.lnk", TRUE);
```

