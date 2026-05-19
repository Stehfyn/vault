<!-- generated-from-dump2 -->
# reqwest — Rust HTTP Client

The de-facto Rust HTTP client. Async by default on top of `hyper` + `tokio`, with a blocking facade for scripts. Handles TLS via `rustls` or `native-tls`, cookies, redirects, proxy env vars, multipart, gzip/brotli, and JSON via `serde`. Sean Monstar (hyper, h2) maintains it.

```rust
use serde::Deserialize;

#[derive(Deserialize, Debug)]
struct Ip { origin: String }

#[tokio::main]
async fn main() -> reqwest::Result<()> {
    let ip: Ip = reqwest::Client::new()
        .get("https://httpbin.org/ip")
        .send().await?
        .json().await?;
    println!("ip = {ip:?}");
    Ok(())
}
```

## References
- <https://github.com/seanmonstar/reqwest>
