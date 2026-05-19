# Win32 Bind Shell Reference

This reference is a minimal WinSock/process-redirection example in the shape historically used by bind shells. The defensive value is recognizing the composition: socket listener, accepted client handle, redirected standard handles, and child process launch.

Do not treat it as a build recipe. Use it to map telemetry: unexpected listening sockets, console child processes without an interactive parent, inherited socket handles, and command interpreters whose stdio is not attached to a console. Connect this to service persistence and process-snippet entries.

Code contribution: classify the pattern around `socket`/`accept`, inherited handles, `STARTF_USESTDHANDLES`, and child process launch telemetry.

## References
- <https://github.com/melardev/C_Win32_BindShell_Sync/blob/master/main.c>
