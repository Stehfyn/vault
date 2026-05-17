# MSDelta

Source: https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta

```cpp
DELTA_INPUT source = { srcBytes, srcSize, FALSE };
DELTA_INPUT target = { tgtBytes, tgtSize, FALSE };
DELTA_INPUT empty = { nullptr, 0, FALSE };
DELTA_OUTPUT delta = {};

if (CreateDeltaB(DELTA_FILE_TYPE_RAW, DELTA_FLAG_NONE, 0, source, target,
                 empty, empty, empty, nullptr, 0, &delta)) {
    DELTA_INPUT deltaInput = { delta.lpStart, delta.uSize, FALSE };
    DELTA_OUTPUT applied = {};
    if (ApplyDeltaB(DELTA_FLAG_NONE, source, deltaInput, &applied)) {
        // use applied.lpStart / applied.uSize
        DeltaFree(applied.lpStart);
    }
    DeltaFree(delta.lpStart);
}
```
