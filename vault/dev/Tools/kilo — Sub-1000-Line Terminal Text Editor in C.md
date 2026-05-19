<!-- generated-from-dump2 -->
# kilo — Sub-1000-Line Terminal Text Editor in C

Salvatore Sanfilippo's terminal text editor in <1024 lines of dependency-free C. Real syntax highlighting (C/C++ out of the box), incremental search, raw-mode TTY handling, and a tiny refresh routine that builds an ANSI-escape diff per keystroke. Canonical reference implementation taught by snaptoken's "Build Your Own Text Editor" tutorial.

```bash
cc -o kilo kilo.c
./kilo source.c
# Keys: Ctrl-S save, Ctrl-Q quit, Ctrl-F find.
```

## References
- <https://github.com/antirez/kilo>
