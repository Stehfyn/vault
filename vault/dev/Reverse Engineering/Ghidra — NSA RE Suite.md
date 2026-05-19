<!-- generated-from-dump2 -->
# Ghidra — NSA RE Suite

NSA's open-sourced software reverse-engineering suite. Java/Swing UI on top of a C++ decompiler (`decompile.exe`) and SLEIGH processor specs covering x86/x64/ARM/AARCH64/MIPS/PowerPC/RISC-V/Z80 and dozens more. Strongest free competitor to IDA Pro; weaker UI but free, scriptable in Python/Java, and the P-code IR is a real asset for static analysis tooling.

```python
# Headless analyzer script: dump every called function name.
# Save as ListCalls.py and run via analyzeHeadless.
from ghidra.program.model.listing import Function

fm = currentProgram.getFunctionManager()
for f in fm.getFunctions(True):
    for ref in f.getBody().getAddresses(True):
        instr = getInstructionAt(ref)
        if instr and instr.getFlowType().isCall():
            for tref in instr.getReferencesFrom():
                tgt = fm.getFunctionAt(tref.getToAddress())
                if tgt: print(f.getName(), "->", tgt.getName())
```

## References
- <https://github.com/NationalSecurityAgency/ghidra>
