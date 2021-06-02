# Motivation
1. C++ defines a rich library of abstract data types.
2. `string` supports variable-length character strings and `vector` defined variable-sze collections.
3. There are some companion types known as iterators, which are used to access the characters in a `string` or the elements in a `vector`.
4. The standard library implements those functionalities of additional types of a higher-level nature that computer hardware usually does not implement directly.
# Namespace `using` declarations
1. `::` is a scope operator, we have lhs and rhs operand to it.
2. `using` declaration lets us use a name from a namespace without using the name with a `namespace_name::` prefix. It has the form of
`using namespace::name;`
3. We can either write the namespaces together or seperate them using multiple lines.
## Header should not include `using` declarations
1. It can cause unexpected name conflicts.
# Library `string` type
