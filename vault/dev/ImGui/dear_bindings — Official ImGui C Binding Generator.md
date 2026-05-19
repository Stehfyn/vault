<!-- generated-from-dump2 -->
# dear_bindings — Official ImGui C Binding Generator

The *official* successor to cimgui — same idea (parse `imgui.h`, emit a C header + JSON metadata), maintained under the dearimgui org. It's what new binding generators are expected to target. Outputs `dcimgui.h` and `dcimgui.json`; the JSON has full type info, default values, and namespace/enum context, which is what makes it useful for codegen in any target language.

```bash
# Generate the C header + JSON metadata from imgui.h.
python dear_bindings.py --output ./out/dcimgui ../imgui/imgui.h

# Resulting files:
#   out/dcimgui.h     -- flat-C header
#   out/dcimgui.cpp   -- thin C++ -> C trampoline
#   out/dcimgui.json  -- machine-readable API description
```

## References
- <https://github.com/dearimgui/dear_bindings>
