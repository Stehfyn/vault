# Shell Link Tracking (Object IDs and Distributed Link Tracking)

When you move a target `.exe`/file and its `.lnk` shortcuts "follow" it, no process scanned for shortcuts. There is **no reverse index from a file to the shortcuts that point at it**. The knowledge runs the other direction and the fix-up is **lazy (pull), at resolve time**: each shortcut carries its target's *identity* (an NTFS object ID + last-known path), and when that one shortcut is resolved — clicked, or just displayed/refreshed by Explorer — the shell re-finds the target by identity and rewrites that shortcut's stored path. What looks like "moving the file updated the shortcuts" is really "Explorer resolved those shortcuts afterward, and each chased the file on its own."

This is the mechanism behind the `tracker-data lookup` / `path tracking` mentioned in `Shell Shortcuts.md`. That note covers `IShellLinkW`/`IPersistFile`; this one covers *why* resolution can repair a moved target.

## The two-part identity stored in every `.lnk`

A shell link is a COM-persisted binary object ([MS-SHLLINK]). Its `ExtraData` can include a **`TrackerDataBlock`**, whose entire job is link tracking. Verbatim from the spec:

> The TrackerDataBlock structure specifies data that can be used to resolve a link target if it is not found in its original location when the link is resolved. This data is passed to the Link Tracking service [MS-DLTW] to find the link target.

Field layout (exact values from the spec):

| Field | Size | Value / meaning |
| --- | --- | --- |
| `BlockSize` | 4 | MUST be `0x00000060` |
| `BlockSignature` | 4 | MUST be `0xA0000003` |
| `Length` | 4 | MUST be `0x00000058` |
| `Version` | 4 | MUST be `0x00000000` |
| `MachineID` | 16 | NULL-terminated string: **NetBIOS name** of the machine where the target last resided |
| `Droid` | 32 | **two GUIDs** (volume ID + object ID) used to find the target via the Link Tracking service |
| `DroidBirth` | 32 | two GUIDs: the *birth* volume/object IDs (stable across moves) |

So a `.lnk` self-describes its target by (machine, volume GUID, object-ID GUID) — independent of path. The plain target path is stored separately (`LinkInfo`/`LinkTargetIDList`); it's the *first* thing tried, and the `TrackerDataBlock` is the *fallback identity* when the path is stale.

Link: <https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-shllink/df8e3748-fba5-4524-968a-f72be06d71fc> (TrackerDataBlock)
Link: <https://learn.microsoft.com/en-us/windows/win32/shell/links> (Shell Links)

## NTFS object IDs: the forward index that makes "find by identity" cheap

The object-ID GUID in the `Droid` is an **NTFS object ID** — a per-file attribute. First-party statements:

> An object ID is an optional attribute that uniquely identifies a file or directory on a volume.
> An index of all object IDs is stored on the volume. Rename, backup, and restore operations preserve object IDs. However, copy operations do not preserve object IDs, because that would violate their uniqueness.

That on-volume index is the **forward map `object-ID -> file`** (NTFS stores it in the `\$Extend\$ObjId` metafile — an internal name, not an API contract; treat the *index* as the contract, not the filename). Because a **move within a volume preserves the object ID** but a **copy does not**, shortcuts follow moves and intentionally do *not* follow copies.

NTFS exposes opening a file directly by this ID, which is what makes resolution O(index lookup) rather than O(scan):

> NTFS allows files to be opened by object ID as well as by file reference number.
> On NTFS, the `FILE_OPEN_BY_FILE_ID` flag can open files using an 8-byte or 16-byte reference number or object ID.

Object-ID lifecycle is driven by FSCTLs, not normal file APIs:

