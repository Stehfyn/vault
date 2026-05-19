# Remove Windows AI Copilot Recall

PowerShell + take-ownership scripts that strip Copilot, Recall, "Click to Do", AI Component packages, and the on-device Phi/SLM models from Windows 11 24H2+. The interesting (and brittle) bit is that these features ship as `Microsoft.Windows.Ai.Copilot.Provider` + companion packages that are pinned via `Provisioned` / `AppxAllUserStore` registry keys and re-installed by Setup on cumulative updates — so the script also nukes the provisioned package list and adds policy registry values (`HKLM\Software\Policies\Microsoft\Windows\WindowsAI\DisableAIDataAnalysis`, etc.) to keep them from coming back.

## References
- <https://github.com/zoicware/RemoveWindowsAI>
