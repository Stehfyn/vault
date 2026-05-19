# DIB Stride Math (Old New Thing)

Raymond Chen's DIB stride note is worth keeping because bitmap bugs often come from confusing visible width with row pitch. DIB scan lines are aligned, many formats are bottom-up unless declared otherwise, and the stride calculation must account for bits-per-pixel before rounding to the required boundary.

Connect this to GDI bitmap entries, screenshot/capture code, and any software-rendered image path. The practical lesson is to pass stride explicitly through your code rather than recomputing it from width in places that do not know the storage format.

Code contribution: carry `stride` beside width/height through DIB code, using aligned row pitch rather than assuming `width * bytes_per_pixel`.

## References
- <https://devblogs.microsoft.com/oldnewthing/20250522-00/?p=111211>
