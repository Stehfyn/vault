<!-- generated-from-dump2 -->
# FastAPI ASGI Web Framework

ASGI web framework built on Starlette (HTTP/routing) and Pydantic (validation/serialization). The killer feature is that path / query / body parameters are declared as ordinary Python type hints, and the framework derives request parsing, response serialization, and an OpenAPI schema from those same hints — so the docs, the validator, and the client-codegen target are all the same source of truth. Async-first, comparable to Express-style frameworks in terseness, but with static typing baked in. Default rival is Flask (sync, no built-in validation); newer rivals are Litestar and BlackSheep with similar idioms.

```python
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

class Item(BaseModel):
    name: str
    price: float
    in_stock: bool = True

@app.post("/items/", response_model=Item)
async def create_item(item: Item) -> Item:
    if item.price < 0:
        raise HTTPException(status_code=400, detail="price must be >= 0")
    return item

@app.get("/items/{item_id}")
async def read_item(item_id: int, q: str | None = None):
    return {"item_id": item_id, "q": q}

# Run: uvicorn main:app --reload
# Docs auto-generated at /docs (Swagger UI) and /redoc
```

## References
- <https://github.com/fastapi/fastapi>
