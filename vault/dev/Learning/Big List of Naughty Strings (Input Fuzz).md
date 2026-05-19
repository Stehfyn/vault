<!-- generated-from-dump2 -->
# Big List of Naughty Strings (Input Fuzz)

Single text file: ~500 strings curated to break user-input handling code. The categories — and what each catches — are the value: SQL meta-characters and classic injection payloads, Unicode normalization landmines (combining characters that make `len(s)` lie, right-to-left override that reverses display order), zero-width chars that pass `.strip()`, the legendary "Trojan Source" bidi sequences, MS-DOS reserved filenames (`CON`, `PRN`, `AUX`, `NUL`), markdown / HTML injection, leet/Unicode-confusable lookalikes, Apple's "Effective Power" iOS crash string. Feeding the whole list as input to every text field in your app is one of the highest-yield-per-second test exercises you can run. Provided as both raw `blns.txt` and JSON.

```python
# Standard usage: parametrize a test over the list.
import json, pathlib
NAUGHTY = json.loads(pathlib.Path("blns.json").read_text())

def test_input_handler():
    for s in NAUGHTY:
        out = canonicalize_username(s)     # whatever input handler you ship
        # Each candidate should either: (a) be accepted and round-trip, or
        # (b) be rejected with a clean error -- never crash, never bypass.
        assert isinstance(out, str)
```

## References
- <https://github.com/minimaxir/big-list-of-naughty-strings>
