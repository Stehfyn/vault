<!-- generated-from-dump2 -->
# yomomma — FastAPI Joke Endpoint

Tiny FastAPI service that returns a random "yo momma" joke from a static JSON file. The kind of repo whose actual value is as a copy-paste starter for "FastAPI + Heroku/Render + a single-endpoint JSON response" — minimal pyproject, single `main.py`, a `jokes.json`, deployed publicly. Useful in pipeline / hello-world testing as a public dependency-free JSON endpoint that returns a string.

```python
# Shape of the API (one route)
import httpx
r = httpx.get("https://yomomma-api.herokuapp.com/jokes")
print(r.json())  # {"joke": "yo momma so..."}

# Or self-host:
from fastapi import FastAPI
import json, random

app = FastAPI()
jokes = json.load(open("jokes.json"))

@app.get("/jokes")
def random_joke():
    return {"joke": random.choice(jokes)}
```

## References
- <https://github.com/beanboi7/yomomma-apiv2>
