<!-- generated-from-dump2 -->
# Ryven Flow-Based Visual Scripting

Flow-based visual scripting environment for Python — Qt (PySide) frontend on top of the author's own `ryvencore` execution kernel. Each node has a Python class with `update_event` (recompute outputs from inputs) and an optional Qt widget for inline UI. Unlike Nodezator (graph is a serialised call to plain functions), Ryven nodes hold state across executions and there are two execution modes: "data flow" (pull) and "exec flow" (push), so it can model both pure pipelines and event-driven graphs. The frontend is decoupled — `ryvencore` is reusable as a library if you want headless graph execution.

```python
# Define a custom Ryven node
from ryven.node_env import Node, NodeInputType, NodeOutputType, node_types

class AddNode(Node):
    title = "Add"
    init_inputs = [NodeInputType("a"), NodeInputType("b")]
    init_outputs = [NodeOutputType("sum")]

    def update_event(self, inp=-1):
        a = self.input(0) or 0
        b = self.input(1) or 0
        self.set_output_val(0, a + b)

node_types([AddNode])
```

## References
- <https://github.com/leon-thomm/Ryven>
