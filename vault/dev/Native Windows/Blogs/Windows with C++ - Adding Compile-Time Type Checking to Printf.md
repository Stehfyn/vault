# Windows with C++ - Adding Compile-Time Type Checking to Printf

MSDN Magazine article on compile-time type checking for printf-style formatting in C++. Uses variadic templates to replace format-specifier placeholders with type-deduced arguments, eliminating mismatched-format bugs at compile time rather than at runtime.

Key technique: variadic templates + `static_assert` or `__attribute__((format))`.

```cpp
template <typename... Args>
void TypedPrintf(const wchar_t* fmt, Args... args)
{
    // args are type-checked at compile time via the template pack
    wprintf(fmt, args...);
}
// Usage:
TypedPrintf(L"Value: %d\n", 42);
// TypedPrintf(L"Value: %d\n", "wrong"); // compile error
```

## References

- https://learn.microsoft.com/en-us/archive/msdn-magazine/2015/may/windows-with-c-adding-compile-time-type-checking-to-printf
