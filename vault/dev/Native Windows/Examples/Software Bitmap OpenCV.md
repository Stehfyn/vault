# Software Bitmap OpenCV

This example sits at the boundary between Windows bitmap memory and OpenCV image matrices. The useful part is layout discipline: pixel format, channel order, stride, top-down versus bottom-up orientation, and ownership must be made explicit when wrapping a DIB or software buffer as `cv::Mat`.

Connect this to `DIB Stride Math (Old New Thing)`, GDI bitmap notes, and capture/overlay samples. Most bugs in this space are not computer-vision bugs; they are row-pitch and lifetime bugs.

## References
- Local snippet source retained in previous revision of this note.
