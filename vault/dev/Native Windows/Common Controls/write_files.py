#!/usr/bin/env python3
"""
File operations script to:
1. Detect encoding of Custom Controls.md
2. Update Custom Controls.md with new content
3. Create new markdown files
4. Clear unsorted.md while preserving encoding
"""

import os
import struct

def detect_encoding(file_path):
    """Detect file encoding by checking for BOM markers.
    
    Returns: ('utf-16-le', True) or ('utf-16-be', True) or ('utf-8', True) or ('utf-8', False)
    """
    try:
        with open(file_path, 'rb') as f:
            bom = f.read(4)
        
        # Check BOM markers
        if bom.startswith(b'\xff\xfe\x00\x00'):  # UTF-32 LE
            return ('utf-32', True)
        elif bom.startswith(b'\x00\x00\xfe\xff'):  # UTF-32 BE
            return ('utf-32', True)
        elif bom.startswith(b'\xff\xfe'):  # UTF-16 LE
            return ('utf-16-le', True)
        elif bom.startswith(b'\xfe\xff'):  # UTF-16 BE
            return ('utf-16-be', True)
        elif bom.startswith(b'\xef\xbb\xbf'):  # UTF-8 BOM
            return ('utf-8-sig', True)
        else:
            return ('utf-8', False)
    except Exception as e:
        print(f"Error detecting encoding for {file_path}: {e}")
        return ('utf-8', False)

def write_file_with_encoding(file_path, content, encoding, has_bom, use_crlf=True):
    """Write content to file with specified encoding and line endings.
    
    Args:
        file_path: Path to write to
        content: String content to write
        encoding: Encoding name
        has_bom: Whether original file had BOM (for utf-8, we use utf-8-sig if True)
        use_crlf: If True, normalize line endings to CRLF
    """
    # Normalize line endings to CRLF
    if use_crlf:
        content = content.replace('\r\n', '\n').replace('\n', '\r\n')
    
    # Choose encoding
    if encoding == 'utf-8' and has_bom:
        write_encoding = 'utf-8-sig'
    else:
        write_encoding = encoding
    
    with open(file_path, 'w', encoding=write_encoding, newline='') as f:
        f.write(content)
    
    print(f"✓ {os.path.basename(file_path)} written ({write_encoding}, CRLF)")

# Target directory
target_dir = r'C:\dev\vault\vault\dev\Native Windows\Common Controls'
os.makedirs(target_dir, exist_ok=True)

print(f"Target directory: {target_dir}\n")

# Step 1 & 2: Read Custom Controls.md and detect encoding
custom_controls_path = os.path.join(target_dir, 'Custom Controls.md')
encoding_cc, has_bom_cc = detect_encoding(custom_controls_path) if os.path.exists(custom_controls_path) else ('utf-8', False)
print(f"Step 1: Custom Controls.md encoding detected: {encoding_cc} (BOM: {has_bom_cc})")

