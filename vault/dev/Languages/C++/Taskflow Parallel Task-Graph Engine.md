<!-- generated-from-dump2 -->
# Taskflow Parallel Task-Graph Engine

Header-only C++ parallel task-graph engine: define a DAG of tasks with explicit dependencies, hand it to `tf::Executor`, and it runs them concurrently respecting the precedence. Distinguishing features: heterogeneous execution (CPU tasks + cudaFlow blocks for nested GPU work), composition (subflows can spawn nested taskflows dynamically at run time), and a debugger that visualizes the schedule. Used in academic HPC and EDA codebases.

```cpp
#include <taskflow/taskflow.hpp>

tf::Executor exec;
tf::Taskflow tf;

auto [A, B, C, D] = tf.emplace(
    []{ std::cout << "A\n"; },
    []{ std::cout << "B\n"; },
    []{ std::cout << "C\n"; },
    []{ std::cout << "D\n"; }
);
A.precede(B, C);  // A -> B, A -> C
B.precede(D);     // B -> D
C.precede(D);     // C -> D

exec.run(tf).wait();    // B and C run in parallel
```

## References
- <https://github.com/taskflow/taskflow>
