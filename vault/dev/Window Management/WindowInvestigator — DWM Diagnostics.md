<!-- generated-from-dump2 -->
# WindowInvestigator — DWM Diagnostics

Etienne Dechamps' diagnostic toolset for investigating Windows window-manager weirdness — chiefly the long-standing issues around DWM, exclusive fullscreen, borderless windowed, frame pacing, and how Windows decides when to suspend or composite a window. Sits in the same conceptual neighbourhood as Special K and his other low-level Windows tools (FlexASIO, dechamps_CMP). The value isn't a polished UI; it's that he writes down the actual mechanics of what he's testing (Present mode, DWM occlusion state, GetForegroundWindow vs. GetShellWindow, etc.) in a way that's reusable when you hit the same class of bug.

```text
Companion reading: his blog posts on frame pacing and DWM behaviour, plus
the Microsoft DXGI flip-model docs. Run alongside PresentMon if you want to
correlate the toolbox's observations with actual present timing.
```

## References
- <https://github.com/dechamps/WindowInvestigator>
