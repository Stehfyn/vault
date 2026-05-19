<!-- generated-from-dump2 -->
# Red — Rebol-Inspired Language Toolchain

Red is a Rebol-inspired single-file (~1 MB) language toolchain: cross-compiler, interpreter, REPL, GUI runtime, and packager in one statically-linked binary, no install. The interesting design choices are (a) homoiconic syntax with first-class blocks (`[1 2 3]`) like Rebol, (b) reactive dataflow for the GUI bindings (`face/text: ratio * area` re-evaluates when `ratio` changes), and (c) the compiler bootstraps itself from a tiny low-level dialect called Red/System (a Pascal-meets-C systems language) which is in turn compiled by the Red toolchain itself.

```text
Red [Title: "Hello"]

view [
    title "Demo"
    field f: "type here"
    button "uppercase" [ f/text: uppercase f/text ]
]
; That's it - a working GUI app, no other deps; compile with `red -c file.red`.
```

## References
- <https://github.com/red/red>
