<!-- generated-from-dump2 -->
# sequin — ANSI Escape Sequence Decoder CLI

Pipe-friendly CLI from the Charm team that decodes raw ANSI/VT terminal sequences into human-readable names — `\x1b[31m` becomes `SGR foreground=red`, `\x1b[H` becomes `CUP cursor home`. Eats stdin or a file. Invaluable when debugging your own TUI rendering or reverse-engineering what some other CLI is emitting; the alternative is reading ECMA-48 byte by byte in a hex dump. Written in Go on top of the same `charmbracelet/x/ansi` parser that powers Bubble Tea, so its sequence coverage tends to be ahead of what's in xterm.

```bash
# Decode a captured stream:
$ printf '\x1b[31mhello\x1b[0m world' | sequin
# CSI SGR 31    Set foreground red
# Data          "hello"
# CSI SGR 0     Reset
# Data          " world"

# Pipe a real program through it:
$ vim --clean -c "echo 'hi'" -c "q!" 2>&1 | script -q /dev/null bash -c 'cat' | sequin
```

## References
- <https://github.com/charmbracelet/sequin>
