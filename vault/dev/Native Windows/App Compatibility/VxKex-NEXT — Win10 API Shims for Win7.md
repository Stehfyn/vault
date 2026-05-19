# VxKex-NEXT - Win10 API Shims for Win7

VxKex-NEXT continues the Windows 7 API-extension idea with broader Win10/Win11-era coverage. It is useful to track because the compatibility target moved: many modern desktop apps now fail due to UCRT, bcrypt, kernelbase, appmodel, or shell expectations that were not common when the original VxKex was written.

Read it as a maintenance case study. Compatibility shims age quickly because applications start depending on newer error semantics, side effects, and API-set layout, not just export names. Connect this to `VxKex`, `OneCoreAPI`, and `App Compat Cache` for the loader/shim/cache boundary.

## References
- <https://github.com/YuZhouRen86/VxKex-NEXT>
