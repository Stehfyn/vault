# Self Update

This sample demonstrates a classic Windows self-update constraint: a running executable image cannot simply overwrite itself in place. The workaround is a two-process handoff where the current process stages a replacement, launches a helper or new copy, waits for the original image handle/process lifetime to end, then renames or replaces the file.

The interesting API surface is process inheritance, command-line handoff, wait handles, and `NtSetInformationFile`/rename semantics. Keep this near `ShellExecute and File Operations`, installer notes, and service-update patterns; the sample is about Windows object lifetime and file replacement, not about networking or update trust.

## References
- Local snippet source retained in previous revision of this note.
