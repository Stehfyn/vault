# Shell Shortcuts

`.lnk` files are COM-persisted shell objects, not INI files. The API boundary is `IShellLinkW` for target/arguments/icon/working-directory metadata and `IPersistFile` for loading/saving. Treat them as shell namespace artifacts: resolving a link can trigger network paths, MSI advertised shortcuts, relative path repair, and tracker-data lookup.

## Resolve an existing link
Link: https://learn.microsoft.com/en-us/windows/win32/shell/links

Contribution: the official shell-links page is valuable for the `Resolve` step, not just property getters. `SLR_NO_UI` avoids hanging a service/tool on a repair dialog; `SLGP_RAWPATH` versus normal path retrieval changes whether environment variables and short paths are expanded.

```cpp
wil::com_ptr<IShellLinkW> link;
CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&link));

wil::com_ptr<IPersistFile> file;
link.query_to(&file);
file->Load(LR"(C:\Users\me\Desktop\App.lnk)", STGM_READ);

link->Resolve(hwnd, SLR_NO_UI | SLR_NOUPDATE);

wchar_t target[MAX_PATH] = {};
WIN32_FIND_DATAW data = {};
link->GetPath(target, ARRAYSIZE(target), &data, SLGP_RAWPATH);
```

## Create a shortcut
Link: https://stackoverflow.com/questions/3906974/how-to-programmatically-create-a-shortcut-using-win32

Contribution: the useful code pattern is the `IShellLinkW` / `IPersistFile` handoff. It also shows the Unicode trap: `IPersistFile::Save` takes a wide path regardless of whether the rest of the shell-link object was created through the ANSI or Unicode interface.

```cpp
wil::com_ptr<IShellLinkW> link;
CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&link));

link->SetPath(LR"(C:\Windows\System32\notepad.exe)");
link->SetArguments(LR"(C:\Temp\notes.txt)");
link->SetWorkingDirectory(LR"(C:\Temp)");
link->SetDescription(L"Open notes in Notepad");

wil::com_ptr<IPersistFile> file;
link.query_to(&file);
file->Save(LR"(C:\Users\me\Desktop\Notes.lnk)", TRUE);
```

Connections: `Shell Execute.md` consumes the verb/launch side; `Known Folders.md` is where shortcut placement should be resolved; `Shell Items and Folders.md` is the richer PIDL/`IShellItem` world when a shortcut target is not a normal file path.
