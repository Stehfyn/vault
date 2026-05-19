<!-- generated-from-dump2 -->
# Python Mesh Network Simulator

Python toolkit for prototyping mesh-network topologies on top of UDP/serial/IRC/whatever transport you want. Provides `Node`, `Link`, and `Switch` primitives plus pluggable transports so you can simulate a thousand nodes on one host and have them route via custom algorithms (link-state, distance-vector, BATMAN-style).

```python
from mesh.node import Node
from mesh.links import UDPLink

a = Node([UDPLink("eth0", port=2000)])
b = Node([UDPLink("eth0", port=2001)])
a.start(); b.start()

# Broadcast a message; the link routes it to neighbors.
a.send(b"hello mesh")
```

## References
- <https://github.com/pirate/mesh-networking>
