<!-- generated-from-dump2 -->
# Samurai — Ninja in C

Ninja-compatible build tool written in C; reads build.ninja and executes rules like ninja.

```ninja
rule cc
  command = cl /c /Fo$out $in
  deps = msvc

rule link
  command = link /OUT:$out $in

build main.obj: cc main.c
build app.exe: link main.obj
```

## References
- <https://github.com/michaelforney/samurai>
