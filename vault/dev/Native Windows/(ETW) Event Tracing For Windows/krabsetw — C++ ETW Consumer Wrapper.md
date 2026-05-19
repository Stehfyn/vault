# krabsetw - C++ ETW Consumer Wrapper

krabsetw is valuable because it removes most of the brittle plumbing from native ETW consumers: session creation, provider enablement, callback dispatch, schema lookup, and typed property parsing. Raw ETW is powerful but hostile; a serious consumer has to manage `StartTrace`, `EnableTraceEx2`, `OpenTrace`, `ProcessTrace`, TDH property formatting, buffer sizing, and version-specific event layouts. krabsetw compresses that into provider objects and callbacks without hiding the ETW model.

The tradeoff is that it still depends on the quality of provider metadata. Manifest-backed providers decode cleanly; TraceLogging and private providers may require manual field handling or keyword research. It is best treated as a native equivalent to TraceEvent: high-level enough for tools, low-level enough to understand why capture sessions fail or fields disappear.

## Connections
- Sealighter builds the same style of user-mode endpoint sensor around krabsetw.
- ETWStudio helps choose provider names, GUIDs, keywords, and event fields before writing krabsetw callbacks.
- `evntcons.h` and TDH explain the raw records krabsetw wraps.

## References
- <https://github.com/microsoft/krabsetw>
