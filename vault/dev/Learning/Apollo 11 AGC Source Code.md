<!-- generated-from-dump2 -->
# Apollo 11 AGC Source Code

OCR'd transcription of the original AGC (Apollo Guidance Computer) assembly listings for Comanche055 (Command Module) and Luminary099 (Lunar Module). Source of the now-famous "BURN BABY BURN — MASTER IGNITION ROUTINE" and "THE_LUNAR_LANDING.agc" file names. The AGC ran a 2 MHz 15-bit-word machine with ~2K of erasable memory and ~36K of read-only "core rope"; the code is hand-written assembly using a cooperative real-time executive with priority-based job and waitlist scheduling, and the famous "1202" alarm during the landing was the executive correctly shedding low-priority work under overload. Worth reading purely as cultural artifact, but the executive/job-list design also predates and prefigures modern RTOS task models.

```text
# Sample from the actual sources (THE_LUNAR_LANDING.agc):
#
#     TC      BANKCALL
#     CADR    STOPRATE        # NULL OUT ATTITUDE ERROR ROD'S
#     TC      DOWNFLAG        # PERMIT X-AXIS OVERRIDE
#     ADRES   XOVINFLG
#     ...
#
# Executive primitives that show up throughout:
#     NOVAC / WAITLIST  - schedule a future job at a tick
#     PRIO / FINDVAC    - cooperative priority dispatch
#     ENDOFJOB          - yield back to executive
```

## References
- <https://github.com/chrislgarry/Apollo-11>
