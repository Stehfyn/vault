<!-- generated-from-dump2 -->
# Bart Wisselink's Self-Hosted Languages

Bart Wisselink's personal language hoard - a long-running collection of his experiments in writing tiny systems languages and bytecode VMs from scratch in his own toolchains. Notable because Bart famously refuses to use the C/LLVM ecosystem and writes both the compiler and the bytecode interpreter in his own language ("M" and successors). Worth a look as an unusually pure example of "language design without infrastructure overhead" - the whole stack is one person's code and fits in a few hundred KB.

```text
# Repo highlights (per Bart's bcforum posts / readmes):
m/             # the "M" systems language, his C replacement
bb/            # "BB" (Big Block), an experimental higher-level lang
qq/            # tiny dynamic language with hash-based dispatch
runner/        # bytecode interpreter (also self-hosted)
# Each language compiles to a flat binary, no linker, no static libs.
```

## References
- <https://github.com/sal55/langs>
