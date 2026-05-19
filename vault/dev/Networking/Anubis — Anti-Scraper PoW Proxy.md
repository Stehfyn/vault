<!-- generated-from-dump2 -->
# Anubis — Anti-Scraper PoW Proxy

Reverse-proxy / middleware that "weighs the soul" of HTTP clients with a JS-based proof-of-work challenge to keep AI scraping bots off open repos and forums. Sits in front of git hosts (Forgejo, GitLab) and presents a SHA-256 PoW gate; legitimate browsers pay the cost once and get a cookie, mass-scrapers without a JS engine bounce.

```yaml
# Compose snippet placing Anubis in front of a backend.
services:
  anubis:
    image: ghcr.io/techarohq/anubis:latest
    environment:
      BIND: ":8923"
      TARGET: "http://app:8080"
      DIFFICULTY: "4"
    ports: ["8923:8923"]
  app:
    image: forgejo/forgejo:1.22
```

## References
- <https://github.com/TecharoHQ/anubis>
