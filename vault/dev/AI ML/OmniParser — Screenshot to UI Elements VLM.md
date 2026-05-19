<!-- generated-from-dump2 -->
# OmniParser — Screenshot to UI Elements VLM

Vision model that turns a screenshot into a structured **set of clickable elements** with bounding boxes and semantic labels — the missing perception step that lets a multimodal LLM agent operate a GUI it can only see (no DOM, no accessibility tree). The pipeline: (1) a YOLO-derived detector trained on UI screenshots produces bounding boxes for clickable icons/buttons/inputs; (2) for each box, BLIP-2 / Florence-2 generates a short caption ("blue submit button," "search field," "username text input"); (3) OCR is fused in for textual labels. The output is a JSON list of `{bbox, type, label}` that any planner-style agent (GPT-4o, Claude, etc.) can ground click actions to. The v2 release uses a single end-to-end Florence-2 fine-tune. Used as the perception layer in MS's "Magentic-One" and many academic computer-use agents.

```python
from omniparser import OmniParser

p = OmniParser.load("microsoft/OmniParser-v2")
result = p.parse("screenshot.png")
# result is a list of dicts:
# [
#   {"bbox": [x1,y1,x2,y2], "type": "icon",  "label": "Search"},
#   {"bbox": [...],         "type": "text",  "label": "Untitled - Notepad"},
#   {"bbox": [...],         "type": "input", "label": "search field"},
#   ...
# ]
# Feed this list to your LLM agent alongside the original image so it can
# reason "to search, click the box labeled 'search field'" and you click x,y.
```

## References
- <https://github.com/microsoft/OmniParser>
