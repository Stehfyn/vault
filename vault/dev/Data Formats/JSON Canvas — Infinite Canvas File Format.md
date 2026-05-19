<!-- generated-from-dump2 -->
# JSON Canvas — Infinite Canvas File Format

Open file format spec by the Obsidian team for "infinite canvas" data - boards/whiteboards with nodes, edges, and embedded markdown / image / link / group content. The interesting design choice: it's intentionally tiny (one JSON document, ~10 node types, ~3 edge types) and embeddable, so apps like Obsidian Canvas, Excalidraw, and others can use it as a shared interchange format rather than each inventing their own JSON shape.

```json
{
  "nodes": [
    { "id": "a", "type": "text",  "x": 0,   "y": 0,
      "width": 200, "height": 80, "text": "hello" },
    { "id": "b", "type": "file",  "x": 300, "y": 0,
      "width": 200, "height": 80, "file": "Notes.md" }
  ],
  "edges": [
    { "id": "e1", "fromNode": "a", "toNode": "b", "fromSide": "right" }
  ]
}
```

## References
- <https://github.com/obsidianmd/jsoncanvas>
