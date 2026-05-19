# winutil - PowerShell Win10/11 Debloater

Chris Titus Tech's `winutil` is best treated as a catalog of Windows configuration switches: AppX removals, scheduled-task disables, privacy settings, service tweaks, and common "debloat" opinions wrapped in a PowerShell/WPF UI. It is not Native Windows code, but the registry paths and task names are useful inventory.

For serious use, separate reversible policy from destructive removal and benchmark claims before adopting them. This connects to `windows-defender-remover`, `Windows-11-Latency-Optimization Scripts`, and app-compat notes because system-wide tweaks can break updates, Store apps, and diagnostics long after the original script ran.

## References
- <https://github.com/ChrisTitusTech/winutil>
