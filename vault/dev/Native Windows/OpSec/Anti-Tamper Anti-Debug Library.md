# Anti-Tamper Anti-Debug Library

`RebirthGuard` packages common anti-debug, anti-tamper, and environment checks behind a small C++ interface. Its contribution is breadth rather than novelty: it shows how commodity protectors layer many weak signals so analysts must either patch a central decision point or emulate a normal host convincingly.

For defensive review, read it as a checklist of branches to expect when reversing protected malware or game-cheat tooling. The main weakness is also instructive: checks that run in-process are visible to the analyst, can be patched, and often degrade legitimate debugging unless carefully scoped.

## References
- <https://github.com/chztbby/RebirthGuard>
