# propvarutil.h

Helper layer on top of the `PROPVARIANT` tagged union (defined in `propidl.h`) used everywhere by the Shell property system, WIA, WIC metadata, IFilter, structured storage. Provides typed initializers (`InitPropVariantFromString`, `InitPropVariantFromBoolean`, `InitPropVariantFromUInt64Vector`, `InitPropVariantFromFileTime`), extractors (`PropVariantToStringAlloc`, `PropVariantToInt32`, `PropVariantToBuffer`), comparison (`PropVariantCompareEx` -- which understands locale and "as ints vs. as strings"), and the absolutely essential `PropVariantClear` / `PropVariantChangeType`. The trap: `PROPVARIANT` is a discriminated union with VT_LPWSTR, VT_BSTR, VT_VARIANT, VT_BLOB, VT_VECTOR | VT_*, etc. -- they each own memory differently, and `PropVariantClear` is the only correct universal cleanup; freeing manually is a great way to corrupt the heap.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/propvarutil/>