- `FSCTL_CREATE_OR_GET_OBJECT_ID` — assign one if absent, else return existing (this is how a `.lnk` *acquires* the target's ID at creation/resolve).
- `FSCTL_GET_OBJECT_ID` — query (no creation).
- `FSCTL_SET_OBJECT_ID` / `_EXTENDED` — set (dangerous; IDs are meant to be opaque).

Returned in `FILE_OBJECTID_BUFFER`. Observe/repair from the shell with `fsutil objectid`.

Link: <https://learn.microsoft.com/en-us/windows/win32/fileio/distributed-link-tracking-and-object-identifiers>
Link: <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openfilebyid> (OpenFileById)
Link: <https://learn.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-file_id_descriptor> (FILE_ID_DESCRIPTOR)
Link: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id>
Link: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_get_object_id>
Link: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ns-winioctl-file_objectid_buffer>
Link: <https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-objectid>

## Resolution flow (lazy, per-shortcut)

`IShellLink::Resolve` is where it all happens — and only when invoked. First-party:

> When the `IShellLink::Resolve` method is called and the referent file cannot be found, for example, when the user activates a shell shortcut, the tracking service is called automatically to find the file.

Order of attempts when a stored path misses:

1. **Path-based heuristic search** ("shell shortcuts include heuristic link tracking that uses a tree search algorithm"): keyed on last-known path + creation date + file size + name/extension; searches N levels down/around the last directory, the desktop root, and each fixed drive. Same-volume nearby moves are usually caught here.
2. **Distributed Link Tracking** via the `Droid` IDs (`[MS-DLTW]`): the Distributed Link Tracking **Client** service (runs on every machine) finds local/same-volume moves via the object-ID index; cross-volume/cross-machine moves within a domain are resolved through the Distributed Link Tracking **Server** that runs on domain controllers and records volume/file move notifications.

`SLR_*` flags on `Resolve` gate this: `SLR_NO_UI` suppresses the repair dialog (use in services/tools), `SLR_NOUPDATE` prevents rewriting the `.lnk`, `SLR_NOSEARCH` disables the heuristic search, `SLR_NOTRACK` disables object-ID tracking.

Link: <https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve> (IShellLink::Resolve, SLR_ flags)
Link: <https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-dltw/fc649f0e-871a-431a-88b5-d5b2f80e9cc9> ([MS-DLTW])

## Claim -> source/probe -> interpretation

Claim: there is no file->shortcuts reverse index; tracking is pull, not push.
Source/probe: the spec frames `TrackerDataBlock` as data consulted "when the link is resolved", and DLT docs state the service is invoked from `IShellLink::Resolve` "when the user activates a shell shortcut". Probe: move the target with all Explorer windows closed; inspect a `.lnk` with a hex viewer — its stored path is still stale until you open the folder/click it.
Interpretation: nothing touches the `.lnk` at move time. The rewrite is a side effect of resolving that specific shortcut.

Claim: shortcuts follow moves but not copies.
Source/probe: "Rename, backup, and restore operations preserve object IDs. However, copy operations do not preserve object IDs." Probe: `fsutil objectid query target.exe`; move it (same volume) -> ID unchanged; copy it -> the copy has no/`different` ID.
Interpretation: the move-vs-copy asymmetry the user sees is by design — identity rides the moved inode, not the bytes.

Claim: the match can succeed even with a wrong/garbage stored path.
Source/probe: the heuristic tree search uses creation date + size + name, and DLT uses the object-ID GUID; both ignore the literal path string. Probe: hand-edit a `.lnk` path to a sibling folder, then `Resolve` with `SLR_NO_UI` and read back `GetPath`.
Interpretation: a `.lnk` is not a static path alias; resolution is allowed to "repair" to a different path than was stored.

## Probe / Experiment Harness

Motivating scenario (observed): moving `WinMainEx.exe` between folders caused Start-Menu/desktop `.lnk`s to repoint. Reproduce and instrument:

```cmd
:: 1. give the target an object ID and record it
fsutil objectid query "C:\dev\WinMainEx\WinMainEx\x64\Release\WinMainEx.exe"
fsutil objectid create "C:\dev\WinMainEx\WinMainEx\x64\Release\WinMainEx.exe"

:: 2. create a shortcut, move the exe, then resolve and compare
```

```cpp
// Query the NTFS object ID directly (the GUID a .lnk Droid would store).
HANDLE h = CreateFileW(target, 0, FILE_SHARE_READ | FILE_SHARE_WRITE,
                       nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
FILE_OBJECTID_BUFFER ob{}; DWORD br = 0;
DeviceIoControl(h, FSCTL_CREATE_OR_GET_OBJECT_ID, nullptr, 0,
                &ob, sizeof(ob), &br, nullptr);   // ob.ObjectId = 16-byte GUID

// Re-open the same file by that object ID after it has moved (no path needed):
FILE_ID_DESCRIPTOR id{ sizeof(id) };
id.Type = ObjectIdType;
memcpy(&id.ObjectId, ob.ObjectId, sizeof(id.ObjectId));
HANDLE volRoot = CreateFileW(L"\\\\?\\C:\\", 0,
    FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
    FILE_FLAG_BACKUP_SEMANTICS, nullptr);
HANDLE moved = OpenFileById(volRoot, &id, GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, 0);  // succeeds across same-volume move
```

```cpp
// Watch a shortcut repair itself, without launching the target.
link->Resolve(nullptr, SLR_NO_UI | SLR_NOUPDATE);   // NOUPDATE = inspect without rewriting
wchar_t before[MAX_PATH]{}; WIN32_FIND_DATAW fd{};
link->GetPath(before, ARRAYSIZE(before), &fd, SLGP_RAWPATH);
// drop SLR_NOUPDATE to let the .lnk actually rewrite to the new location
```

Measured signal: `fsutil objectid` GUID stability across move vs copy; `OpenFileById` success after move; `Resolve` HRESULT and pre/post `GetPath`; whether the `.lnk` bytes change only after a non-`SLR_NOUPDATE` resolve.

Failure interpretation: object IDs are **NTFS 3.0+ only** and **per-volume**; moving the target to FAT/exFAT, to removable media, or doing the move from an older OS *loses* tracking data (no harm to the file, just untrackable). The DLT client does not see a newly created NTFS volume until reboot.

## Connections

- `Shell Shortcuts.md` — the `IShellLinkW`/`IPersistFile`/`Resolve` API surface this note explains the tracking internals of.
- `Shell Items and Folders.md` — `LinkTargetIDList` (PIDL) is the other identity a `.lnk` stores alongside path + tracker data.
- `Known Folders.md` — where Start-Menu/Desktop `.lnk`s that exhibit this behavior actually live.
- `(NTAPI) Undocumented Kernel/` — FSCTL/`NtCreateFile` `FILE_OPEN_BY_FILE_ID` is the native edge of `OpenFileById`.

## Sources (first-party)

- Distributed Link Tracking and Object Identifiers: <https://learn.microsoft.com/en-us/windows/win32/fileio/distributed-link-tracking-and-object-identifiers>
- [MS-SHLLINK] TrackerDataBlock: <https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-shllink/df8e3748-fba5-4524-968a-f72be06d71fc>
- Shell Links overview: <https://learn.microsoft.com/en-us/windows/win32/shell/links>
- IShellLink::Resolve: <https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve>
- [MS-DLTW] Distributed Link Tracking Workstation Protocol: <https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-dltw/fc649f0e-871a-431a-88b5-d5b2f80e9cc9>
- OpenFileById: <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openfilebyid>
- FILE_ID_DESCRIPTOR: <https://learn.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-file_id_descriptor>
- FSCTL_CREATE_OR_GET_OBJECT_ID: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id>
- FSCTL_GET_OBJECT_ID: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_get_object_id>
- FSCTL_SET_OBJECT_ID: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id>
- FILE_OBJECTID_BUFFER: <https://learn.microsoft.com/en-us/windows/win32/api/winioctl/ns-winioctl-file_objectid_buffer>
- fsutil objectid: <https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-objectid>
