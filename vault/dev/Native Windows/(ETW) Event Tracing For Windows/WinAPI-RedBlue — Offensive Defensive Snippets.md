# WinAPI-RedBlue - Offensive Defensive Snippets

WinAPI-RedBlue is useful when read defensively: it pairs common Win32 primitives with the telemetry and controls that reveal or constrain them. The value is not novelty in the techniques; it is the side-by-side framing that turns API calls, handle rights, memory permissions, token operations, and process/thread creation into observable behaviors.

Keep the entry at the detection layer. For this vault, the interesting question is which subsystem records the behavior: Kernel-Process ETW for process/thread/image transitions, handle and memory APIs for access patterns, AMSI or script providers for content, and native APIs when the Win32 wrapper is bypassed. That connects it directly to Sealighter, wtrace, ProcMonXv2, and the PE injection notes without turning the note into a recipe.

## Connections
- ETW entries explain where defensive telemetry comes from.
- PE and Hooks entries explain why many techniques eventually reduce to loader behavior, thread creation, message hooks, or memory mapping.

Code contribution: map each linked primitive to telemetry families such as `Microsoft-Windows-Kernel-Process`, `OpenProcess`, `VirtualAllocEx`, `WriteProcessMemory`, `CreateRemoteThread`, and token APIs.

## References
- <https://github.com/tbhaxor/WinAPI-RedBlue>
