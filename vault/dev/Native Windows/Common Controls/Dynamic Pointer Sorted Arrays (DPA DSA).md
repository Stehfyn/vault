# Dynamic Pointer Sorted Arrays (DPA DSA)

`dpa_dsa.h` exposes comctl32's old internal collection helpers: DPA stores pointers, DSA stores fixed-size structures, and the sorted variants support callback-based ordering/search. They are exported and historically used by shell/common-control code, but they are not a modern container abstraction. Ownership is manual, callbacks are C-style, and error handling is from the Win9x/NT4 era.

The value today is mainly when reading or interoperating with old common-control style code. If new C++ is allowed, use standard containers. If you are deliberately staying in C and already depend on comctl32, DPA/DSA can be a compact dependency-free dynamic array, but document ownership rules at every insertion/removal site.

## References
- `dpa_dsa.h` - Windows SDK header for `DPA_*` and `DSA_*` helpers.

## Connections
- `Custom Controls.md` is where these helpers often appear as private item storage.
