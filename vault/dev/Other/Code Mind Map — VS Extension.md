<!-- generated-from-dump2 -->
# Code Mind Map — VS Extension

Visual Studio (and VS Code) extension that lets you draw a mind-map where each node is anchored to a specific location in your source code — clicking a node opens that file at that line. The point is to keep "what does this codebase look like at a 1000-foot view" notes separate from in-file comments while still letting them stay in sync as code moves: each node stores a stable symbol-based anchor (function name + signature hash) rather than a fragile file:line pair.

```text
# Usage (paraphrased from the extension's README):
#   1. Install from the Marketplace.
#   2. View > Code Mind Map -> opens a canvas pane.
#   3. Right-click a line in your editor -> "Add to Mind Map" -> node appears.
#   4. Drag nodes around, draw arrows ("calls", "extends", "TODO related to").
#   5. Click a node to jump to the anchored location, even after refactors.
```

## References
- <https://github.com/OlegIGalkin/Code-Mind-Map>