custom_controls_content = """## References
- https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles
- https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp
- https://github.com/jkopa/Win32-Window
- https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/Visual%20C%2B%2B%202008%20Feature%20Pack
- https://github.com/MicrosoftDocs/win32/tree/docs/desktop-src

---

## NM_CUSTOMDRAW — Custom Button Painting with Gradient

Source: https://stackoverflow.com/questions/18745447/how-can-i-change-the-background-color-of-a-button-winapi-c

Handle `WM_NOTIFY` → `NM_CUSTOMDRAW` to fully paint a button. Use `CDIS_SELECTED` / `CDIS_HOT` for state-dependent visuals. Return `CDRF_DODEFAULT` to let Windows draw the text/focus rect.

```cpp
// Gradient brush helper — builds a pattern brush by drawing scanlines into a compat bitmap
HBRUSH CreateGradientBrush(COLORREF top, COLORREF bottom, LPNMCUSTOMDRAW item)
{
    HDC hdcmem = CreateCompatibleDC(item->hdc);
    HBITMAP hbitmap = CreateCompatibleBitmap(item->hdc,
        item->rc.right - item->rc.left,
        item->rc.bottom - item->rc.top);
    SelectObject(hdcmem, hbitmap);

    int r1 = GetRValue(top),  r2 = GetRValue(bottom);
    int g1 = GetGValue(top),  g2 = GetGValue(bottom);
    int b1 = GetBValue(top),  b2 = GetBValue(bottom);
    int h = item->rc.bottom - item->rc.top;

    for (int i = 0; i < h; ++i)
    {
        int r = r1 + (i * (r2 - r1)) / h;
        int g = g1 + (i * (g2 - g1)) / h;
        int b = b1 + (i * (b2 - b1)) / h;
        HBRUSH line = CreateSolidBrush(RGB(r, g, b));
        RECT rc = { 0, i, item->rc.right - item->rc.left, i + 1 };
        FillRect(hdcmem, &rc, line);
        DeleteObject(line);
    }

    HBRUSH pattern = CreatePatternBrush(hbitmap);
    DeleteDC(hdcmem);
    DeleteObject(hbitmap);
    return pattern;
}

// In WndProc — WM_NOTIFY handler
case WM_NOTIFY:
{
    LPNMHDR hdr = (LPNMHDR)lParam;
    if (hdr->idFrom == IDC_MY_BUTTON && hdr->code == NM_CUSTOMDRAW)
    {
        LPNMCUSTOMDRAW cd = (LPNMCUSTOMDRAW)lParam;
        static HBRUSH hDefault = NULL, hHot = NULL, hSel = NULL;

        COLORREF clrTop, clrBot;
        if (cd->uItemState & CDIS_SELECTED)
            clrTop = RGB(180,0,0),   clrBot = RGB(255,180,0);
        else if (cd->uItemState & CDIS_HOT)
            clrTop = RGB(255,230,0), clrBot = RGB(245,0,0);
        else
            clrTop = RGB(255,180,0), clrBot = RGB(180,0,0);

        HBRUSH& brush = (cd->uItemState & CDIS_SELECTED) ? hSel
                      : (cd->uItemState & CDIS_HOT)      ? hHot : hDefault;
        if (!brush) brush = CreateGradientBrush(clrTop, clrBot, cd);

        HPEN pen = CreatePen(PS_INSIDEFRAME, 0, RGB(0,0,0));
        HGDIOBJ oldPen   = SelectObject(cd->hdc, pen);
        HGDIOBJ oldBrush = SelectObject(cd->hdc, brush);

        RoundRect(cd->hdc, cd->rc.left, cd->rc.top,
                            cd->rc.right, cd->rc.bottom, 5, 5);

        SelectObject(cd->hdc, oldPen);
        SelectObject(cd->hdc, oldBrush);
        DeleteObject(pen);

        return CDRF_DODEFAULT; // let Windows draw label / focus rect
    }
    break;
}
```
"""

print("Step 2: Updating Custom Controls.md...")
write_file_with_encoding(custom_controls_path, custom_controls_content, encoding_cc, has_bom_cc)

