<!-- generated-from-dump2 -->
# Chaos Preprocessor Library

The Chaos preprocessor library — Paul Mensonides's macro library that Boost.Preprocessor was derived from. Provides primitive recursion, ordered lists, integer arithmetic and tuple manipulation using nothing but the C preprocessor's macro substitution engine. The cleverness is in side-stepping the "preprocessor doesn't have recursion" rule by using deferred expansion through `CHAOS_PP_EXPAND` and a "scan" mechanism that retriggers macros on later passes. Useful reading if you want to understand BOOST_PP_REPEAT et al at their roots.

```text
# Idiomatic Chaos example (the canonical "repeat macro N times")
#include <chaos/preprocessor/repetition/repeat.h>

#define M(s, n, _) int x##n;

CHAOS_PP_REPEAT(5, M, ~)
// Expands to:  int x0; int x1; int x2; int x3; int x4;
```

## References
- <https://github.com/rofl0r/chaos-pp>
