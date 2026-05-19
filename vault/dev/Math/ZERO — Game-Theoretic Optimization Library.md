<!-- generated-from-dump2 -->
# ZERO — Game-Theoretic Optimization Library

Research-grade C++ library from the Data Science for Real-Time Decision-Making chair (Polytechnique Montréal) for solving mathematical programs with game-theoretic structure: Nash equilibria of quadratic games, bilevel / EPEC (Equilibrium Problem with Equilibrium Constraints), and integer-programming-game problems. Wraps Gurobi for the underlying MILPs/QPs; built on Armadillo for the linear algebra. The niche is unusual: most LP/MIP libraries solve a single optimization; ZERO solves *interacting* optimizations where each player's problem references the others' solutions, then iterates / decomposes until convergence. Useful reference for anyone modeling auctions, market-clearing, or multi-firm planning.

```cpp
// Conceptual: define a 2-player Nash game where each player solves a QP
// parameterized by the opponent's strategy; ZERO finds the Nash point.
// (Real API in include/games/nashgame.h.)
#include <zero.h>

GRBEnv env;
ZeroN::NashGame game(env, /*n_players=*/2);

// Each player has its own (Q_i, c_i) quadratic objective + linear constraints.
arma::sp_mat Q1, A1; arma::vec c1, b1;  // player 1's data
game.addPlayer(/*idx=*/0, Q1, c1, A1, b1);
// ...same for player 1...

ZeroN::NashAlgorithm alg = ZeroN::NashAlgorithm::FullEnumeration; // or PolyLCP
game.findNashEq(alg);
arma::vec x1 = game.getSolution(0);
arma::vec x2 = game.getSolution(1);
```

## References
- <https://github.com/ds4dm/ZERO>
