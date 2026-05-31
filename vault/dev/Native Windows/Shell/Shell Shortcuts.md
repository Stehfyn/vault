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

Claim -> source/probe -> interpretation:

Claim: creating a `.lnk` is COM persistence, not file-format writing.
Source/probe: the Stack Overflow answer's core sequence is `CoCreateInstance(CLSID_ShellLink) -> IShellLink::SetPath/SetDescription -> QueryInterface(IID_IPersistFile) -> IPersistFile::Save`. Probe by creating a shortcut, then reopening it through `IPersistFile::Load` and reading the target with `IShellLink::GetPath`.
Interpretation: no text serializer is involved. If save succeeds but Explorer displays unexpected metadata, inspect the shell-link properties through COM rather than parsing bytes.

Claim: Unicode conversion is not optional at the persistence boundary.
Source/probe: the answer converts the link-file path to `WCHAR` before `IPersistFile::Save`; even ANSI `IShellLinkA` code must cross a wide `IPersistFile` API.
Interpretation: mixed ANSI/Unicode samples often work by accident for ASCII paths and fail for user-profile, localized, or cloud-provider paths. Prefer `IShellLinkW` end to end.

## Verification Route

Claim: a shell shortcut is also a property bag; for toasts and taskbar identity, `SetPath` is not the interesting part.

Why it matters to code: desktop toast samples and app identity samples often say "create a shortcut" but the critical payload is not the target path. It is the property store attached to the link: `PKEY_AppUserModel_ID`, optional `PKEY_AppUserModel_ToastActivatorCLSID`, relaunch metadata, and sometimes icon/arguments.

```cpp
wil::com_ptr<IShellLinkW> link;
wil::com_ptr<IPropertyStore> props;
CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link));

link->SetPath(exePath);
link.query_to(&props);

PROPVARIANT v{};
InitPropVariantFromString(appUserModelId, &v);
props->SetValue(PKEY_AppUserModel_ID, v);
props->Commit();
PropVariantClear(&v);
```

Probe: create two shortcuts to the same EXE, one with only `SetPath`, one with AUMID property-store values. Read both back through `IPersistFile::Load` + `IPropertyStore::GetValue`, then run the toast probe against each AUMID.

Interpretation: both shortcuts launch. Only the property-bearing one contributes app identity for notification/taskbar behaviors. This is why shortcut creation belongs in the toast route, not just the "launch a file" route.

Connections: `Shell Execute.md` consumes the verb/launch side; `Known Folders.md` is where shortcut placement should be resolved; `Shell Items and Folders.md` is the richer PIDL/`IShellItem` world when a shortcut target is not a normal file path; `Shell Link Tracking (Object IDs and Distributed Link Tracking).md` explains the `TrackerDataBlock`/NTFS-object-ID/DLT machinery behind `Resolve` repairing a moved target.

## Experiment Harness

Goal: test shortcut resolution behavior without launching the target.

```cpp
link->Resolve(hwnd, SLR_NO_UI | SLR_NOUPDATE | SLR_NOSEARCH);
wchar_t raw[MAX_PATH]{}, normal[MAX_PATH]{};
WIN32_FIND_DATAW fd{};
link->GetPath(raw, ARRAYSIZE(raw), &fd, SLGP_RAWPATH);
link->GetPath(normal, ARRAYSIZE(normal), &fd, 0);
wprintf(L"raw=%ls normal=%ls\n", raw, normal);
```

Procedure: create shortcuts to an existing file, deleted file, environment-variable path, and network path; compare flags.

Measured signal: `Resolve` HRESULT, raw path, normalized path, UI/no-UI behavior, elapsed time.

Failure interpretation: repair dialogs, MSI advertised shortcuts, and path tracking are part of shell-link behavior; a `.lnk` is not a static text alias. Reference: <https://learn.microsoft.com/en-us/windows/win32/shell/links>.
