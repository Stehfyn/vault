<!-- generated-from-dump2 -->
# gli99 — GifCities GeoCities GIF Scraper

Web scraper for the GifCities corpus (the Internet Archive's collection of GIFs from GeoCities pages). Pulls down the indexed GIFs, page-by-page, for offline browsing or training-data assembly. Useful as a small reference of how to scrape an archive that returns JSON-API pages with cursor pagination.

```python
# Conceptual (see repo for actual flags):
import requests
cursor = None
while True:
    r = requests.get("https://gifcities.archive.org/api/v1/gifsearch",
                     params={"q": "*", "cursor": cursor}).json()
    for g in r["gifs"]:
        save(g["url"])
    cursor = r.get("next")
    if not cursor:
        break
```

## References
- <https://github.com/TomTkacz/gli99>
