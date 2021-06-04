## Bitwise Operator
> Prefer to use `unsigned` types because generally there is no guarantee on how the sign bit is handled.

1. The left-shift operator ( << operator) insers 0-valued bits on the right.
2. The behaviour of the right-shift operator ( >> operator) depends on the type of the left-hand operand:
    1. If that operand is `unsigned` then the operator inserts 0-valued bits on the left
    2. If it is a signed type, the result is implementation defined-either copies of the sign bit or 0-valued bits are inserted on the left.