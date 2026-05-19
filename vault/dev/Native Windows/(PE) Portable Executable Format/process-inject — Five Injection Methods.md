# process-inject - Five Injection Methods

This repository catalogs several Windows process-injection families: remote-thread DLL loading, suspended-process replacement, reflective loading, APC-based execution, and SetWindowsHookEx-assisted loading. Its value is comparative taxonomy. Each method stresses a different subsystem: loader state, thread scheduling, message queues, handle rights, memory protections, or hooks.

For this vault, keep the note defensive and structural. The important question is which artifacts distinguish the families: cross-process handles, remote allocations, image-load events, APC delivery context, message-hook DLL mapping, or a hollowed process whose identity no longer matches its code.

## Connections
- PE notes cover loader and image artifacts.
- Hooks notes cover SetWindowsHookEx as an injection surface tied to GUI thread queues.

Code contribution: classify artifacts around `OpenProcess`, `VirtualAllocEx`, `WriteProcessMemory`, `QueueUserAPC`, `SetWindowsHookEx`, image-load events, and mismatched process image sections.

## References
- <https://github.com/suvllian/process-inject>
