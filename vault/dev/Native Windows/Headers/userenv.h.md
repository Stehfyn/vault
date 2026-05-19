# userenv.h

User profile, environment block, and Group Policy registry-merge APIs in `userenv.dll`. The headliners are `LoadUserProfileW` / `UnloadUserProfile` (the only supported way to mount HKCU for a token you got from `LogonUser`), `CreateEnvironmentBlock` / `ExpandEnvironmentStringsForUserW` (build a per-user environment for `CreateProcessAsUser`), `GetUserProfileDirectoryW` (resolve %USERPROFILE% for an arbitrary token), and `GetProfilesDirectoryW`. Critical for service-side impersonation work: if you `CreateProcessAsUser` without first calling `LoadUserProfile` you get the Default user's HKCU, which silently breaks anything that reads `HKCU\Software\...`. Cluster: `profinfo.h` (PROFILEINFO struct), `winuser.h` (token rights), `wtsapi32.h` (session enumeration).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/userenv/>
