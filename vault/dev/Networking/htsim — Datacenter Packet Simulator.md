<!-- generated-from-dump2 -->
# htsim — Datacenter Packet Simulator

A discrete-event packet network simulator originally written by Mark Handley/Costin Raiciu (UCL) for evaluating data-center congestion control, now maintained under Broadcom's CSG umbrella to evolve protocols like DCTCP, NDP, EQDS, and Swift. Lives in a different niche from ns-3: monolithic C++, no Python bindings, optimized for huge fat-tree topologies (tens of thousands of hosts) at second-scale wall-clock simulations — researchers reach for it specifically when ns-3's per-event overhead bottoms out. Notable design choice: each protocol is a self-contained `EventSource` subclass, and topologies are generated procedurally rather than via XML.

```cpp
// Sketch of how a topology + flow are wired up (see sim/datacenter/*.cpp).
EventList eventlist;
eventlist.setEndtime(timeFromSec(10));
FatTreeTopology* topo = new FatTreeTopology(N_HOSTS, &eventlist);
// Spin up a TCP flow between two leaves.
TcpSrc*  src = new TcpSrc(nullptr, nullptr, eventlist);
TcpSink* snk = new TcpSink();
Route* fwd = topo->get_bidir_paths(srcHost, dstHost, false).at(0);
src->connect(*fwd, *fwd->reverse(), *snk, timeFromMs(0));
while (eventlist.doNextEvent()) {}
```

## References
- <https://github.com/Broadcom/csg-htsim>
