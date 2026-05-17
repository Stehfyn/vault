# GPU Device Selection

## Khronos forum: device choice and affinity
https://community.khronos.org/t/how-to-use-opengl-with-a-device-chosen-by-you/63017/9
Brief: Use vendor GPU-affinity extensions to pick a device after ICD selection.
```c
auto wglEnumGpusNV = (BOOL (WINAPI *)(UINT, HGPUNV*))wglGetProcAddress("wglEnumGpusNV");
auto wglCreateAffinityDCNV = (HDC (WINAPI *)(const HGPUNV*))wglGetProcAddress("wglCreateAffinityDCNV");
HGPUNV gpu = nullptr;
if (wglEnumGpusNV && wglEnumGpusNV(0, &gpu)) {
    HGPUNV gpus[] = { gpu, nullptr };
    HDC affinityDc = wglCreateAffinityDCNV(gpus);
}
```
