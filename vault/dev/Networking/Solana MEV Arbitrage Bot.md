<!-- generated-from-dump2 -->
# Solana MEV Arbitrage Bot

Solana MEV arbitrage bot. Uses Geyser gRPC + shredstream (instead of the higher-latency Jupiter aggregator) to see pending transactions early, then constructs multi-hop swap routes across Raydium / Orca / Meteora pools, sized dynamically to maximize profit minus priority fees. README description is keyword-stuffed for SEO; the actual code is a competent low-latency Rust MEV searcher.

```rust
// Pipeline shape (simplified): geyser stream -> pool delta -> route search -> tx build.
let mut stream = GeyserClient::connect("http://geyser:10000").await?
    .subscribe_account_updates(vec![raydium::AMM_PROGRAM]).await?;

while let Some(update) = stream.next().await {
    if let Some(arb) = find_multi_hop_route(&update, &pool_graph) {
        let tx = build_tx(&arb, priority_fee_microlamports(50_000));
        bundle_client.send_bundle(vec![tx]).await?;
    }
}
```

## References
- <https://github.com/katlogic/solana-arbitrage-bot>
