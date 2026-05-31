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

## Source Shape

The shell and WinRT notes use this same skeleton with different first interfaces. Classic COM starts at `IUnknown`; WinRT starts at `IInspectable`, which inherits `IUnknown`; shell extensions often hand back multiple interface pointers whose addresses differ but whose controlling `IUnknown` identity must match.

```c
HRESULT STDMETHODCALLTYPE Thing_QueryInterface(IThing *self, REFIID iid, void **out)
{
    if (IsEqualIID(iid, &IID_IUnknown) || IsEqualIID(iid, &IID_IThing)) {
        *out = self;
        self->lpVtbl->AddRef(self);
        return S_OK;
    }
    *out = NULL;
    return E_NOINTERFACE;
}
```

## Discussion Claim To Verify

Claim: two interface pointers on the same object do not have to compare equal, but their controlling `IUnknown` must.

Why it matters to code: shell and WinRT samples frequently pass around `IShellItem`, `IDataObject`, `IPropertyStore`, `IInspectable`, and type-specific interfaces as if pointer equality proved object equality. That is only true for the controlling unknown. A multi-interface COM object can expose different adjusted interface pointers, especially when implemented in C++ with multiple inheritance.

Verification route:

1. Acquire two interfaces from the same object, such as `IShellLinkW` and `IPropertyStore` from `CLSID_ShellLink`, or `IInspectable` and a runtime-specific WinRT interface from an activated WinRT object.
2. Print the raw interface pointer values.
3. Query both for `IID_IUnknown`.
4. Compare the returned `IUnknown *` values.
5. In WinDbg, disassemble the first vtable slot from each interface pointer and verify it is a `QueryInterface`-shaped entry, not an arbitrary data pointer.

```cpp
wil::com_ptr<IShellLinkW> link;
CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link));

wil::com_ptr<IPropertyStore> store;
link.query_to(&store);

wil::com_ptr<IUnknown> u1, u2;
link.query_to(&u1);
store.query_to(&u2);

wprintf(L"link=%p store=%p unk1=%p unk2=%p same_identity=%d\n",
        link.get(), store.get(), u1.get(), u2.get(), u1.get() == u2.get());
```

Interpretation: different `link` and `store` addresses are normal. Different controlling `IUnknown` addresses mean either different COM identities or a broken `QueryInterface` implementation. The Microsoft rule is explicit: object identity is tested through `QueryInterface(IID_IUnknown)`, not by comparing arbitrary interface pointers.

References: <https://learn.microsoft.com/en-us/windows/win32/com/rules-for-implementing-queryinterface> and <https://devblogs.microsoft.com/oldnewthing/20211026-00/?p=105834>.

## Connections
- `basetyps.h` supplies the macros that generate this same C-compatible shape.
- "WinRT is fundamentally COM" is the modern version: `IInspectable` extends `IUnknown`, activation factories replace class factories, and metadata replaces type libraries.
- `../Shell/Explorer++ (Tabbed Win32 Explorer).md` is the shell-client case: many COM interfaces, mostly consumed through C++ helpers.
- `../(WinRT) Windows Runtime/WinUI 3 in Pure C (No cppwinrt).md` is the WinRT-client case: handwritten ABI structs plus activation factories.
- `../(WTL) Windows Template Library/ATL x64 stdcall Thunk Reference.md` is the adjacent callback problem: turning raw ABI callbacks and HWND messages into object methods without changing the underlying calling convention.

## References
- <https://www.codeproject.com/Articles/13601/COM-in-plain-C> - practical walkthrough of handwritten COM vtables and object layout.
