# Mesa3D Pre-built Windows Drivers

`mesa-dist-win` packages prebuilt Mesa binaries for Windows so you can test OpenGL through llvmpipe/softpipe and related Mesa components without building the stack yourself. Its practical use is process-local deployment: put the supplied OpenGL DLLs next to a target executable and verify whether a rendering bug is in your app or in a vendor ICD.

Do not treat this as a performance solution. It is a compatibility/debugging tool and a way to make GL tests run on machines where hardware OpenGL is unavailable or inconsistent.

## References
- <https://github.com/pal1000/mesa-dist-win>

## Connections
- `Build Mesa Software OpenGL for Windows.md`
