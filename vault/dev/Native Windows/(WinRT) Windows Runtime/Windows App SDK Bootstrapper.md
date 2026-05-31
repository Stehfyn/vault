# Windows App SDK Bootstrapper

The Windows App SDK is the successor to the UWP-only platform story: modern Windows UI and platform APIs are delivered through NuGet/framework packages so Win32, WPF, WinForms, and WinUI 3 apps can use them. The bootstrapper is the unpackaged-app mechanism: call `MddBootstrapInitialize*` early, bind the process to an installed Windows App Runtime package matching the requested major/minor version, then shut it down on exit.

This is not just a loader detail. It is the deployment contract that decides whether an unpackaged EXE can activate `Microsoft.UI.Xaml`, app notifications, app lifecycle APIs, MRT Core, and other WinAppSDK components. Failure modes are operational: missing runtime packages, version mismatch, preview tags, architecture mismatch, or apps that should instead ship self-contained.

```cpp
PACKAGE_VERSION minVersion{};
minVersion.Major = 1;
minVersion.Minor = 5;

HRESULT hr = MddBootstrapInitialize2(
    0x00010005, L"", minVersion,
    MddBootstrapInitializeOptions_OnNoMatch_ShowUI);
if (FAILED(hr)) {
    // Missing or incompatible Windows App Runtime; handle setup explicitly.
    return hr;
}

// Use WinAppSDK APIs here.
MddBootstrapShutdown();
```

## Source Contrast

Mozeiko's pure-C sample demonstrates the other deployment path: avoid runtime discovery and ship self-contained runtime files beside the EXE. That is not the bootstrapper model, but it is the right comparison when debugging activation failures.

```bat
makepri.exe new /pr . /cf main.priconfig.xml /of output\main.pri /o
copy /y packages\runtimes-framework\win-x64\native\Microsoft.WindowsAppRuntime.dll output\

cl.exe /Iincludes main.c /link /out:output\main.exe ^
  /manifest:embed /manifestinput:main.manifest
```

## Source Code Reading

`mmozeiko/hello-world-winui3-c/build.cmd` is a concrete package-graph lab. It downloads individual Windows App SDK NuGet packages, extracts headers/metadata/native runtime payloads, runs `winmdidl.exe` over `Microsoft.UI.Xaml.winmd`, stages runtime DLLs into `output\`, generates `main.pri`, embeds `main.manifest`, and links a normal `cl.exe` binary.

The actionable contrast:

- Bootstrapper path: call `MddBootstrapInitialize*`, let the dynamic dependency package graph resolve an installed Windows App Runtime, then activate `Microsoft.UI.*`.
- Self-contained path: place `Microsoft.WindowsAppRuntime.dll`, WinUI framework DLLs, PRI, manifest, and metadata-derived ABI headers beside the EXE, then activate without relying on machine-wide runtime registration.

```bat
winmdidl.exe /outdir:idl /metadata_dir:packages\metadata Microsoft.UI.Xaml.winmd
makepri.exe new /pr . /cf main.priconfig.xml /of output\main.pri /o
copy packages\runtimes-framework\win-x64\native\Microsoft.WindowsAppRuntime.dll output\
cl.exe /Iincludes main.c /link /manifest:embed /manifestinput:main.manifest
```

Claim -> source/probe -> interpretation:

Claim: `Microsoft.UI.Xaml.Application` activation is a runtime-binding test, not only a COM ABI test.
Source/probe: run the pure-C sample with the staged runtime DLLs removed, then run a bootstrapper sample with no Windows App Runtime installed. Log `RoGetActivationFactory("Microsoft.UI.Xaml.Application")`, loaded modules, and package-graph state.
Interpretation: a correct `IApplicationStatics` IID and vtable are insufficient if the Windows App Runtime cannot be found. A passing OS WinRT activation plus failing WinUI activation isolates deployment.

## Discussion Claim To Verify

Claim: bootstrapper failure in a packaged or Store-installed app is not the same bug as bootstrapper failure in an unpackaged app.

Why it matters to code: forum threads around `MddBootstrapInitialize` often collapse three states into one word, "packaged." A packaged app normally declares its framework dependency in the manifest. An unpackaged app uses the bootstrapper to add the Windows App Runtime framework package to its package graph. A self-contained app carries runtime files with the app and should not require bootstrapper initialization for that purpose.

Verification route:

1. Log whether the process has package identity with `GetCurrentPackageFullName`.
2. Call `MddBootstrapInitialize2` only in the unpackaged/framework-dependent configuration.
3. Immediately test `RoGetActivationFactory` for one OS WinRT class and one WinAppSDK class.
4. Record loaded modules such as `Microsoft.WindowsAppRuntime.dll`.
5. For dynamic-dependency experiments, use `MddGetGenerationId()` before and after adding/removing a dependency; do not use `GetCurrentPackageFullName` as package-graph proof.

```cpp
UINT32 len = 0;
LONG identity = GetCurrentPackageFullName(&len, nullptr);

