# Process Hollowing (RunPE)

Process hollowing is best understood as a mismatch between process identity and executable image contents. A process is created in a benign-looking state, its original image mapping is replaced or overwritten, and execution resumes at an entry point belonging to different PE content. The technique is old, heavily studied, and useful here mainly because it exposes the relationship between the PEB image base, section mappings, thread context, and loader assumptions.

Defensively, the canonical artifacts matter more than the mechanics: suspended-process creation, image unmapping or replacement, private executable memory, thread-context changes, PEB/image inconsistencies, and ETW/process/image-load sequences that do not match the final code. Treat RunPE as a PE-loader and process-state case study.

## Connections
- `ManualMap` and `MemJect` cover related in-memory PE initialization problems.
- ETW process/image providers, wtrace, and ProcMonXv2 are observation paths for the surrounding process events.

## References
- <https://github.com/aaaddress1/RunPE-In-Memory>
