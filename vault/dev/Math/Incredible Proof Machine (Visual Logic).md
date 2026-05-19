<!-- generated-from-dump2 -->
# Incredible Proof Machine (Visual Logic)

Joachim Breitner's "Incredible Proof Machine" - an interactive in-browser visualization for building formal proofs by connecting logical inference rules as nodes. Targeted at teaching first-order logic without the LaTeX-style ascii syntax usually required. Useful as a starting reference if you ever want to embed a proof-checker UI in a teaching website; the implementation is plain JavaScript on a SAT-style propositional / first-order verifier.

```text
# Try at: https://incredible.pm/
# Repo holds: rule definitions (JSON), session files (saved proof graphs),
# a small JS UI for dragging rule blocks and wiring premise -> conclusion edges,
# and a verifier that walks the graph and checks every connection's typing.
```

## References
- <https://github.com/nomeata/incredible>
