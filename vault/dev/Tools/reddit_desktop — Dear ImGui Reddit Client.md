<!-- generated-from-dump2 -->
# reddit_desktop — Dear ImGui Reddit Client

C++ / Dear ImGui desktop Reddit client. Useful only as a reference of an ImGui app talking to a real REST API (Reddit's OAuth, paginated `/r/.../hot.json`, image/comment loading) and rendering image thumbnails inline via stb_image. The pattern to note: a single render thread that pulls from a `std::queue` of "completed" HTTP responses populated by a worker pool, so the UI never blocks on network.

```cpp
// Worker -> UI hand-off pattern used throughout:
std::queue<RedditPost> ready;
std::mutex mu;
std::thread([](std::string url) {
    auto json = http_get(url);
    auto posts = parse_posts(json);
    std::lock_guard g(mu);
    for (auto& p : posts) ready.push(std::move(p));
});

// UI thread, per ImGui frame:
{
    std::lock_guard g(mu);
    while (!ready.empty()) {
        all_posts.push_back(std::move(ready.front()));
        ready.pop();
    }
}
for (auto& p : all_posts) DrawPostCard(p);
```

## References
- <https://github.com/sgiurgiu/reddit_desktop>