# Step 3: Create Visual Styles.md
visual_styles_content = """## References
- https://stackoverflow.com/questions/51969459/how-to-enable-microsoft-windows-common-controls-for-specificate-control
- https://github.com/wine-mirror/wine/blob/master/dlls/uxtheme/draw.c

---

## Activation Context — Enable ComCtrl v6 for a Single Control

Without a v6 manifest, the process defaults to ComCtrl v5. You can activate a ComCtrl v6 context just for the `CreateWindow` call of a specific control, then deactivate it.

Source: https://stackoverflow.com/questions/51969459/how-to-enable-microsoft-windows-common-controls-for-specificate-control

```cpp
// Borrow resource #124 from shell32.dll which embeds a ComCtrl v6 manifest.
// In production, point lpSource to your own manifest file or embed it.
ACTCTX ctx = {};
ctx.cbSize        = sizeof(ctx);
ctx.dwFlags       = ACTCTX_FLAG_RESOURCE_NAME_VALID
                  | ACTCTX_FLAG_SET_PROCESS_DEFAULT
                  | ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID;
ctx.lpSource             = TEXT("shell32.dll");
ctx.lpAssemblyDirectory  = TEXT("C:\\\\Windows\\\\System32\\\\");
ctx.lpResourceName       = MAKEINTRESOURCE(124);

HANDLE hActCtx = CreateActCtx(&ctx);
if (hActCtx == INVALID_HANDLE_VALUE)
    return; // handle error

ULONG_PTR ulCookie = 0;
if (!ActivateActCtx(hActCtx, &ulCookie))
{
    ReleaseActCtx(hActCtx);
    return;
}

// --- Create the control that needs v6 theming ---
HWND hEdit = CreateWindowEx(0, WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
    10, 10, 200, 24, hParent, (HMENU)IDC_EDIT, hInst, NULL);
SendMessage(hEdit, EM_SETCUEBANNER, FALSE, (LPARAM)L"Placeholder text");
// ------------------------------------------------

DeactivateActCtx(0, ulCookie);
ReleaseActCtx(hActCtx);
```

> **Why:** `EM_SETCUEBANNER` and visual theming on edit/list controls require ComCtrl v6.
> Wrapping only the `CreateWindow` call avoids changing the global manifest for the whole process.
"""

visual_styles_path = os.path.join(target_dir, 'Visual Styles.md')
print("Step 3: Creating Visual Styles.md...")
write_file_with_encoding(visual_styles_path, visual_styles_content, encoding_cc, has_bom_cc)

# Step 4: Create Window Messaging.md
window_messaging_content = """## References
- https://learn.microsoft.com/en-us/windows/win32/api/Winuser/ns-winuser-copydatastruct
- https://learn.microsoft.com/en-us/windows/win32/dataxchg/wm-copydata

---

## WM_COPYDATA — Cross-Process Data Transfer

`WM_COPYDATA` + `COPYDATASTRUCT` is the simplest built-in mechanism for passing arbitrary read-only data between processes. The OS copies the buffer across process boundaries; the receiving window must duplicate the data if it needs it after the handler returns.

```cpp
// ── Sender ──────────────────────────────────────────────────────────────────
void SendStringToWindow(HWND hTarget, HWND hSelf, const wchar_t* text)
{
    // dwData is a user-defined type tag the receiver uses to identify the payload
    COPYDATASTRUCT cds = {};
    cds.dwData = 1; // e.g. 1 = "wstring message"
    cds.cbData = (DWORD)((wcslen(text) + 1) * sizeof(wchar_t));
    cds.lpData = (PVOID)text;

    // Must use SendMessage (not PostMessage) — lParam is only valid during the call
    SendMessage(hTarget, WM_COPYDATA, (WPARAM)hSelf, (LPARAM)&cds);
}

// ── Receiver (WndProc) ───────────────────────────────────────────────────────
case WM_COPYDATA:
{
    const COPYDATASTRUCT* cds = (const COPYDATASTRUCT*)lParam;
    if (cds->dwData == 1 && cds->lpData && cds->cbData > 0)
    {
        // lpData is only valid here — copy it before returning
        std::wstring msg(static_cast<const wchar_t*>(cds->lpData),
                         cds->cbData / sizeof(wchar_t));
        // strip null terminator if present
        if (!msg.empty() && msg.back() == L'\\0') msg.pop_back();

        // process msg ...
        OutputDebugStringW(msg.c_str());
    }
    return TRUE; // indicate the message was processed
}
```

> **Constraints:**
> - `lpData` must not contain pointers (they'd be invalid in the target process).
> - The data must not be modified by another thread while `SendMessage` is in flight.
> - Use `SendMessage`, never `PostMessage` — the buffer is freed after the call returns.
"""

