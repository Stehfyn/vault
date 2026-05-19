# PPL Killer (Capcom Driver)

The Capcom-driver PPLKiller is the older, compact example of Protected Process Light bypass through a vulnerable signed driver. Its importance is historical and architectural: PPL is enforced by kernel metadata, so arbitrary kernel write capability can collapse the protection regardless of the user-mode access model.

For defenders, treat this as a BYOVD case study. Relevant signals are vulnerable-driver presence, service-load events, device handles, attempts to alter protected-process state, and subsequent access to processes such as LSASS. Connect this to the RTCore64 PPLKiller and Microsoft vulnerable-driver blocklist discussions.

Code contribution: focus on `NtLoadDriver`, service creation, driver device handles, protected-process metadata writes, and post-write access attempts rather than reproducing the primitive.

## References
- <https://github.com/Mattiwatti/PPLKiller>
