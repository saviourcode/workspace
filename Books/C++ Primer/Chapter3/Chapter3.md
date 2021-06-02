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
1. When we use `=` we ask the compiler to **copy initialize** the object by copying the initializer on the right-hand side into the object being created.
2. And when we omit the `=`, we use **direct initialization**.
3. When we have a single initializer, we have a choice between Copy initialize or Direct Initialize.
4. But when we have more than one value in the initializer then we must use Direct Initialization. Eg. incase of s4.
5. If we still want to use copy initialization then we must do so by doing it indirectly (Indirect copy initialization).
Eg.
`string s8 = string(10, 'c'); // indirect copy initialization`
## Operations on `string`s
```cpp
os << s; // Write s onto output stream os. Returns os.
is >> s; // Reads whitespace-seperated string from is into s. Returns is.
getline(is,s); // Reads a line of input from is into s. Returns is.
s.empty(); // Return true is empty else false
s.size(); // Returns the number of characters in s
s[n]; // Returns a reference to the char at pointion n in s
s1 + s2; // Returns a string by concatenation
s1 = s2; // Replaces characters in s1 with a copy of s2
s1 == s2; // Check for equality
s1 != s2; // same as above
<,<=,>,>=; // Compare according to dictionary ordering
```
### Reading and Writing `string`
1. The `string` input operator reads and discards any leading whitespace (e.g., spaces, newlines, tabs). It just reads characters until the next whitespace character is encountered.
2. `getline()` function is used to read the entire line instead of `>>` operator.
3. Because both these methods returns the input stream, we can use them as a condition inside the while loop, which will check their state.
### `string::size_type` Type
1. The `string` class-and most other library types-defines several companion types. These companion types make it possible to use the library types in a machine-independent manner.
2. `size_type` is one of those types.
3. We can ask the compiler to a make a variable of type `size_type` by using `decltype` or `auto`
Eg.
`auto len = line.size(); // len has type string::size_type`
### Adding the `string`
1. Adding two strings is pretty strightforward just use `+` or `+=` operator
2. When adding a string literal or a character literal atleast one of the operand must be a string type.
`string s7 = ("hello" + ", ") + s2; // Err: can't add string literals`
3. For historical reasons and for compatibility with C, string literals are not standard library `string`s.
### Character Operations, Range based For-Loop
1. `range-for` is used to process every character in the string.
2. Syntax is as follows:
```cpp
for(declaration : expression)
    statement
```
where `expression` is an object of a type that represents a sequence, and `declaration` defines the variable that we'll use to access the underlying elements in the sequence.  

3. On each iteration, the variable in the declaration is initialized from the value of the next element in expression.
### Processing Only some Characters
1. The `string` class provide us with the `[]` operator, also known as subscript operator.
2. It takes the input as `string::size_type`
3. The value of subscript of a string is `>=0` or `< size()`
4. The result of using an index outside this range is undefined. So, using subscripting to an empty string is undefined.

# Library `Vector` Type
