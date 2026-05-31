# nodify - WPF Node Graph Editor

Nodify is a WPF control library for node-graph editors: nodes, connectors, pending connections, selection, pan/zoom, and graph-surface virtualization. Its real value is not that it draws boxes and lines; it shows how far WPF's retained-mode model can be pushed when an editor needs thousands of interactive elements without abandoning MVVM.

Read it beside Direct2D/Win2D and custom-control notes. Immediate-mode drawing libraries solve graph editors by owning the entire scene; Nodify demonstrates the WPF version: bind graph state to controls, virtualize aggressively, keep input gestures coherent, and avoid turning the visual tree into the bottleneck.

Code contribution: inspect node/connector controls for `ItemsControl`, `DataTemplate`, routed commands, pan/zoom transforms, virtualization, and MVVM-bound connection state.

## References
- <https://github.com/miroiu/nodify> - WPF node-editor controls and samples with MVVM-oriented graph editing patterns.

## Experiment Harness

Goal: find the visual-tree scale where WPF graph editing stops being interactive.

```csharp
var sw = Stopwatch.StartNew();
model.Nodes = Enumerable.Range(0, n).Select(i => new NodeVm()).ToList();
Dispatcher.InvokeAsync(() =>
    Debug.WriteLine($"nodes={n} visuals={CountVisuals(editor)} ms={sw.ElapsedMilliseconds}"));
```

Procedure: generate 100, 1,000, and 10,000 nodes; toggle virtualization/pan-zoom features; record frame time while dragging.

Measured signal: visual count, layout/render time, input latency, memory.

Failure interpretation: WPF retained-mode cost is usually visual tree size and layout invalidation, not line drawing itself. Reference: <https://learn.microsoft.com/en-us/dotnet/desktop/wpf/advanced/optimizing-performance-controls>.
