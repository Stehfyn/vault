# File API From App

The `*FromApp` file APIs are the AppContainer-friendly variants of classic file functions. `MoveFileFromAppW` looks mundane until you need desktop-style file work from a packaged app, where capability checks, brokered access, and Store policy replace the assumptions behind `MoveFileW`.

Keep this near MSIX/AppContainer notes rather than ordinary file I/O. It connects to `Known Folders`, `ShellExecute and File Operations`, and `YY-Thunks`: all three show how a familiar Win32 call can mean different things depending on package identity, OS vintage, and loader surface.

Boundary shape:

```cpp
BOOL moved = MoveFileFromAppW(existing_path, new_path);
DWORD err = moved ? ERROR_SUCCESS : GetLastError();
```

The useful comparison is `MoveFileW` versus `MoveFileFromAppW`: same user intent, different package/capability enforcement path. When a packaged desktop app fails only under MSIX/AppContainer identity, this family of APIs is a better lead than generic file-copy code.

## Source Code Reading

This topic is also first-party API driven. The source-shaped detail is that the `*FromApp` calls are not broader versions of classic file APIs; they are the package/AppContainer-aware entry points for the same file intent.

A useful contract matrix:

```text
CreateFile2FromAppW
  inputs: app-visible path, access mask, share mode, creation disposition, CREATEFILE2_EXTENDED_PARAMETERS
  output: HANDLE or INVALID_HANDLE_VALUE + GetLastError
  variable: package identity, capabilities, brokered path grants

MoveFileFromAppW
  inputs: existing path, new path
  output: BOOL + GetLastError
  variable: whether both paths are permitted to the app identity
```

The verifiable claim is not "this moves files." It is "the same path and access mask can produce different results under unpackaged desktop identity versus packaged/AppContainer identity."

```text
claim: path class matters under package identity
probe: compare app-local data, install directory, removable library/capability path, and arbitrary `C:\Temp`

claim: picker/brokered grants change access
probe: open the same path before and after a brokered picker grant; compare GetLastError

claim: classic and FromApp entry points are not diagnostic substitutes
probe: run `CreateFileW` and `CreateFile2FromAppW` in the same packaged context and log both results
```

Source files read:
- Microsoft `CreateFile2FromAppW` documentation
- Microsoft `MoveFileFromAppW` documentation
- Microsoft packaged-app file-access documentation

## Experiment Harness

Goal: compare ordinary Win32 file intent with package/AppContainer file policy.

Procedure:

```cpp
CREATEFILE2_EXTENDED_PARAMETERS xp = {};
xp.dwSize = sizeof(xp);
xp.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;

const wchar_t* local_path = L"<ApplicationData.LocalFolder.Path>\\allowed-local-test.txt";
const wchar_t* outside_path = L"C:\\Temp\\outside-test.txt";

HANDLE local = CreateFile2FromAppW(local_path,
                                   GENERIC_READ | GENERIC_WRITE,
                                   FILE_SHARE_READ, CREATE_ALWAYS, &xp);
DWORD local_err = local == INVALID_HANDLE_VALUE ? GetLastError() : ERROR_SUCCESS;

HANDLE outside = CreateFile2FromAppW(outside_path,
                                     GENERIC_READ | GENERIC_WRITE,
                                     FILE_SHARE_READ, OPEN_EXISTING, &xp);
DWORD outside_err = outside == INVALID_HANDLE_VALUE ? GetLastError() : ERROR_SUCCESS;

printf("local=%p gle=%lu outside=%p gle=%lu\n",
       local, local_err, outside, outside_err);
```

Signals to record: packaged/unpackaged identity, AppContainer status, manifest capabilities, path category, handle result, `GetLastError`, and whether the same path succeeds through a picker or declared capability. Expected baseline: app data/install locations and brokered picks behave differently from arbitrary paths. A failure on an arbitrary absolute path is usually the point of the experiment, not a filesystem bug.

## Discussion Claim Verification

Claim: "`CreateFile2FromAppW` is just `CreateFileW` with a different name."

Why it matters for new diagnostic code: packaged identity and file capabilities are the variable. A diagnostic that only logs path and access mask misses the policy boundary that explains the failure.

How to verify:
1. Run the same probe unpackaged and packaged.
2. Test app-local data, package install directory, user-selected/brokered file, declared capability location, and arbitrary `C:\Temp`.
3. Log `GetCurrentPackageFullName`/identity status beside every handle result.
4. Compare `CreateFileW` and `CreateFile2FromAppW` only inside the same identity context.

Minimal code/pseudocode:

```cpp
for path in test_paths:
  HANDLE a = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
  DWORD ea = a == INVALID_HANDLE_VALUE ? GetLastError() : 0;

  HANDLE b = CreateFile2FromAppW(path, GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING, &xp);
  DWORD eb = b == INVALID_HANDLE_VALUE ? GetLastError() : 0;

  log(package_identity(), path_kind(path), ea, eb);
```

Interpretation: the first-party links support AppContainer-aware file API semantics. They do not support diagnosing packaged-app file failures from filesystem ACLs alone. If the same path succeeds unpackaged and fails packaged, capability/brokered-access policy is the first suspect.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-movefilefromappw>
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-createfile2fromappw>
- <https://learn.microsoft.com/en-us/windows/apps/develop/files/file-access-permissions>