window_messaging_path = os.path.join(target_dir, 'Window Messaging.md')
print("Step 4: Creating Window Messaging.md...")
write_file_with_encoding(window_messaging_path, window_messaging_content, encoding_cc, has_bom_cc)

# Step 5: Create Rendering.md
rendering_content = """## References
- https://stackoverflow.com/questions/26700236/flicker-when-moving-resizing-window/53017156#53017156
- https://stackoverflow.com/questions/61915005/force-win32-common-controls-to-draw-on-id2d1hwndrendertarget/62775968#62775968

---

## Flicker-Free Resize via WM_NCCALCSIZE

Source: https://stackoverflow.com/questions/26700236/flicker-when-moving-resizing-window/53017156#53017156

Windows internally `BitBlt`s the old client area during resize. This causes the stretched-edge artifact. The fix: make the `src`/`dst` blit rects 1×1 so the copy is a no-op.

```cpp
case WM_NCCALCSIZE:
{
    if (!wParam) break; // wParam==0: just map window→client rect, no src/dst

    NCCALCSIZE_PARAMS* np = (NCCALCSIZE_PARAMS*)lParam;
    RECT ocr = np->rgrc[2]; // save old client rect before DefWindowProc stomps it

    LRESULT ret = DefWindowProc(hwnd, WM_NCCALCSIZE, wParam, lParam);

    RECT& dst = np->rgrc[1]; // blit destination
    RECT& src = np->rgrc[2]; // blit source (was old client rect)

    // Collapse src & dst to a 1×1 rect so Windows copies nothing visible.
    dst.right  = dst.left + 1;
    dst.bottom = dst.top  + 1;
    src.right  = dst.left + 1;
    src.bottom = dst.top  + 1;

    return WVR_VALIDRECTS;
}
```

Alternative: intercept `WM_WINDOWPOSCHANGING` and set `SWP_NOCOPYBITS`:
```cpp
case WM_WINDOWPOSCHANGING:
{
    LRESULT r = DefWindowProc(hwnd, uMsg, wParam, lParam);
    WINDOWPOS* wp = (WINDOWPOS*)lParam;
    wp->flags |= SWP_NOCOPYBITS;
    return r;
}
```

> **Note (Win10/DWM):** DWM also replicates edge pixels when compositing. There is no public API to suppress it. The above fixes the GDI-layer BitBlt but DWM artifacts may still appear briefly.

---

## GDI + Direct2D Interop via ID2D1DCRenderTarget

Source: https://stackoverflow.com/questions/61915005/force-win32-common-controls-to-draw-on-id2d1hwndrendertarget/62775968#62775968

`ID2D1DCRenderTarget` binds to an `HDC`, allowing D2D and GDI (including Win32 common controls) to share the same device context in a single `WM_PAINT` handler.

```cpp
// --- Device-independent setup (once) ---
ID2D1Factory*         g_pD2DFactory = nullptr;
ID2D1DCRenderTarget*  g_pDCRT       = nullptr;
ID2D1SolidColorBrush* g_pBrush      = nullptr;

void CreateD2DResources()
{
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &g_pD2DFactory);

    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE));

    g_pD2DFactory->CreateDCRenderTarget(&props, &g_pDCRT);
    g_pDCRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::SteelBlue), &g_pBrush);
}

// --- WM_PAINT: D2D first, then GDI controls draw on top ---
case WM_PAINT:
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    RECT rc;
    GetClientRect(hwnd, &rc);

    // Bind the DC render target to the paint HDC
    g_pDCRT->BindDC(hdc, &rc);
    g_pDCRT->BeginDraw();
    g_pDCRT->Clear(D2D1::ColorF(D2D1::ColorF::White));
    // ... D2D drawing calls ...
    g_pDCRT->DrawEllipse(
        D2D1::Ellipse(D2D1::Point2F(150.f, 150.f), 80.f, 80.f),
        g_pBrush, 2.f);
    g_pDCRT->EndDraw();

    // GDI draws on the same HDC — Win32 controls will paint here via WM_PAINT
    // or you can manually draw GDI primitives:
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    HGDIOBJ old = SelectObject(hdc, hPen);
    MoveToEx(hdc, 300, 50, NULL);
    LineTo(hdc,   500, 250);
    SelectObject(hdc, old);
    DeleteObject(hPen);

    EndPaint(hwnd, &ps);
    return 0;
}
```
"""

