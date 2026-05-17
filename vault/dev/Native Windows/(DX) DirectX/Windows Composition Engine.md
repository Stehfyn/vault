# Windows Composition Engine

## Transparent/layered window with DirectComposition
https://stackoverflow.com/questions/64966632/transparent-window-using-windows-composition-engine-in-c
Brief: Create a DComp device, target, and visual for transparent composition.
```cpp
IDCompositionDevice* device = nullptr;
DCompositionCreateDevice(nullptr, IID_PPV_ARGS(&device));
IDCompositionTarget* target = nullptr;
device->CreateTargetForHwnd(hwnd, TRUE, &target);
IDCompositionVisual* visual = nullptr;
device->CreateVisual(&visual);
target->SetRoot(visual);
device->Commit();
```

## Gaussian blur effect setup
https://stackoverflow.com/questions/63381368/direct-composition-idcompositiongaussianblureffect-throwing-access-violation-ex/63384511#63384511
Brief: Create and configure a DComp Gaussian blur effect safely.
```cpp
IDCompositionGaussianBlurEffect* blur = nullptr;
device->CreateGaussianBlurEffect(&blur);
blur->SetBorderMode(D2D1_BORDER_MODE_HARD);
blur->SetStandardDeviation(12.0f);
IDCompositionVisual* visual = nullptr;
device->CreateVisual(&visual);
visual->SetEffect(blur);
```

## DCompositionBoostCompositorClock
https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock
Brief: Temporarily boost compositor clock for smooth animations.
```cpp
BOOL boosted = TRUE;
HRESULT hr = DCompositionBoostCompositorClock(boosted);
if (SUCCEEDED(hr)) {
    device->Commit();
    boosted = FALSE;
    DCompositionBoostCompositorClock(boosted);
}
```
