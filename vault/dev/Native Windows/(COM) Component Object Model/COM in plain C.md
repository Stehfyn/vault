# COM in Plain C

COM does not require C++; C++ merely gives a convenient syntax for the ABI. In C, an object starts with a pointer to a table of function pointers, `QueryInterface` returns interface pointers whose first member is another compatible vtable pointer, and reference counting is just an ownership convention enforced by `AddRef`/`Release`. That is the same mechanism used by MIDL-generated headers, WinRT's `IInspectable` ABI, and many "no framework" samples in this folder.

The CodeProject article earns its keep by making the hidden layout explicit, but the important caveat is identity: if an object exposes multiple interfaces, each interface pointer may have a different address, while `QueryInterface(IID_IUnknown)` must return the controlling unknown for identity comparison. Single-vtable examples teach the shape; real servers also need aggregation rules, thread-model registration, class factories, marshaling expectations, and exact HRESULT behavior.

```c
typedef struct IThingVtbl IThingVtbl;
typedef struct IThing {
    const IThingVtbl *lpVtbl;
} IThing;

struct IThingVtbl {
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(IThing *self, REFIID riid, void **out);
    ULONG   (STDMETHODCALLTYPE *AddRef)(IThing *self);
    ULONG   (STDMETHODCALLTYPE *Release)(IThing *self);
    HRESULT (STDMETHODCALLTYPE *DoWork)(IThing *self);
};
```

## Connections
- `basetyps.h` supplies the macros that generate this same C-compatible shape.
- "WinRT is fundamentally COM" is the modern version: `IInspectable` extends `IUnknown`, activation factories replace class factories, and metadata replaces type libraries.

## References
- <https://www.codeproject.com/Articles/13601/COM-in-plain-C> - practical walkthrough of handwritten COM vtables and object layout.
