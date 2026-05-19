<!-- generated-from-dump2 -->
# Ghidra MCP Server for LLMs

Ghidra extension that exposes the analysis database over the Model Context Protocol (MCP), so Claude/Cursor/Cline can query a live Ghidra project for decompiled functions, xrefs, type info, and rename symbols from chat. Effectively the Ghidra equivalent of the IDA MCP plugins that exploded in 2024-2025.

```json
// claude_desktop_config.json -> add the Ghidra MCP server.
{
  "mcpServers": {
    "ghidra": {
      "command": "java",
      "args": ["-jar", "GhidrAssistMCP.jar", "--project", "C:/RE/sample.gpr"]
    }
  }
}
```

## References
- <https://github.com/symgraph/GhidrAssistMCP>
