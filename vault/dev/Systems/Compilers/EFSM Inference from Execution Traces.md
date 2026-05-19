<!-- generated-from-dump2 -->
# EFSM Inference from Execution Traces

Isabelle/HOL formalization and OCaml/SML toolchain for inferring Extended Finite State Machines (EFSMs) from execution traces. Given a log of (input, output, variable) tuples, it generalizes a minimal state machine consistent with observations, with optional guards over program variables. Aimed at program-comprehension / model-mining research, not at runtime profilers.

```bash
# Build (requires Isabelle, OPAM, Z3).
opam install . --deps-only
dune build

# Run on a trace file.
./_build/default/inference/Main.exe --input traces/coffee_machine.log --output ./out
```

## References
- <https://github.com/jmafoster1/efsm-inference>
