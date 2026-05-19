<!-- generated-from-dump2 -->
# MWT Decision Service — Bandit Explorer (C++)

C++ exploration library from Microsoft's **Multi-World Testing / Decision Service** stack — the algorithmic core that picks which arm of a contextual-bandit policy to play for each user request. Implements **epsilon-greedy**, **softmax / tau-first**, and **bagging** with the careful propensity-score bookkeeping you need so the resulting log is *unbiased* — i.e., suitable for offline counterfactual policy evaluation later via Inverse Propensity Scoring (IPS) or Doubly Robust estimators. Paired with Vowpal Wabbit (the policy learner) on the back end. Pre-dates and influenced the design of Azure Personalizer. Useful read for "what exactly does an honest exploration log look like" — if you've ever written code that picks `argmax(scores)` and called it a bandit, this is what you were missing.

```cpp
// Conceptual epsilon-greedy explorer (real API in include/MWTExplorer.h):
// Wraps a base policy and emits both the chosen action AND its probability
// of being chosen, so downstream IPS analysis can correct for the policy.
#include <MWTExplorer.h>

class MyContext { /* features */ };
class MyPolicy : public IPolicy<MyContext> {
public:
    u32 Choose_Action(MyContext& ctx) override { return /* argmax */; }
};

MyPolicy basePolicy;
EpsilonGreedyExplorer<MyContext> explorer(basePolicy, /*epsilon=*/0.05f,
                                           /*num_actions=*/4);
MwtExplorer<MyContext> mwt("myapp", *new MyRecorder());

u32 action = mwt.Choose_Action(explorer, "context_uid", ctx);
// Logged record now contains (ctx, action, probability=eps/K or 1-eps+eps/K, ...).
```

## References
- <https://github.com/microsoft/mwt-ds-explore-cpp>