rendering_path = os.path.join(target_dir, 'Rendering.md')
print("Step 5: Creating Rendering.md...")
write_file_with_encoding(rendering_path, rendering_content, encoding_cc, has_bom_cc)

# Step 6: Create Borderless Window.md
borderless_window_content = """## References
- https://stackoverflow.com/questions/66165781/it-is-possible-to-adjust-the-offset-of-cs-dropshadow-on-a-window-class
- https://stackoverflow.com/questions/39731497/create-window-without-titlebar-with-resizable-border-and-without-bogus-6px-whit
- https://github.com/melak47/BorderlessWindow
- https://learn.microsoft.com/en-us/windows/win32/dwm/customframe

---

## Borderless Resizable Window (Win10 — DWM shadow + resize)

Source: https://stackoverflow.com/questions/39731497/create-window-without-titlebar-with-resizable-border-and-without-bogus-6px-whit

Key technique: use `WS_THICKFRAME | WS_POPUP` to get OS resize cursors and snap behavior, `DwmExtendFrameIntoClientArea` with zero margins to collapse the NC frame, and manually implement `WM_NCHITTEST` to expose the resize border.

```cpp
// Requires: Dwmapi.lib, UxTheme.lib
// #include <Dwmapi.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static RECT border; // thickness of the invisible resize border

    switch (uMsg)
    {
    case WM_CREATE:
    {
        // Compute the actual border thickness (negative → positive)
        SetRectEmpty(&border);
        DWORD style = (DWORD)GetWindowLongPtr(hwnd, GWL_STYLE);
        if (style & WS_THICKFRAME)
        {
            AdjustWindowRectEx(&border, style & ~WS_CAPTION, FALSE, 0);
            border.left  *= -1;
            border.top   *= -1;
        }
        else if (style & WS_BORDER)
            SetRect(&border, 1, 1, 1, 1);

        // Collapse the DWM NC frame so we own the full client area,
        // but keep the DWM shadow (margins={0} ≠ margins={-1})
        MARGINS margins = {};
        DwmExtendFrameIntoClientArea(hwnd, &margins);
        SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
            SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
        return 0;
    }

    case WM_NCCALCSIZE:
        // Returning 0 makes the client rect equal to the window rect (removes NC area).
        // Preserve top border for Windows 10 resize grip.
        if (lParam)
        {
            NCCALCSIZE_PARAMS* sz = (NCCALCSIZE_PARAMS*)lParam;
            sz->rgrc[0].left   += border.left;
            sz->rgrc[0].right  -= border.right;
            sz->rgrc[0].bottom -= border.bottom;
            // Keep sz->rgrc[0].top unchanged so the title-bar resize area works
            return 0;
        }
        break;

    case WM_NCHITTEST:
    {
        // Let DefWindowProc try first (handles resize grips in NC area)
        LRESULT hit = DefWindowProc(hwnd, uMsg, wParam, lParam);
        if (hit == HTCLIENT)
        {
            POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
            ScreenToClient(hwnd, &pt);
            // Expose top resize border (sits inside client area after WM_NCCALCSIZE)
            if (pt.y < border.top) return HTTOP;
        }
        return hit;
    }

    case WM_NCACTIVATE:
        return 0; // prevent NC repaint flash during activation change

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Window creation — WS_THICKFRAME gives resize cursors & aero snap
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, PWSTR, int)
{
    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInst;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"BorderlessWnd";
    RegisterClass(&wc);

    CreateWindowEx(0, L"BorderlessWnd", NULL,
        WS_VISIBLE | WS_THICKFRAME | WS_POPUP,
        100, 100, 800, 600, NULL, NULL, hInst, NULL);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    { TranslateMessage(&msg); DispatchMessage(&msg); }
    return 0;
}
```

---

## DWM Aero Shadow for Popup Windows

`CS_DROPSHADOW` is for tool/popup windows. For proper resizable borderless windows the shadow comes from `DwmExtendFrameIntoClientArea` with `MARGINS {1,1,1,1}`:

```cpp
auto set_shadow = [](HWND hwnd, bool enabled)
{
    BOOL comp = FALSE;
    DwmIsCompositionEnabled(&comp);
    if (!comp) return;
    static const MARGINS kShadow[2] = { {0,0,0,0}, {1,1,1,1} };
    DwmExtendFrameIntoClientArea(hwnd, &kShadow[enabled ? 1 : 0]);
};

// Call after creating (or toggling) the borderless style:
set_shadow(hwnd, true);
```
"""

