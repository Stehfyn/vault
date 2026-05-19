<!-- generated-from-dump2 -->
# Gtk.NodeGraph C# Node-Editor Widget

C# / GtkSharp port of `aluntzer/gtknodes` — a node-editor canvas widget for Gtk apps written in .NET. Nodes have typed input/output sockets that you wire together; connections fire data-change events that propagate values along the graph (the README's sample app is a calculator built by wiring number nodes through arithmetic-op nodes). Type-compatibility validation prevents wiring an int socket to a string socket. Graphs serialize to XML so you can persist a layout. Useful when you specifically need a GTK look-and-feel inside a .NET app (cross-platform via GtkSharp on Linux/Win/Mac) and don't want to host an embedded HTML canvas.

```csharp
using Gtk;
using AliensGroup.Gtk.NodeGraph;

var view  = new NodeView();
var src   = new Node { Label = "Constant" };
var dst   = new Node { Label = "Multiply" };

src.AddItem(new Label("out: 42"), NodeSocketType.Source, typeof(int));
dst.AddItem(new Label("a"),       NodeSocketType.Sink,   typeof(int));
dst.AddItem(new Label("b"),       NodeSocketType.Sink,   typeof(int));

view.Add(src);
view.Add(dst);
// Connections drawn interactively, or via view.Connect(src, 0, dst, 0);
```

## References
- <https://github.com/AliensGroup/Gtk.NodeGraph>
