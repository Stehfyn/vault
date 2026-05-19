# CallMeWin32kDriver — Win32k Subsystem Driver Trick

This project demonstrates a registry-mediated loading path for a driver adjacent to the Win32k subsystem rather than a normal SCM-created service. The interesting point is not the mechanics of adding a value; it is the boundary it probes: GUI-session kernel code, shadow syscall tables, and the historical split between the NT executive and the USER/GDI subsystem living behind `win32k.sys`.

The entry belongs in the registry section because the persistence/load trigger is configuration under Session Manager, not an installer API. It also belongs near security material: any technique that changes driver load posture is inseparable from code integrity, signing policy, kernel attack surface, and the fact that subsystem-loaded components are not managed like ordinary service drivers.

## Connections
- `AccessMask Decoder` is relevant when inspecting the key permissions and service-driver handles used around this technique.
- `winnt.h` and `ntdll.lib` provide the NT vocabulary that user-mode tooling uses when probing these subsystem boundaries.

## References
- <https://github.com/gmh5225/CallMeWin32kDriver>
