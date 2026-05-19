<!-- generated-from-dump2 -->
# Microsoft BASIC for 6502 (1976 Source)

The actual 1976/1978 source of Microsoft BASIC for 6502 — the BASIC that shipped (with minor branding changes) on the Apple II (Applesoft), Commodore PET / VIC-20 / C64, Atari 400/800, KIM-1, OSI machines, and dozens of others. Written by Bill Gates, Paul Allen, and Ric Weiland. Released by Microsoft in 2024 under MIT. Worth reading as a historical artifact and as a study in **how to fit a BASIC interpreter — lexer, tokenizer, garbage-collected string heap, floating point, pseudo-trigonometric primitives — into 8 KB of ROM**. The token table, the floating-point routines (MBF — Microsoft Binary Format, predecessor of IEEE 754 in practice), and the famous "WAIT 6502, 1" CBM trick (Bill Gates' easter egg, find his name in the C64 source) are all here.

```text
# Build: MACRO-10 assembler source (originally written on DECsystem-10).
# Conditional assembly switches at the top select the target machine:
#
#   REALIO  EQ      4       ; 0=KIM,1=COMMODORE,2=OSI,3=APPLE,4=STM,5=PDP10
#
# The same source assembles into Applesoft, Commodore BASIC v2, KIM BASIC,
# etc., by toggling these switches. The shared core is the lexer, the
# tokenized-line execution loop, and the MBF floating-point package.
#
# Famous easter egg in the COMMODORE build:
#   WAIT 6502, 1
# scans memory for the string "MICROSOFT!" written by Gates as a copyright marker.
```

## References
- <https://github.com/microsoft/BASIC-M6502>
