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
1. It is implemented in `string` standard library
2. Apart from providing us the operations on the string, the library is also made in efficiency in mind. So, they can be used for general purposes.
## Defining and initializing `string`
1. There are multiple ways to initialize the object of `string` class.
Eg.
```cpp
string s1; // default initialization s1 is empty string
string s2 = s1; // s2 is a copy of s1
string s3 = "hiya"; // s3 is a copy of the string literal
string s4(10,'c'); // s4 is cccccccccc
```
2. Few more examples
```cpp
string s1; // Default initialization
string s2(s1); // s2 is a copy of s1
string s2 = s1; // equivalent to above
string s3("value"); // s3 is a copy of the string literal
string s3 = "value"; // equivalent to above
string s4(n, 'c'); // initialize s4 with n copies of the character 'c'
```
## Direct and Copy Forms of Initialization
1. When we use `=` we ask the compiler to copy initialize the object by copying the initializer on the right-hand side into the object being created.
2. 