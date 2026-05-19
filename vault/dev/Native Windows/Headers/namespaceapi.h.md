# namespaceapi.h

Private object-namespace API: `CreateBoundaryDescriptorW` + `AddSIDToBoundaryDescriptor` define a "boundary" (a SID-bound trust scope), and `CreatePrivateNamespaceW` mounts a kernel-object namespace inside that boundary. Inside that namespace, names like `mutex_foo` won't collide with the same name in the global `\BaseNamedObjects` namespace, and only callers whose token contains every SID in the boundary descriptor can open the namespace's objects. This is the supported way to give an application a per-session-or-package-scoped name space for `CreateMutex`, `CreateEvent`, `CreateFileMapping` -- it's what makes `Local\` and `Global\` look natural to user code, and how AppContainer apps get their own isolated namespace under `\Sessions\<n>\AppContainerNamedObjects\<sid>`. Cluster: `winbase.h` for the `CreateMutex` consumers, `securitybaseapi.h` for SID assembly, `processthreadsapi.h` for the AppContainer token side.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/namespaceapi/>
- <https://learn.microsoft.com/en-us/windows/win32/sync/object-namespaces>
