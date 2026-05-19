# PowerShell VSS Module - Scriptable Shadow Copies

This module wraps Volume Shadow Copy Service operations in PowerShell so administrators can create, expose, inspect, and remove snapshots without fighting `vssadmin` or writing COM requester code. It is useful as an operations reference for consistent point-in-time reads of otherwise live files.

The distinction from AlphaVSS is audience: this is scriptable maintenance and backup glue, while AlphaVSS is an application library. Both belong with file-copy and backup notes because VSS changes the problem from "copy bytes now" to "coordinate writers, freeze state, then copy a stable view."

## References
- <https://github.com/albertony/vss>
