<!-- generated-from-dump2 -->
# Nodezator Visual Scripting Editor

Desktop node-based visual scripting editor for Python, built on pygame for the canvas. Each node is literally a Python function — Nodezator introspects its signature (parameters, defaults, annotations) and renders sockets and inline widgets accordingly, then on "play" topologically sorts the graph and calls the functions in order. So unlike Ryven (live runtime) or ComfyUI (domain-specific), it produces a `.ndz` graph that is essentially "structured calls to a library of functions you wrote in plain `.py` files." Useful for non-programmer domain users who need a frozen pipeline UI on top of someone else's Python code.

```python
# A Nodezator-compatible node is just a function in a file the editor scans.
# nodes/string_ops/concat.py

main_callable = "concat"   # name the editor picks up

def concat(
    a: str = "",
    b: str = "",
    sep: str = " ",
) -> [
    {"name": "out", "type": str},
]:
    return {"out": f"{a}{sep}{b}"}
```

## References
- <https://github.com/IndieSmiths/nodezator>
