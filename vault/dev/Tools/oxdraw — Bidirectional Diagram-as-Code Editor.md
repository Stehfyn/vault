<!-- generated-from-dump2 -->
# oxdraw — Bidirectional Diagram-as-Code Editor

"Diagram-as-code" tool in Rust where the diagram source is a plaintext / config format but the editor is a *real* draggable GUI — the trick is that dragging a node in the editor edits the underlying text representation in place rather than producing a separate binary layout file. Same niche as Mermaid / PlantUML / D2 / Excalidraw, with the differentiator being that all of those force a choice: either pure text (no manual repositioning) or pure GUI (no clean diff). oxdraw is positioned in between. Useful for the "I want this in git but the auto-layout is wrong" case.

```bash
cargo install oxdraw

# Open the GUI editor, drag nodes around, edits propagate to .oxd source
oxdraw open architecture.oxd

# Render to SVG / PNG headlessly for embedding in docs
oxdraw render architecture.oxd -o architecture.svg
```

```text
# .oxd source (rough shape — see repo for actual grammar)
node A "API"       at (100, 100)
node B "DB"        at (300, 100)
edge A -> B "writes"
```

## References
- <https://github.com/RohanAdwankar/oxdraw>
