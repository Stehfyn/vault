<!-- generated-from-dump2 -->
# Tidbyt Community Apps

User-contributed apps for the Tidbyt - a 64x32 pixel matrix display sold as a desk gadget. Apps are written in Starlark (Google's restricted Python dialect) using the Pixlet runtime, then submitted via this repo. The interesting design constraint: 64x32 pixels means apps must be designed for *glance*-level information density (one weather number, one stock ticker, one ETA). Browsing the repo is a study in minimal data display.

```python
# Conceptual app (Starlark):
load("render.star", "render")
load("http.star", "http")

def main():
    resp = http.get("https://wttr.in/Brooklyn?format=j1").json()
    temp = resp["current_condition"][0]["temp_F"]
    return render.Root(
        child = render.Row(
            children = [
                render.Text("BK"),
                render.Text(temp + "F", color = "#ff8800"),
            ],
        ),
    )
```

## References
- <https://github.com/tidbyt/community>
