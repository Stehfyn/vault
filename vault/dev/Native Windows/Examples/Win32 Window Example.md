```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if(windoweventcp != NULL && strcmp(windoweventcp, "") != 0){
        if(msg == WM_CREATE && strstr(windoweventcp, "create")) eventfuncs.funccp1();
        if(msg == WM_MOVE && strstr(windoweventcp, "move")) eventfuncs.funccp2();
        if(msg == WM_SIZE && strstr(windoweventcp, "size")) eventfuncs.funccp3();
    }
    switch (msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_COMMAND:
            chkelemsevnts(lParam, wParam, hwnd);
            break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

HWND swapi_createwindow(){
    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, window.windowname, style, window.positionx, window.positiony, window.width, window.height, NULL, NULL, hInstancecp, NULL);
    SetWindowTheme(hwnd, L"DarkMode_Explorer", NULL);
    HFONT hFont = CreateFontW(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(hwnd, WM_SETFONT, (WPARAM) hFont, TRUE);
    GetMessage(&msg, NULL, 0, 0);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return hwnd;
}
```
https://github.com/hyperdregon/SimpleWinAPI/blob/main/src/UI/Windows/NormalWindows/window.c
