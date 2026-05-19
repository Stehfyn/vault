<!-- generated-from-dump2 -->
# CXXGraph Graph Algorithms Library

Header-only C++ template library for graphs: adjacency-list backend, weighted/unweighted/directed/undirected variants, and the standard algorithm suite (Dijkstra, Bellman-Ford, A*, Floyd-Warshall, Kruskal, Prim, strongly-connected-components via Tarjan/Kosaraju, max-flow). Notable for being one of the most maintained header-only graph libs (alternatives like Boost.Graph are aging and notoriously slow to compile). Includes serialization to GraphML/DOT and partition-friendly storage.

```cpp
#include "Graph/Graph.hpp"

CXXGraph::Node<int> a("a", 1), b("b", 2), c("c", 3);
CXXGraph::DirectedWeightedEdge<int> e1(1, a, b, 5.0);
CXXGraph::DirectedWeightedEdge<int> e2(2, b, c, 2.0);

CXXGraph::Graph<int> g{{ &e1, &e2 }};
auto path = g.dijkstra(a, c);   // shortest path
// path.result == 7.0
```

## References
- <https://github.com/ZigRazor/CXXGraph>
