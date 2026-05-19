<!-- generated-from-dump2 -->
# Cheat Engine DMA Hardware Plugin

Cheat Engine plugin that routes memory reads through a DMA card (PCILeech / FT60x or LeetDMA-style FPGA) instead of through `ReadProcessMemory`. Lets you run CE's pointer scanner, AOB scan, and structure dissect against a target game from a separate sniffer PC — invisible to user-mode anti-cheats.

```text
1. Plug in FT60x/PCILeech DMA hardware, install MemProcFS drivers.
2. Drop the plugin DLL into Cheat Engine\autorun\plugin\.
3. In CE: "Open Process" -> selecting a PID now uses VMM.dll reads.
4. Pointer scans work normally; writes are blocked (DMA is read-only by default).
```

## References
- <https://github.com/kaijia2022/Cheat-Engine-DMA-Plugin>
