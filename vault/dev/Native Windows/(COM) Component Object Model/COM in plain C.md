COM interfaces can be defined and implemented in plain C by manually constructing vtable structs. Each COM object has a pointer to its vtable as its first member, mirroring the C++ ABI layout. `IUnknown` is the root interface every COM object must implement.

```c
#include <windows.h>
#include <unknwn.h>

/* Forward-declare our object type */
typedef struct MyObject MyObject;

/* Define the vtable */
typedef struct MyObjectVtbl {
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(MyObject *this_, REFIID riid, void **ppv);
    ULONG   (STDMETHODCALLTYPE *AddRef)        (MyObject *this_);
    ULONG   (STDMETHODCALLTYPE *Release)       (MyObject *this_);
} MyObjectVtbl;

/* Object struct — vtable pointer MUST be first member */
struct MyObject {
    const MyObjectVtbl *lpVtbl;
    LONG refCount;
};

static HRESULT STDMETHODCALLTYPE MyObject_QueryInterface(MyObject *this_, REFIID riid, void **ppv) {
    if (IsEqualIID(riid, &IID_IUnknown)) {
        *ppv = this_;
        this_->lpVtbl->AddRef(this_);
        return S_OK;
    }
    *ppv = NULL;
    return E_NOINTERFACE;
}
static ULONG STDMETHODCALLTYPE MyObject_AddRef(MyObject *this_) {
    return InterlockedIncrement(&this_->refCount);
}
static ULONG STDMETHODCALLTYPE MyObject_Release(MyObject *this_) {
    ULONG rc = InterlockedDecrement(&this_->refCount);
    if (rc == 0) free(this_);
    return rc;
}

static const MyObjectVtbl MyObject_Vtbl = {
    MyObject_QueryInterface,
    MyObject_AddRef,
    MyObject_Release,
};

MyObject *MyObject_Create(void) {
    MyObject *obj = (MyObject *)malloc(sizeof(MyObject));
    obj->lpVtbl   = &MyObject_Vtbl;
    obj->refCount = 1;
    return obj;
}
```

## References
- https://www.codeproject.com/Articles/13601/COM-in-plain-C
