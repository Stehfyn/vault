Since Windows Vista, the `IFileDialogCustomize` interface allows declaratively adding controls (check buttons, combo boxes, labels, separators, edit boxes) to the common file open/save dialogs. The OS handles layout; the app queries control state after the dialog closes, making it forward-compatible with future dialog redesigns.

```cpp
#include <shobjidl.h>

#define IDC_CUSTOM_CHECK  601
#define IDC_CUSTOM_COMBO  602

void ShowCustomFileDialog(HWND hwndOwner) {
    IFileOpenDialog *pDlg = nullptr;
    CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER,
                     IID_PPV_ARGS(&pDlg));

    IFileDialogCustomize *pCustom = nullptr;
    pDlg->QueryInterface(IID_PPV_ARGS(&pCustom));

    // Add a check button
    pCustom->AddCheckButton(IDC_CUSTOM_CHECK, L"Include subfolders", FALSE);

    // Add a labelled combo box
    pCustom->StartVisualGroup(700, L"File Type");
    pCustom->AddComboBox(IDC_CUSTOM_COMBO);
    pCustom->AddControlItem(IDC_CUSTOM_COMBO, 0, L"All Files");
    pCustom->AddControlItem(IDC_CUSTOM_COMBO, 1, L"Text Only");
    pCustom->SetSelectedControlItem(IDC_CUSTOM_COMBO, 0);
    pCustom->EndVisualGroup();
    pCustom->Release();

    if (SUCCEEDED(pDlg->Show(hwndOwner))) {
        pDlg->QueryInterface(IID_PPV_ARGS(&pCustom));
        BOOL bChecked = FALSE;
        pCustom->GetCheckButtonState(IDC_CUSTOM_CHECK, &bChecked);
        DWORD dwSelected = 0;
        pCustom->GetSelectedControlItem(IDC_CUSTOM_COMBO, &dwSelected);
        pCustom->Release();
    }
    pDlg->Release();
}
```

## References
- https://devblogs.microsoft.com/oldnewthing/20211227-00/?p=106054
