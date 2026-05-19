# basetyps.h - COM IDL/RPC Typedefs

`basetyps.h` is one of the quiet foundation headers behind classic COM: it defines the interface-declaration macros and calling-convention vocabulary that let IDL-generated C/C++ headers describe the same ABI. `DECLARE_INTERFACE`, `DECLARE_INTERFACE_`, `STDMETHOD`, `STDMETHOD_`, `PURE`, and the `THIS`/`THIS_` split exist so the same interface can be seen as a C++ abstract class or as a C vtable structure.

The header matters when reading older SDK headers or implementing COM without C++ sugar. It is the connective tissue between "COM in plain C", MIDL output, WinRT's ABI projection, and ATL/WTL wrapper code: all of them eventually reduce to the same pointer-to-vtable layout and `__stdcall` method signatures.

## References
- `basetyps.h` - Windows SDK header that supplies the COM interface macro layer used by generated and handwritten COM declarations.
