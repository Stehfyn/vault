<!-- generated-from-dump2 -->
# Pictonode — Node-Based Image Editor

Node-based image editor, in the spirit of Blender's compositor or Natron - build an image-processing pipeline by wiring nodes (load, blur, color-grade, blend, save) on a canvas. The interesting design questions in any node-based editor are (a) how do you propagate region-of-interest backwards from sink to source to avoid recomputing pixels that won't be displayed, and (b) how do you cache intermediate buffers; see the source for this team's answer.

```text
# Repo is the canonical implementation. Typical node-graph eval:
#   for each output node:
#       walk upstream marking required ROI on each input port
#       schedule producer nodes in topological order
#       cache results keyed by (node, output-port, parameter-hash, roi)
```

## References
- <https://github.com/TeamPictonode/pictonode>
