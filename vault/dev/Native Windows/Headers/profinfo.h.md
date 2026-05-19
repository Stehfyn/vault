# profinfo.h

Contains only the `PROFILEINFOW` / `PROFILEINFOA` struct and the `PI_*` flag constants -- split out of `userenv.h` so the struct can be shared with kernel-mode profile code. Passed to `LoadUserProfileW` to choose between a roaming-vs-local profile, suppress the UI (`PI_NOUI`), or apply Group Policy (`PI_APPLYPOLICY`). The `lpProfilePath` field lets you point at an arbitrary roaming profile location, which is exactly what `runas /profile`, RDS, and service-side impersonation use. Header is small and exists basically to break a `userenv.h` / `winnt.h` include cycle.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/profinfo/ns-profinfo-profileinfow>
