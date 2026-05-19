<!-- generated-from-dump2 -->
# Infer — Meta Static Analyzer

Meta's static analyzer for Java/C/C++/Objective-C built on bi-abduction separation logic. Finds null-deref, leaks, dangling pointers, race conditions, and (with Pulse) interprocedural taint flows. Hooks into the build by wrapping the compiler: `infer run -- make` records the actual command line, replays it through Infer's frontends, and reports findings inline.

```bash
# Build C++ project under Infer; report into ./infer-out/.
infer run --pulse -- clang++ -std=c++20 -c src/foo.cpp src/bar.cpp
infer explore --html
```

## References
- <https://github.com/facebook/infer>
