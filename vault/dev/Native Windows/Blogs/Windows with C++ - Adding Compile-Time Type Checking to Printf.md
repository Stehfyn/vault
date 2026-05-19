# Windows with C++ - Adding Compile-Time Type Checking to Printf

Kenny Kerr's MSDN Magazine article is a period piece from the point where variadic templates made C++ formatting wrappers practical. The useful idea is not to keep `printf`; it is to move format/argument mismatch detection from runtime undefined behavior into compile-time type reasoning.

Read it alongside safer string/formatting utilities and Windows logging code. Native Windows projects still contain wide/narrow format mismatches, `OutputDebugString` wrappers, and trace macros where this lesson applies even if the modern answer is `std::format`, `fmt`, or WIL logging helpers.

## References
- <https://learn.microsoft.com/en-us/archive/msdn-magazine/2015/may/windows-with-c-adding-compile-time-type-checking-to-printf>
