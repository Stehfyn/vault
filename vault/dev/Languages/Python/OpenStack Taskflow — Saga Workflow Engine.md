<!-- generated-from-dump2 -->
# OpenStack Taskflow — Saga Workflow Engine

OpenStack's Python library for "do this list of steps reliably, with rollback if any step fails" - a workflow / job engine designed for the kind of multi-step provisioning operations that show up across OpenStack services (Nova spawning a VM is a graph of N tasks, each with a paired revert function). Notable as a real-world implementation of the Saga pattern in Python well before "saga" was the trendy microservices term. Engines: serial, parallel, worker-distributed-via-message-bus.

```python
from taskflow.patterns import linear_flow as lf
from taskflow import engines, task

class Allocate(task.Task):
    def execute(self, name):           return alloc_vm(name)
    def revert (self, name, **_):      release_vm(name)

class Boot(task.Task):
    def execute(self, vm_id):          return boot(vm_id)
    def revert (self, vm_id, **_):     poweroff(vm_id)

flow = lf.Flow('provision').add(Allocate('alloc'), Boot('boot'))
engines.run(flow, store={'name': 'my-vm'})  # any step fails -> revert chain
```

## References
- <https://github.com/openstack/taskflow>
