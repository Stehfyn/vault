<!-- generated-from-dump2 -->
# Blueberry — Cellular Automata Rule Explorer

Interactive explorer for the Conway-style cellular automaton family, but generalized: it edits "MAP rules" (the 512-bit encoding the Golly/LifeWiki community uses to specify any 2-state, 9-neighbor outer-totalistic-or-not rule), including isotropic subsets where rotations and reflections share the same transition. The interesting design choice is making the rule itself the manipulated object — the UI lets you click through symmetry-equivalent rules, mutate single transitions, and watch the universe evolve under the new rule live, instead of just picking from a preset menu. Useful for hunting rules with interesting emergent dynamics outside the Life/HighLife corner.

```text
# MAP rule encoding (background, not API):
#   - 9 neighborhood cells (center + 8 Moore neighbors).
#   - 2^9 = 512 possible "before" configurations.
#   - The rule is a 512-bit string: bit k = next state for configuration k.
#   - Outer-totalistic Life ("B3/S23") is the subset of MAP rules where
#     only the count of live neighbors + center state matters.
#
# blueberry-archive lets you flip those 512 bits with isotropy preserved.
```

## References
- <https://github.com/achabense/blueberry-archive>
