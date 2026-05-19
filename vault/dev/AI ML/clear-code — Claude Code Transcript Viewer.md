<!-- generated-from-dump2 -->
# clear-code — Claude Code Transcript Viewer

Web dashboard for inspecting Claude Code transcripts — point it at your `~/.claude/projects/*/sessions/*.jsonl` files and it renders the tool calls, messages, and edits as a navigable timeline. Useful when you want to audit *what* Claude did during a long agent run without scrolling raw JSONL. The project itself is the dashboard; you provide the logs.

```bash
# Wire up a log directory and serve.
npx clear-code --logs ~/.claude/projects --port 5173
# Then open http://localhost:5173 to browse sessions by project / date.
```

## References
- <https://github.com/chatgptprojects/clear-code>
