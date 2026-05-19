<!-- generated-from-dump2 -->
# ifconfig.io — Public IP Echo Service

The Go server behind `ifconfig.io` — a "what's my public IP" service designed for `curl`. The clever bit is content negotiation by client: `curl ifconfig.io` returns just the IP plus a newline (so it composes in shell scripts), `curl ifconfig.io/all.json` returns a structured blob of remote-addr + UA + headers + reverse DNS, and a browser hitting the URL gets an HTML page. Per-path endpoints expose individual fields (`/ip`, `/host`, `/ua`, `/port`, `/lang`, `/encoding`). Mostly a single Go file behind Gin; useful as a 200-line template for "tiny multipurpose HTTP service that respects Accept headers".

```go
// Conceptual handler (real impl uses gin):
// Detects whether the client is a CLI tool by sniffing User-Agent and returns
// plain text by default; opt into JSON via /all.json or Accept: application/json.
func handler(c *gin.Context) {
    ip := c.ClientIP()
    if strings.HasPrefix(c.GetHeader("User-Agent"), "curl/") ||
       c.NegotiateFormat("text/plain") == "text/plain" {
        c.String(200, "%s\n", ip)
        return
    }
    c.JSON(200, gin.H{
        "ip":   ip,
        "ua":   c.GetHeader("User-Agent"),
        "lang": c.GetHeader("Accept-Language"),
        "host": lookupReverse(ip),
    })
}
```

## References
- <https://github.com/georgyo/ifconfig.io>