UINT32 before = MddGetGenerationId();

HRESULT boot = MddBootstrapInitialize2(
    WINDOWSAPPSDK_RELEASE_MAJORMINOR,
    WINDOWSAPPSDK_RELEASE_VERSION_TAG_W,
    PACKAGE_VERSION{},
    MddBootstrapInitializeOptions_None);

UINT32 after = MddGetGenerationId();
HMODULE runtime = GetModuleHandleW(L"Microsoft.WindowsAppRuntime.dll");
wprintf(L"identity=%ld bootstrap=%08lx graph=%u->%u runtime=%p\n",
        identity, boot, before, after, runtime);
```

Interpretation: `APPMODEL_ERROR_NO_PACKAGE` from `GetCurrentPackageFullName` is normal for an unpackaged process and does not mean dynamic dependencies failed. A successful bootstrapper should make WinAppSDK framework content activatable; a packaged app failing with `ERROR_NOT_SUPPORTED` is a deployment/packaging route issue, not a vtable or `RoInitialize` issue.

Audited discussion links:

- <https://stackoverflow.com/questions/76301950/store-app-cant-call-mddbootstrapinitialize> - packaged/Store bootstrapper confusion; useful because it separates install location from supported initialization mode.
- <https://learn.microsoft.com/en-us/answers/questions/1291236/desktop-app-in-store-cannot-use-winui3> - same claim routed through Microsoft Q&A; the answer points at DDLM/package-graph requirements rather than ACLs.
- <https://github.com/microsoft/WindowsAppSDK/issues/1953> - bootstrapper exception report; useful as an HRESULT-first debugging example.

## References
- <https://github.com/microsoft/WindowsAppSDK> - source and documentation hub for Windows App SDK / Windows App Runtime.
- <https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/framework-packages/framework-packages-overview> - package graph and dynamic dependency overview.
- <https://learn.microsoft.com/en-us/windows/windows-app-sdk/deploy-unpackaged-apps> - deployment guide for unpackaged/framework-dependent Windows App SDK apps.
- <https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/win32/_dynamicdependency/> - Dynamic Dependency API reference.

## Connections
- `WinUI 3 in Pure C (No cppwinrt).md`, `WinUI 3 Without XAML.md`, and `Xaml Islands Minimal Win32 Host.md` all depend on this runtime-binding story once they move beyond toy activation.
- `Sandboxing Win32 Apps via MSIX.md` is the packaging alternative when bootstrapper failure modes are unacceptable.
- `../Windows Installer/MSIX Package Support Framework - Shims.md` and `../Windows Installer/msix-packaging - Cross-Platform MSIX SDK.md` are deployment-side companions.

## Experiment Harness

Goal: separate package identity, package graph mutation, and runtime activation.

```cpp
UINT32 len = 0;
LONG before = GetCurrentPackageFullName(&len, nullptr);
UINT32 graphBefore = MddGetGenerationId();

PACKAGE_VERSION minVersion{};
HRESULT hr = MddBootstrapInitialize(WINDOWSAPPSDK_RELEASE_MAJORMINOR,
    WINDOWSAPPSDK_RELEASE_VERSION_TAG_W, minVersion);

UINT32 graphAfter = MddGetGenerationId();
HMODULE runtime = GetModuleHandleW(L"Microsoft.WindowsAppRuntime.dll");
wprintf(L"identity=%ld bootstrap=%08lx graph=%u->%u runtime=%p\n",
        before, hr, graphBefore, graphAfter, runtime);
MddBootstrapShutdown();
```

Procedure: run with runtime installed, then on a clean VM or with a deliberately mismatched major/minor version; also inspect `Get-AppxPackage Microsoft.WindowsAppRuntime*`.

Measured signal: bootstrap HRESULT, runtime DLL loaded, Application event log entry, `GetCurrentPackageFullName` result, and dynamic-dependency generation ID.

Failure interpretation: `APPMODEL_ERROR_NO_PACKAGE` before bootstrap is normal for unpackaged apps and should remain a package-identity signal, not a package-graph signal. Bootstrap failure points to missing runtime, incompatible version tag, architecture mismatch, unsupported packaged context, or initialization order. Reference: <https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/win32/mddbootstrap/nf-mddbootstrap-mddbootstrapinitialize>.
