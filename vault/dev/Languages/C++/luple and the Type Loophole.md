<!-- generated-from-dump2 -->
# luple and the Type Loophole

Bag of compile-time C++14/17 tricks by Alexandr Poltavsky, of which the famous one is the **type loophole**: a way to recover the field types of an aggregate struct purely from name lookup, by exploiting the rule that a friend function declared inside a class template specialization can be redefined later — letting you "report" each member's type back to a global, queryable list at template instantiation time. The repo also houses `luple` (a tuple alternative with O(1) compile-time `get`), `nuple` (a `luple` with named members via NTTP strings), a compile-time string-interning helper, and a struct reader built on the loophole. Foundational reading for anyone interested in pre-reflection C++ aggregate inspection — Boost.PFR and Cista use closely related ideas.

```cpp
// Conceptual sketch of the type loophole (Poltavsky's own example is canonical):
//   1. Declare a friend tag<N, T> as an undefined function inside a class
//      template ubiq<N>, where the conversion operator records T into a list
//      via friend injection.
//   2. Initialize a target struct with N copies of ubiq<>; each conversion
//      defines tag<N, FieldT> for the matching field type.
//   3. Query tag<N, ?> via overload resolution to read FieldT back out.
//
// Use sites:
//   loophole_ns::as_type_list_t<MyStruct>  // -> type_list<int,float,...>
//
// luple usage (tuple replacement):
luple<int, std::string> l{42, "hello"};
get<0>(l) = 7;
```

## References
- <https://github.com/alexpolt/luple>
