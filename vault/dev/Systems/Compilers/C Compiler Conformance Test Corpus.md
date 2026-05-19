<!-- generated-from-dump2 -->
# C Compiler Conformance Test Corpus

Community-curated C compiler conformance corpus: ~200 single-file tests covering K&R, C89/C99/C11 edge cases, plus runners for tcc, cproc, chibicc, lacc, pcc, cuik, etc. Each test is `NNNNN.c` + expected exit code / stdout; useful when writing your own C frontend to see how the toy compilers handle each feature.

```bash
git clone https://github.com/c-testsuite/c-testsuite
cd c-testsuite
./run.sh runners/gcc/run.sh
# Outputs PASS/FAIL counts plus per-test diff against tests/*.c.expected.
```

## References
- <https://github.com/c-testsuite/c-testsuite>
