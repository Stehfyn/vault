<!-- generated-from-dump2 -->
# HFSM2 Hierarchical State Machine

Header-only C++14 hierarchical finite-state machine framework. Distinguished from flat FSM libraries (sml, etod) by first-class support for *composite* states (XOR-children, exactly one active substate) and *orthogonal* states (AND-children, all active in parallel) — the standard UML statechart features needed for AI behaviour, UI workflows, and any non-trivial state graph. Zero-allocation: the state graph is described as a nested template type and the runtime carries only a small bitset of active states plus the user's per-state member data. Performance and footprint are competitive with hand-written code, which is the point — full statecharts at the cost of a flat switch.

```cpp
#include <hfsm2/machine.hpp>

struct Context { int counter = 0; };
using M = hfsm2::MachineT<hfsm2::Config::ContextT<Context>>;

#define S(s) struct s
using FSM = M::PeerRoot<
    S(Idle),
    M::Composite<S(Active),
        S(Running),
        S(Paused)
    >
>;
#undef S

struct Idle    : FSM::State { void update(FullControl& c) { c.changeTo<Active>(); } };
struct Active  : FSM::State {};
struct Running : FSM::State {};
struct Paused  : FSM::State {};

Context ctx;
FSM::Instance fsm{ctx};
fsm.update();          // Idle -> Active (Running active by default)
```

## References
- <https://github.com/andrew-gresyk/HFSM2>
