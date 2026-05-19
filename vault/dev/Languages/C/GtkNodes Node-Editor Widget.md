<!-- generated-from-dump2 -->
# GtkNodes Node-Editor Widget

GTK 3 widget library written in C that adds a node-editor canvas — boxes with typed input/output sockets you can wire together — on top of GtkFixed. Used as the visual layer in some scientific / EO ground-station GUIs (Armin Luntzer works at IWF). The non-obvious design choice: connections are GObjects that listen to "value-changed" signals on the source socket and forward via GValue to the sink socket, so data propagation is just standard GObject signal plumbing rather than a custom event bus. C# port lives at `AliensGroup/Gtk.NodeGraph`; Python wrapping is via GObject Introspection.

```c
#include <gtknodes.h>

GtkWidget *view = gtk_nodes_node_view_new();
GtkWidget *src  = gtk_nodes_node_new();
GtkWidget *dst  = gtk_nodes_node_new();

GtkWidget *out  = gtk_label_new("out");
GtkWidget *in   = gtk_label_new("in");

gtk_nodes_node_add_item(GTK_NODES_NODE(src), out,
                       GTK_NODES_NODE_SOCKET_SOURCE);
gtk_nodes_node_add_item(GTK_NODES_NODE(dst), in,
                       GTK_NODES_NODE_SOCKET_SINK);

gtk_container_add(GTK_CONTAINER(view), src);
gtk_container_add(GTK_CONTAINER(view), dst);
```

## References
- <https://github.com/aluntzer/gtknodes>
