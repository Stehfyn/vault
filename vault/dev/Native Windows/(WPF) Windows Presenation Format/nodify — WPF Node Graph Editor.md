# nodify - WPF Node Graph Editor

Nodify is a WPF control library for node-graph editors: nodes, connectors, pending connections, selection, pan/zoom, and graph-surface virtualization. Its real value is not that it draws boxes and lines; it shows how far WPF's retained-mode model can be pushed when an editor needs thousands of interactive elements without abandoning MVVM.

Read it beside Direct2D/Win2D and custom-control notes. Immediate-mode drawing libraries solve graph editors by owning the entire scene; Nodify demonstrates the WPF version: bind graph state to controls, virtualize aggressively, keep input gestures coherent, and avoid turning the visual tree into the bottleneck.

Code contribution: inspect node/connector controls for `ItemsControl`, `DataTemplate`, routed commands, pan/zoom transforms, virtualization, and MVVM-bound connection state.

## References
- <https://github.com/miroiu/nodify> - WPF node-editor controls and samples with MVVM-oriented graph editing patterns.
