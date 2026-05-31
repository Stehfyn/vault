# Msi.h — Windows Installer API Header

`Msi.h` is the top-level Windows Installer API for products, features, components, installation sessions, and advertised shortcuts. It exposes entry points such as `MsiInstallProduct`, `MsiConfigureProductEx`, `MsiGetProductInfo`, and install-handle APIs used by custom actions.

The important distinction is that MSI is a database-driven transaction engine, not a script runner. Calling the API starts or queries an action graph whose behavior is determined by tables, properties, component rules, per-user/per-machine context, elevation, and source resiliency.

## Engine Call Shape

`MsiInstallProductW` takes a package path plus public-property command line; it does not take a list of files to copy. UI and logging are separate process-global settings, so diagnostic tools should set them before invoking the engine.

```c
MsiSetInternalUI(INSTALLUILEVEL_NONE, NULL);
MsiEnableLogW(INSTALLLOGMODE_VERBOSE, L"install.log", INSTALLLOGATTRIBUTES_APPEND);
UINT rc = MsiInstallProductW(L"C:\\pkg\\app.msi",
                             L"ACTION=INSTALL ALLUSERS=1");
```

## Source Code Reading

The SDK and classic samples show two different code boundaries:

1. External engine caller:

```text
MsiSetInternalUI
MsiEnableLog
MsiInstallProductW(package, public-property string)
inspect UINT Windows Installer return code
```

2. Native custom action DLL:

```cpp
extern "C" __declspec(dllexport)
UINT __stdcall MyAction(MSIHANDLE hInstall) {
    // query session properties through MsiGetProperty/MsiSetProperty
    // return ERROR_SUCCESS or an MSI error code
}
```

The distinction matters because the external caller owns process UI/logging setup, while the custom action runs inside `msiexec.exe` with bitness, impersonation, sequencing, and deferred/custom-action-data rules imposed by the installer engine.

Claim -> source/probe -> interpretation:
- Claim: "Calling `MsiInstallProductW` is equivalent to `msiexec /i`."
- Source/probe: run both with identical public properties and verbose logs.
- Interpretation: the engine path should converge, but UI level, current directory, elevation, logging, source resolution, and quoting often differ in harness code.

## Experiment Harness

Wrap engine calls with log and return-code capture. Then compare silent API install with command-line `msiexec` using the same public properties.

```powershell
msiexec /i C:\pkg\app.msi ACTION=INSTALL ALLUSERS=1 /qn /l*v cli.log
.\msi_install_harness.exe C:\pkg\app.msi "ACTION=INSTALL ALLUSERS=1"
fc cli.log api.log
```

Signal: same final Windows Installer return code and same high-level action sequence. Failure interpretation: diverging behavior usually means UI level, property quoting, elevation context, current directory/source resolution, or logging setup differs between the two routes.

## Connections
- `MsiQuery.h` is for reading/editing MSI database tables directly.
- `MSI Search Conditions` explains one common way properties are populated before install actions run.
- `DLL Build Config` is the native custom-action deployment boundary: bitness and CRT linkage must match the `msiexec.exe` host context.
- `Registry Setup (RegInstallW)` is the non-transactional legacy contrast.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/msi/>
- <https://learn.microsoft.com/en-us/windows/win32/api/msi/nf-msi-msiinstallproductw>
