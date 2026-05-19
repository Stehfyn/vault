# MoVfuscator (Mov-Only Compiler)

Christopher Domas's MoVfuscator is the classic demonstration that x86 `mov` can be abused into a Turing-complete execution model. The practical output is hostile to ordinary static analysis because expected branch and arithmetic structure largely disappears, even when the program still computes normally.

Its value here is conceptual, not operational. It teaches why "recognizable instruction patterns" are a weak proxy for semantics and why reverse engineering often has to recover dataflow, not just control flow. Pair it with the Battelle fork and metamorphic compiler entry.

## References
- <https://github.com/xoreaxeaxeax/movfuscator>
