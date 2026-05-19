# DirectXMathVector.inl

Inline implementation file for DirectXMath vector operations: the actual `XMVector*` machinery behind the public `DirectXMath.h` surface. It is header-only by design so the compiler can select SSE/SSE2/AVX/ARM NEON code paths and inline aggressively across translation units. You normally do not include the `.inl` directly; it is useful when debugging codegen, porting DirectXMath to unusual toolchains, or understanding why `XMVECTOR` has strict calling-convention/alignment rules that plain `XMFLOAT4` does not.

Connections: compare with `d3vec.inl.md` for the deprecated D3DX math world and `WindowsNumerics.impl.h.md` for WinRT value types. The split is compute representation (`XMVECTOR`) versus storage/ABI representation (`XMFLOAT*`, WinRT numerics).

## References
- DirectXMathVector.inl
