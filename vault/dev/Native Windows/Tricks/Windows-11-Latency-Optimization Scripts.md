# Windows-11-Latency-Optimization Scripts

This repo is a bundle of Windows 11 latency and responsiveness tweaks spanning services, power policy, telemetry settings, gaming settings, and vendor-related switches. Its usefulness is as a checklist of claims to test, not as a trusted performance prescription.

Connect it to `MMCSS Research`, `Power State APIs`, and `Windows-Dev-Performance`. Real latency work needs workload-specific measurement with ETW, frame-time/audio-glitch counters, and rollback discipline; broad tweak scripts often mix plausible scheduler/power changes with unrelated debloat folklore.

Useful measurement route:

```text
baseline ETW trace
  -> single setting change
  -> repeat workload
  -> compare scheduler, DPC/ISR, power, frame-time, and audio-glitch counters
  -> keep or roll back
```

The Windows mechanism links are MMCSS task class, power execution state, timer resolution, graphics presentation, and service policy. Treat registry/service edits as hypotheses until the measurement route proves they helped the workload under test.

## Discussion Claim To Verify

Claim commonly made by tweak-script repositories: a bundle of service, timer, game, telemetry, and power changes improves Windows latency.

Why it matters: latency is workload-specific. A script can reduce one benchmark's tail latency while damaging battery life, update behavior, capture reliability, audio stability, or another workload.

Verification route:

```powershell
powercfg /getactivescheme
powercfg /query > power-before.txt
powercfg /requests

wpr -start GeneralProfile -filemode
# run one fixed workload: game benchmark, audio glitch test, PresentMon capture, or input-latency harness
wpr -stop latency-before.etl
```

Apply exactly one candidate setting, then repeat:

```powershell
wpr -start GeneralProfile -filemode
# same workload, same duration, same foreground/background state
wpr -stop latency-after.etl
```

Interpretation:
- Lower DPC/ISR or present-frame outliers with unchanged error counters: candidate survives.
- Lower average latency but worse p95/p99, audio glitches, or power requests: the tweak is not a general improvement.
- No ETW/WPA/PresentMon/audio evidence in the source: the repository supports "these settings were changed," not "these settings improve your machine."

## References
- <https://github.com/NicholasBly/Windows-11-Latency-Optimization>
