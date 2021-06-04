## Bitwise Operator
> Prefer to use `unsigned` types because generally there is no guarantee on how the sign bit is handled.

1. The left-shift operator ( << operator) insers 0-valued bits on the right.
2. The behaviour of the right-shift operator ( >> operator) depends on the type of the left-hand operand:
    1. If that operand is `unsigned` then the operator inserts 0-valued bits on the left
    2. If it is a signed type, the result is implementation defined-either copies of the sign bit or 0-valued bits are inserted on the left.

## Explicit Conversions
1. We use a `cast` to request an explicit conversion.
### Named Casts
1. A named cast has the following form:
`cast-name<type> (expression);`
where `type` is the target type of the conversion, and expression is the value to be cast. If `type` is a reference, then the result is an lvalue.
2. The cast-name may be one of `static_cast`, `dynamic_cast`, `const_char` and `reinterpret_cast`.
3. There's a `dynamic_cast` also, which supports the run-time type identification.
4. The cast-name determines what kind of conversion is performed.