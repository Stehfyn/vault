<!-- generated-from-dump2 -->
# ImGui Node Editor (Blueprint-Style Graphs)

The de-facto node-graph widget for Dear ImGui — used in Unreal-style blueprint editors, shader graphs, and procedural-content tools. Handles pan/zoom, bezier-curve links, pin types, selection rectangles, group nodes, and right-click context menus. The trick under the hood is that the editor draws on top of its own scrolling region and intercepts ImGui's input to translate it into graph coordinates.

```cpp
ed::Begin("node-editor");

ed::BeginNode(node_id);
    ImGui::Text("Add");
    ed::BeginPin(in_a, ed::PinKind::Input);  ImGui::Text("-> A"); ed::EndPin();
    ed::BeginPin(in_b, ed::PinKind::Input);  ImGui::Text("-> B"); ed::EndPin();
    ed::BeginPin(out,  ed::PinKind::Output); ImGui::Text("Sum ->"); ed::EndPin();
ed::EndNode();

for (auto& link : links)
    ed::Link(link.id, link.start_pin, link.end_pin);

ed::End();
```

## References
- <https://github.com/thedmd/imgui-node-editor>
