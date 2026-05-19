<!-- generated-from-dump2 -->
# PyGWalker Tableau-Style DataFrame UI

PyGWalker turns a pandas / polars DataFrame into an interactive Tableau-style visual analysis UI that renders inline in a Jupyter notebook (or as a standalone Streamlit / Gradio component). The clever bit: the front end is a TypeScript drag-and-drop pivot/chart builder (Graphic Walker) that compiles user gestures into a SQL-ish IR, then PyGWalker executes that IR against the DataFrame using DuckDB for the heavy aggregation — so the same UI works on a 100-row in-memory frame and a 10GB Parquet file without code changes. Alternative to plotly express (more code, less GUI) and pandas-profiling (read-only).

```python
import pandas as pd
import pygwalker as pyg

df = pd.read_csv("sales.csv")

# In a Jupyter notebook:
walker = pyg.walk(df)   # opens the full GUI inline

# In a Streamlit app:
from pygwalker.api.streamlit import StreamlitRenderer
renderer = StreamlitRenderer(df, spec="./chart_config.json")
renderer.explorer()
```

## References
- <https://github.com/Kanaries/pygwalker>
