# Drag and Drop

Win32 drag-and-drop for files uses `DragAcceptFiles` + `WM_DROPFILES`. For richer shell DnD (drag from your app to Explorer, support for virtual files) implement `IDropSource` / `IDropTarget`.

```cpp
// Accept dropped files
DragAcceptFiles(hwnd, TRUE);

case WM_DROPFILES: {
  HDROP drop = (HDROP)wParam;
  UINT count = DragQueryFileW(drop, 0xFFFFFFFF, nullptr, 0);
  for (UINT i = 0; i < count; ++i) {
    WCHAR file[MAX_PATH] = {};
    DragQueryFileW(drop, i, file, MAX_PATH);
    // process file...
  }
  DragFinish(drop);
  break;
}
```

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms692761(v=vs.85)

## Source Code Reading

Explorer++ shows the Shell drag/drop path that the short `WM_DROPFILES` sample does not. In `Explorer++/Helper/DragDropHelper.cpp`, file and namespace drags start from absolute PIDLs, not paths:

1. `SHCreateShellItemArrayFromIDLists` turns PIDLs into an `IShellItemArray`.
2. `IShellItemArray::GetAttributes(SIATTRIBFLAGS_AND, SFGAO_*)` computes allowed effects.
3. `BindToHandler(BHID_DataObject)` obtains the Shell `IDataObject`.
4. `CFSTR_PREFERREDDROPEFFECT` and `CFSTR_DROPDESCRIPTION` are written as private clipboard formats when needed.
5. `SHDoDragDrop` starts the drag with allowed effects.

```cpp
array->GetAttributes(SIATTRIBFLAGS_AND, SFGAO_CANCOPY | SFGAO_CANMOVE, &attrs);
array->BindToHandler(nullptr, BHID_DataObject, IID_PPV_ARGS(&data));
SetBlobData(data.get(), RegisterClipboardFormat(CFSTR_PREFERREDDROPEFFECT), effect);
SHDoDragDrop(nullptr, data.get(), nullptr, allowedEffects, &result);
```

`Explorer++/Helper/ClipboardHelper.cpp` also demonstrates a practical paste probe. `CanShellPasteDataObject` binds the destination PIDL to `IShellFolder`, asks the folder for an `IDropTarget` via `CreateViewObject`, intersects allowed effects with the source's preferred effect, then calls `IDropTarget::DragEnter`. That turns "can I paste here?" into the same contract the real drop target will execute.

```cpp
SHBindToObject(nullptr, destinationPidl, nullptr, IID_PPV_ARGS(&folder));
folder->CreateViewObject(nullptr, IID_PPV_ARGS(&dropTarget));
dropTarget->DragEnter(dataObject, MK_LBUTTON, {0, 0}, &effect);
```

Claim -> source/probe -> interpretation:

Claim: `CF_HDROP` is a compatibility format, not the Shell drag/drop contract.
Source/probe: copy a normal file, a shell virtual item, and a cloud placeholder; enumerate `IDataObject::EnumFormatEtc` and test for `CF_HDROP`, `CFSTR_SHELLIDLIST`, `CFSTR_FILEDESCRIPTOR`, and `CFSTR_FILECONTENTS`.
Interpretation: if only `CF_HDROP` is consumed, virtual folders and deferred file contents are invisible to the app.

## Discussion Claim To Verify

Claim: `IDataObject::GetData` returns caller-owned `STGMEDIUM` storage, but `IDataObject::SetData(..., fRelease=TRUE)` transfers ownership to the data object.

Why it matters to code: drag/drop bugs often masquerade as "Explorer gave me a null handle" or "the drop target corrupted my data." In practice, the source or target frequently releases a medium it no longer owns, forgets to release one it does own, or ignores `punkForRelease`.

Verification route:

1. In a test `IDataObject`, log every `GetData` and `SetData` call: `cfFormat`, `tymed`, `lindex`, `hGlobal`/`pstm`, `punkForRelease`, and `fRelease`.
2. For `GetData`, have the caller always release successful media with `ReleaseStgMedium`.
3. For `SetData`, only release immediately when `fRelease == FALSE`; when `TRUE`, copy or store the medium and release it when the data object is destroyed or the data is replaced.
4. Test with Explorer file drag, ZIP-folder drag, and a virtual/cloud item.

```cpp
HRESULT MyDataObject::SetData(FORMATETC *fmt, STGMEDIUM *med, BOOL release)
{
    printf("SetData cf=%u tymed=%lx lindex=%ld release=%d h=%p punk=%p\n",
           fmt->cfFormat, med->tymed, fmt->lindex, release,
           med->hGlobal, med->pUnkForRelease);

    if (release) {
        stored_ = *med;          // data object now owns this medium
        return S_OK;
    }

    return CloneMedium(fmt, med, &stored_); // caller still owns original
}
```

Interpretation: crashes after `DoDragDrop` returns usually mean the medium lifetime contract was violated. A null `hGlobal` with `TYMED_ISTREAM` is not a null transfer; it means the payload is stream-backed. For virtual files, `CFSTR_FILEDESCRIPTOR` plus indexed `CFSTR_FILECONTENTS` is the normal path.

Audited discussion/source links:

- <https://stackoverflow.com/questions/69650213/shcreatedataobject-idataobject-exhibits-strange-behavior-during-cdefviewonbegi> - useful because the symptom looks like Explorer weirdness but routes to medium ownership and Shell private formats.
- <https://stackoverflow.com/questions/5990019/drag-and-drop-files-from-a-zip-folder-into-my-window> - ZIP-folder drag is a good falsifier for `CF_HDROP`-only code.
- <https://learn.microsoft.com/en-us/windows/win32/shell/clipboard> - official route for `CFSTR_FILEDESCRIPTOR` / `CFSTR_FILECONTENTS`.
- <https://learn.microsoft.com/en-us/windows/win32/shell/datascenarios> - official scenario route for Shell data objects and virtual file contents.

## Experiment Harness

Goal: inspect the actual shell data object before implementing a drop target.

```cpp
OleInitialize(nullptr);              // not plain CoInitialize
wil::com_ptr<IDataObject> data;
HRESULT hr = OleGetClipboard(&data); // copy files in Explorer first

FORMATETC fmt{ CF_HDROP, nullptr, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
STGMEDIUM stg{};
HRESULT hdrop = data ? data->GetData(&fmt, &stg) : E_POINTER;
printf("OleGetClipboard=%08lx CF_HDROP=%08lx tymed=%lx\n", hr, hdrop, stg.tymed);
if (SUCCEEDED(hdrop)) ReleaseStgMedium(&stg);
```

Procedure: copy a normal file, a OneDrive placeholder, and a virtual shell item if available; compare formats with `IDataObject::EnumFormatEtc`.

Measured signal: offered clipboard formats, `TYMED_*`, `CF_HDROP` availability, and whether the target needed OLE initialization.

Failure interpretation: `CF_HDROP`-only code is path-transfer code, not general Shell drag/drop. Reference: <https://learn.microsoft.com/windows/win32/shell/dragdrop>.
