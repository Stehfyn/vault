<!-- generated-from-dump2 -->
# Quint — Modern TLA+ for Programmers

Leslie Lamport's TLA+ with a syntax that won't make you bounce off it. Same underlying model — the **Temporal Logic of Actions**: you describe a system as a state space + atomic transitions + invariants + temporal properties — but instead of TLA+'s mathematician-flavored notation it uses a Scala/Rust-shaped syntax that programmers can actually read. Informal Systems built it because Cosmos/IBC engineers needed to specify distributed protocols and couldn't get a team to learn TLA+. Compiles to TLA+ under the hood, so all of TLA's tooling (TLC model checker, Apalache symbolic checker) works. Worth learning if you've ever wanted formal-methods reach without the notation overhead.

```quint
// A coin-flip game (from the Quint tutorial)
module coinFlip {
  var state: str

  action init = state' = "ready"

  action flip = any {
    all { state == "ready", state' = "heads" },
    all { state == "ready", state' = "tails" },
  }

  // Invariant: never escape the three known states.
  val inv = state.in(Set("ready", "heads", "tails"))
}
```

```bash
# Tooling:
$ quint typecheck coin.qnt
$ quint run --invariant inv coin.qnt          # randomized simulator
$ quint verify --invariant inv coin.qnt       # Apalache symbolic model check
```

## References
- <https://github.com/informalsystems/quint>