borderless_window_path = os.path.join(target_dir, 'Borderless Window.md')
print("Step 6: Creating Borderless Window.md...")
write_file_with_encoding(borderless_window_path, borderless_window_content, encoding_cc, has_bom_cc)

# Step 7: Create Window Sizing.md
window_sizing_content = """## References
- https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-getminmaxinfo
- https://stackoverflow.com/questions/4134946/wm-getminmaxinfo-does-not-seem-to-work-how-to-get-a-windows-minimum-and-maximu

---

## WM_GETMINMAXINFO — Constrain Window Size

Sent before a resize/move operation. Override `MINMAXINFO` members to clamp the window.  
Windows pre-fills the struct with defaults; only set the fields you need to change.

```cpp
case WM_GETMINMAXINFO:
{
    MINMAXINFO* mmi = (MINMAXINFO*)lParam;

    // Minimum tracking size (user drags borders)
    mmi->ptMinTrackSize.x = 400; // min width  (pixels)
    mmi->ptMinTrackSize.y = 300; // min height (pixels)

    // Maximum tracking size (user drags borders — optional)
    mmi->ptMaxTrackSize.x = 1920;
    mmi->ptMaxTrackSize.y = 1080;

    // Maximized position and size — clamp to work area of the window's monitor
    HMONITOR hMon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = { sizeof(mi) };
    if (GetMonitorInfo(hMon, &mi))
    {
        RECT& wa = mi.rcWork;
        mmi->ptMaxPosition.x = wa.left;
        mmi->ptMaxPosition.y = wa.top;
        mmi->ptMaxSize.x     = wa.right  - wa.left;
        mmi->ptMaxSize.y     = wa.bottom - wa.top;
    }

    return 0;
}
```

> **Notes:**
> - `ptMaxPosition` is in virtual-screen coordinates (important on multi-monitor).
> - Use `MonitorFromWindow` → `GetMonitorInfo` so the window maximizes onto the correct monitor.
> - The message is *not* a query you can poll — it is only sent during an impending resize/move.
>   `SendMessage(hwnd, WM_GETMINMAXINFO, ...)` won't return current min/max from the OS.
"""

window_sizing_path = os.path.join(target_dir, 'Window Sizing.md')
print("Step 7: Creating Window Sizing.md...")
write_file_with_encoding(window_sizing_path, window_sizing_content, encoding_cc, has_bom_cc)

# Step 8: Read unsorted.md, detect encoding, and clear it
unsorted_path = os.path.join(target_dir, 'unsorted.md')
if os.path.exists(unsorted_path):
    encoding_unsorted, has_bom_unsorted = detect_encoding(unsorted_path)
    print(f"\nStep 8: unsorted.md encoding detected: {encoding_unsorted} (BOM: {has_bom_unsorted})")
    
    # Write empty content with same encoding
    write_file_with_encoding(unsorted_path, '', encoding_unsorted, has_bom_unsorted)
else:
    print(f"\nStep 8: unsorted.md does not exist, skipping")

print("\n✅ All operations completed successfully!")
