# FastCopy-M — Multilingual Fork of Fast Windows Copier

Multi-language fork of FastCopy — Shirouzu's de-facto fastest Windows file copier. Bypasses Explorer's slow per-file shell hooks, supports overlapped I/O, hash verification (xxHash/SHA), include/exclude regex filters, and `\\?\` long-path / unbuffered modes. The M fork adds Chinese / Korean / Spanish / etc. localization on top of upstream.

```text
# CLI copy with verification, exclude node_modules and .git.
FastCopy.exe /cmd=sync /verify=xxHash /exclude="node_modules\;.git\" \
             /from="D:\src\" /to="E:\backup\"
```

## References
- <https://github.com/Mapaler/FastCopy-M>
