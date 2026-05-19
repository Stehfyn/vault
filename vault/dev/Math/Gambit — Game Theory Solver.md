<!-- generated-from-dump2 -->
# Gambit — Game Theory Solver

Decades-old academic toolset for computing Nash equilibria, refinements, and rationalizable sets — both normal-form and (the harder problem) extensive-form games with imperfect information. C++ core, Python bindings, plus a Qt GUI for drawing game trees. Implements the canonical algorithms specialists actually want to cite: Lemke-Howson for two-player Nash, simplicial-subdivision for n-player, sequential and trembling-hand for refinements, and importantly **agent-form** representation for extensive games (so subgame-perfect/sequential equilibria are tractable). Read alongside Shoham/Leyton-Brown's MAS textbook; the algorithms in chapter 4 are this code.

```python
import pygambit as gbt

# 2x2 Prisoner's Dilemma in normal form
g = gbt.Game.new_table([2, 2])
g.players[0].label = "Alice"
g.players[1].label = "Bob"

# Payoffs (Alice, Bob) for each strategy combo
g[0,0][0] = -1; g[0,0][1] = -1   # both cooperate
g[0,1][0] = -3; g[0,1][1] =  0   # Alice C, Bob D
g[1,0][0] =  0; g[1,0][1] = -3   # Alice D, Bob C
g[1,1][0] = -2; g[1,1][1] = -2   # both defect

# Solve all Nash equilibria via Lemke-Howson
result = gbt.nash.lcp_solve(g)
for eq in result.equilibria:
    print(eq)
```

## References
- <https://github.com/gambitproject/gambit>
