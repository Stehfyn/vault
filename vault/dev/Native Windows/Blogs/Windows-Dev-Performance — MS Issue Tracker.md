# Windows-Dev-Performance - MS Issue Tracker

Microsoft's Windows-Dev-Performance repo is not a code reference; it is a triage record of developer-facing Windows performance pain. The useful material is in issues and resolutions around Defender scanning, filesystem filters, ConPTY latency, shell startup, terminal behavior, and repository-scale file trees.

Use it as a pointer when a Native Windows performance problem smells systemic rather than local. The best entries are closed issues with ETW traces or Microsoft comments because they identify which subsystem actually owned the delay.

Code contribution: look for issue evidence around ETW traces, Defender exclusions, filesystem filter drivers, ConPTY, shell startup, and repository-scale `CreateFile`/directory enumeration behavior.

## References
- <https://github.com/microsoft/Windows-Dev-Performance>
