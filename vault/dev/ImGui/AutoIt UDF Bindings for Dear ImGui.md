<!-- generated-from-dump2 -->
# AutoIt UDF Bindings for Dear ImGui

AutoIt UDF (User Defined Functions) bindings for Dear ImGui — lets you build an ImGui UI from AutoIt scripts using `DllCall` into a compiled cimgui DLL. Useful in Windows automation workflows where AutoIt is already in the toolbox and you want a *real* UI instead of MsgBox / GUI*-control soup.

```autoit
#include "imgui.au3"

_ImGui_CreateContext()
_ImGui_BackendWin32_Init($hWnd)
_ImGui_BackendDX11_Init($pDevice, $pCtx)

While 1
    _ImGui_BackendDX11_NewFrame()
    _ImGui_BackendWin32_NewFrame()
    _ImGui_NewFrame()
    _ImGui_Begin("Hello from AutoIt")
        If _ImGui_Button("Click") Then ConsoleWrite("clicked!" & @CRLF)
    _ImGui_End()
    _ImGui_Render()
    _ImGui_BackendDX11_RenderDrawData()
WEnd
```

## References
- <https://github.com/thedemons/imgui-autoit>
