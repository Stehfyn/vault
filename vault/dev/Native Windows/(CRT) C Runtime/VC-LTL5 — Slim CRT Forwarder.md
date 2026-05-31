# VC-LTL5 — Slim CRT Forwarder to System DLL

VC-LTL is a compatibility and size tactic: keep MSVC source-level CRT expectations, but replace the normal static CRT libraries with import/forwarder libraries that resolve as much as possible to system CRT DLLs such as `msvcrt.dll` or `ucrtbase.dll`. That yields much smaller binaries than `/MT` while avoiding a separate redist for some targets. The cost is that you are now relying on the exact CRT surface present on the target OS, so feature selection and minimum-OS targeting become part of the link step rather than a packaging afterthought.

This is not the same as no-CRT programming. C++ initialization, security helpers, floating-point support, and allocator semantics still exist; VC-LTL just changes where implementation bodies come from. It pairs naturally with API thunk projects when a modern toolchain is used to produce binaries for old Windows versions.

## Source Code Reading

The `VC-LTL5` repository is structured like a build-system intervention plus a compatibility CRT subset, not a single runtime DLL.

Files worth reading first:
- `Directory.Build.props`
- `Nuget/build/native/VC-LTL.props`
- `Nuget/build/net8.0-windows7.0/VC-LTL.targets`
- `Sources/crt/vcruntime/winapi_thunks.cpp`
- `Sources/crt/vcruntime/winapi_downlevel.cpp`
- `Sources/ltl/debug_heap.cpp`
- `Sources/crt/LTL_Tools.h`

The important composition is build-time:

```text
MSBuild project
  -> imports VC-LTL.props / VC-LTL.targets
  -> changes library search/order and target policy
  -> links LTL libraries/shims instead of the default CRT shape
  -> unresolved modern Win32 calls can route through downlevel thunk code
```

For code review, look for three concrete effects:
1. Which CRT object/library names are substituted by the `.props`/`.targets`.
2. Which modern API calls are hard imports versus wrapper/thunk calls in `winapi_thunks.cpp`.
3. Whether allocator/debug-heap behavior crosses a DLL ABI boundary. VC-LTL keeps CRT semantics alive; it does not make `malloc` memory safe to free from an arbitrary module.

Experiment: build the same small C++ program with the normal MSVC CRT and with VC-LTL, then compare `dumpbin /imports`, file size, and minimum-OS behavior in a VM. The code under test should include one C++ global object, one `new/delete`, and one newer Win32 call so both startup and thunk policy are visible.

## Discussion Claim Verification

Claim: "VC-LTL gives no-CRT-size binaries without changing source."

Why it matters for new code: VC-LTL is a linker/runtime substitution strategy, not a semantic eraser. It can reduce static CRT weight and improve downlevel targeting, but C++ startup, allocator rules, exception/unwind dependencies, and API availability still have to be audited.

How to verify:

```powershell
msbuild app.vcxproj /p:Configuration=Release /p:Platform=x64 /bl:normal.binlog
msbuild app.vcxproj /p:Configuration=Release /p:Platform=x64 /p:UseVCLTL=true /bl:vcltl.binlog
dumpbin /imports x64\Release\app.exe
dumpbin /dependents x64\Release\app.exe
link /dump /loadconfig x64\Release\app.exe
```

Minimal code/pseudocode:

```cpp
struct G { G(); ~G(); } g;
int main() {
    auto p = new int(7);
    delete p;
    return 0;
}
```

Interpretation: if the binary still has initializer tables, C++ unwind metadata, allocator calls, or vcruntime/ucrt dependencies, the verified claim is "different CRT/provider shape," not "no CRT." Nullify claims that VC-LTL makes cross-DLL CRT ownership safe; it does not change the exported ABI contract of your DLL.

## Connections
- `CRT Linkage (MD MT DLL)` gives the baseline model VC-LTL bends.
- `Binary Size Reduction` and `No-CRT Win32` are more aggressive approaches when CRT semantics are disposable.

## References
- <https://github.com/Chuyu-Team/VC-LTL5>
