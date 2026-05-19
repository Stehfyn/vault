<!-- generated-from-dump2 -->
# BetterRDP — Windows RDP Tweak Pack

Registry + Group-Policy tweak pack that flips the gates on the Windows Remote Desktop server to allow 60 fps frame rates, GPU acceleration (RemoteFX/RDP10 AVC444), higher bitrates, and chroma 4:4:4. Mostly tweaks under `HKLM\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services` plus the H.264/AVC capture provider.

```powershell
# Core BetterRDP knobs (excerpt).
$rdp = "HKLM:\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services"
New-Item $rdp -Force | Out-Null
Set-ItemProperty $rdp -Name "fEnableVirtualizedGraphics" -Type DWord -Value 1
Set-ItemProperty $rdp -Name "MaxMonitorFPS"             -Type DWord -Value 60
Set-ItemProperty $rdp -Name "AVC444ModePreferred"       -Type DWord -Value 1
Set-ItemProperty $rdp -Name "VideoEncoderType"          -Type DWord -Value 1   # H.264
```

## References
- <https://github.com/Upinel/BetterRDP>
