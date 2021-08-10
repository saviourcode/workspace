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
1. `vector` is a collection of objects, all of which have the same type.
2. It is also referred to as a container because it "contains" other objects.
3. It is defined in the `vector` standard library of C++
4. `vector` is a class template. C++ has both class and function templates.
5. The process that the compiler uses to create classes or function from templates is called **instantiation**.
6. We specify the type of the object to the `vector` to create our template.
Eg.
```cpp
vector<int> ivec; // ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file; // vector whose elements are vectors
```
7. Since reference are not objects, so we can't have vector of references.
## Defining and initializing a `vector`
1. Various methods to intialize a `vector` are:
```cpp
vectior<T> v1; // vector holds object of type T. Default initialization, empty
vector<T> v2(v1); // v2 has a copy of v1, direct initialization form
vector<T> v2 = v1; // Equivalent to above, copy initialization form
vector<T> v3(n, val); // v3 has n elements with value val
vector<T> v4(n); // v4 has n copies of value-initialized object.
vector<T> v5{a,b,c,...}; //Direct form and elements are initialized by corresponding initializers
vector<T> v5 = {a,b,c,...}; // same as above but now copy initialization
### List initialization 
```cpp
vector<string> v1{"a","b","c",...}; // List initialization
vector<string> v2("a","b","c",...); // error
```
### Direct and Copy form
Use direct form only when passing the count of the `vector`
```cpp
vector<int> vi(10); // ok, 10 elements
vector<int> vi = 10; //Err
```
### List initializer or Element Count?
1. Whenever there is a confusion between List initialization and element count follow the below steps:   
    1. For data type apart from `string`, if we use parentheses, then we are asking for the count and the value to initialized as
    ```cpp
    vector<int> v1(10); // 10 elements, default initialized
    vector<int> v1(10,1); // 10 elements with value 1
    ```
    And if we use curly braces then we are providing specific values to the vector as
    ```cpp
    vector<int> v2{10}; // 1 element with value 10
    vector<int> v2{10,1} // two element, one is 10 and other is 1
    ```
    2. For `string` data type however, there is no ambiguity between the parentheses and the curly brace as
    ```cpp
    vector<string> v5{"hi"}; // list initialization, one element
    vector<string> v6("hi"); // Err, can't construct a vector
    vector<string> v7{10}; // ten elements, default initialized
    vector<string> v8{10,"hi"}; // ten elements with value hi
    ```
## Adding Elements to a `vector`
1. To add an element to the `vector` use, `push_back` method at runtime.
```cpp
vector<int> v1; //Default initialized, empty

for(int i = 0; i != 100; ++i)
    v1.push_back(i); // append to the back of v1
```
2. `vector` generally follow the grow concept, because they can be grown easily. So, don't define `vector` of a particular size, just add elements to it by `push_back` method.
### Programming implications of adding elements to a `vector`
1. The loops must be correctly written even when the size of the `vector` changes.
2. The body of `range-for` must not change the size of the sequence over which it is iterating.
## Other `vector` Operations
1. There are various operations that can be performed on `vector`s such as:
```cpp
v.empty(); // Returns if v is empty, otherwise returns false
v.size(); // Returns the number of elements in v
v.push_back(t); // Adds an element with value t to the end of v
v[n]; // Returns a reference to the element at position n in v
v1 = v2; // Create a copy of v2 in v1
v1 = {a,b,c,...}; // List initialization
v1 == v2; // Check if both the vectors are same or not
v1 != v2; // Same as above
<,<=,>,>=; // Have their normal meaning using dictionary ordering
```
2. To use `size_type`, we must name the type in which it is defined. A `vector` type always includes its element type.
```cpp
vector<int>::size_type // ok
vector::size_type // error
```
3. The subscript operator on `vector` (and `string`) fetches an existing element; it does not add an element.
4. A good way to ensure that subscripts are in range is to avoid subscripting altogether by using a `range for` whenever possible.

## Iterators
1. Like pointers, iterators give us indirect access to an object.
2. In the case of an iterator, that object is an element in a container or a character in a `string`.
3. A valid iterator either denotes a n element or denotes a position one past the last element in a container. All other iterator values are invalid.

### Using Iterators
1. The `begin` memeber returns an iterator that denotes the first element (or first character).
2. The iterator returned by `end` is an iterator positioned "one past the end" of the associated container.
3. The iterator returned by the end is often referred to as the **off-the-end iterator**.
4. If the container is empty, beign returns the same iterator as the one returned by end.
5. And we never really care about the precise type that an iterator has. So, we simply define them as `auto`.
`auto b = v.begin(), e = v.end();`
### Iterator Operations
1. Various Operations on iterator are as follows:
```cpp
*iter // Returns a reference to the element denoted by the iterator iter
iter->mem // It is used for class-types. Like string have empty() Dereferences iter and fetches the member named mem from the underlying element. Equivalent to (*iter).mem
++iter // Increments iter to refer to the next element in the container
--iter // Decrements iter to refer to the previous element in the container
iter1 == iter2 // Compares if they are equal
iter1 != iter2 // Check if they are unequal
```
2. Dereferencing an invalid iterator is an Undefined Behaviour
### Moving Iterators from one element to another
1. By incrementing a iterator we advance the iterator by one position.
2. **Important Note**: The iterator returned from `end` does not denote an element, it may not be incremented or dereferenced.

> C++ Programmers tend to use `!=` rather than `<` because of the habit of using iterators. As many libraries don't even provide subscript operator.
### Iterator Types
1. The Library type that have iterators define types named `iterator` and `const_iterator` that represent actual iterator types
```cpp
vector<int>::iterator it; // it can read and write the vector elements
string::iterator it2; // it2 can read and write in a string
vector<int>::const_iterator it3; // it3 can read but not write elements
string::const_iterator it4; // it4 can read but not write elements
```
2. `const_iterator` behaves exactly like a pointer to `const`.
3. If a `vector` or `string` is `const`, we may use only its `const_iterator` type. And with non`const` `vector` or `string` we can use either `iterator` or `const_iterator`.
### The `begin` and `end` Operations
1. If the object is `const`, then `begin` and `end` return a `const_iterator`; if the object is not `const`, they return `iterator`
```cpp
vector<int> v; // Default initialization form
const vector<int> cv;
auto it1 = v.begin(); // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
```
So, the new standard introduced two new functions named `cbegin()` and `cend()`
`auto it3 = v.cbegin();` it3 has type vector<int>::const_iterator
### Deferencing a Member type from the iterator
1. 
```cpp
vector<string> s;
auto it = s.begin();

(*it).empty(); // To check if the first element is empty or not
it->empty(); // Same as above
```
What the parentheses does is that they first dereference the iterator and then it access the member function.
### Some `vector` Operations invalidate iterator
Any operation of adding new element to the `vector` like `push_back` will invalidate the iterators into that `vector`

## Iterator Arthimetic
> Whatever arithmetic operation you do, just remember that the iterator needs to denote the elements in, or one past the end of, the same container.
1. Iterators for `string` and `vector` support additional operations that can move and iterator multiple elements at a time. They also support all the relational operators. And these are referred as **iterator arithmetic**
2. iter + n or iter - n or iter += n or iter -= n, moves the iterator by that such integral value.
3. iter1 - iter2, yields the signed difference between the two.
4. `>,>=,<,<=` relational operations are also permitted.
### Arithmetic Operations on Iterators
1. We can compute an iterator to the element nearest the middle of a vector as:
`auto mid = vi.begin() + vi.size() / 2;`
2. When we subtract two iterator we get a signed integral type named as `difference_type`. It is defined by the library container.
### Using Iterator Arithmetic
```cpp
auto sought = "some string" // string to find
const vector<string> s; // Default initialization form
// Later I add some elements at runtime using push_back
// And then I even somehow sort then
auto start = s.begin(); // begin iterator
auto end = s.end(); // end iterator
auto mid = start + (end - start)/2; // Midpoint

while(mid != end && *mid != sought)
{
    if(sought < mid) // Check only the first half
        end = mid
    else // or else check the other half
        start = mid + 1;
    
    mid = start + (end - start)/2 // new midpoint
}

// read out the mid variable the answer is stored inside it
```
## Array
### Defining and Initializing Built-in Arrays
1. The size that is passed to the array for dimensions has to be a `constexpr` (Constant Expression) such as:
```cpp
constexpr unsigned sz = 42; // Constant Expression

int arr[sz]; // array of 42 elements
string strs[get_size()]; // Ok if get_size() returns a constexpr
```
> As with variables of built-in type, a default-initialized array of built-in type that is defined inside a function will have always have undefined values.
2. There can't be array of reference because array stores objects.
3. When we define an array we can't use `auto` to deduce the type of the array from the list initialization
4. When we initialize an array with a string the NULL character is also added to the array as:
```cpp
char c = "C++"; // NULL terminatior added automatically
```
5. Arrays don't support copy or assignment operators
### Understand Complicated Array Declarations
**Important Topic**
1. Always read the arrays starting from the name of the declaration to inside-out.
Eg.
```cpp
int *ptrs[10]; // ptrs is an array of 10 pointers to int
int &refs[10] = /* ? */; // No valid
int (*Parray)[10] = &arr; // Parray is pointer to an array of 10 ints
int (&Rarray)[10] = arr; // Rarray is a reference to array of 10 ints
int *(&Rarray)[10] = ptrs; // Rarray is a reference to array of 10 pointers to int
```
### Accessing the element in the array
1. Array uses the index which is of type `size_t` and defined in `cstddef` header
2. We can use `range-for` when we have to traverse the entire array
```cpp
unsigned scores[11] = {};
// And then fill the array by taking input from the user
for(auto i:scores)
    cout << i << " ";

cout << endl;
```
### Pointers and Array
1. Operation on arrays are actually really like operation on pointers
```cpp
int ia[] = {0,1,2,3,4,5}; // ia is an array of 10 ints
auto ia2(ia); // ia2 is an int* that points to the first element in ia
```
2. However when we use decltype the conversion happens in a bit odd way
```cpp
decltype(ia) ia3 = {0,1,2,3,4,5};
```
here ia3 is actually an array of 6 ints.
### Library function `begin` and `end`
1. The standard included two new functions `begin` and `end`
2. Since the array is not a class type, so these functions can't be a member of the array.
3. The array needs to be passed to the function `begin` and `end`.
```cpp
int ia = {0,1,2,3,4,5,6};
int *beg = begin(ia); // Pointer to the first element in ia
int *last = end(ia); // Pointer to one past the last element in ia
```
These functions are defined in `iterator` header.
### Pointer Arthimetic
1. The Subtraction of two pointers yields a library type named as `ptrdiff_t`. And like `size_t`, the `ptrdiff_t` type is machine-specific type and is defined in the `cstddef` header.
2. `ptrdiff_t` is a signed integral type.
### Subscripts and Pointers
1. The built-in subscript can be a negative index.
```cpp
int *p = &ia[2]; // p points to the element indexed by 2
int j = p[1];   // p[1] is equivalent to *(p+1)
                // p[1] is the same element as ia[3]
int k = p[-2]; // p[-2] is the same element as ia[0]
```
> Unlike subscripts for `vector` and `string`, the index of built-in subscript operator is not an `unsigned` type.
### C-Style Character String
> Please avoid using them in the code, they can cause vulnerbility issue and introduce bugs in the code.
### Interfacing to Older code
1. To convert a string to C-Style string use:
```cpp
string s("some string"); // Direct Form of initialization

char *str = s; // Err
const char *str = s.c_str(); //Ok
```
`c_str()` method returns a const char pointer
2. To convert a array to a vector
```cpp
int arr[] = {0,1,2,3,4,5};

vector<int> ivec(begin(arr), end(arr)); // Complete array
vector<int> subvec(arr + 1, arr + 4); // Only a sub-array
```

All other combinations are not possible, like initializing a array from a vector.

> Prefer to use Library types instead of arrays and pointer because they are error-prone

## Multidimensional arrays
1. There are no multidimensional array. 
2. There is actually only array of arrays.
Eg.
```cpp
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
int arr[10][20][30] = {0}; // array of size 10; each element is a 20-element array whose elements are arrays of 30 ints
```
### Initializing the elements of a Multidimensional Array
1. We can initialize the elements of a multidimensional array by providing a bracketed list of initializers.
2. The bracketed values for each row is as follows:
```cpp
int ia[3][4] = { // three elements, each element is an array of size 4
    {0, 1, 2, 3}, // index 0
    {4, 5, 6, 7}, // index 1
    {8, 9, 10 ,11} // index 2
};
```
We can omit the brackets for this particular case, but the readibility decreases greatly.

3. But for a incomplete initializer the brackets makes a difference as,
```cpp
int ia[3][4] = {{0}, {4}, {8}}; // explicitly initialize only the element 0 in each row
int ix[3][4] = {0, 3, 6, 9}; // explicitly initializes only the first row and not the other ones.
```
### Subscripting a Multidimensional Array
1. We can use nested for loops
### Using a `range for` with multidimensional arrays
1. We can use `range-for` in our example as:
```cpp
for(auto &row : ia) // for every element in the outer array
    for(auto &col : row) // for every element in the inner array
        cout << col << endl;
```
And if we want to write the above code without using the reference then we must make the outer loop a reference.
```cpp
for(const auto &row : ia)
    for(auto col : row)
        /* do something */
```
We have done so to avoid normal array to pointer conversion.
If it had been written like this:
```cpp
for(auto row : ia)
    for(auto col : row)
```
Then the compiler would have initialized `row` as `int *`, due to which the inner loop would have become illegal. As, how come `col` be made mapped to the original element in the array. There is no way of doing that.

> To use a multidimensional array in a `range-for` the loop control variable except for the inner most array must be references.

### Pointers and Multidimensional Arrays
> Whenever we define a pointer to a multidimensional array, we are just defining it to array of arrays.

```cpp
int ia[3][4]; // ia is an array of size 3, and each element is array of size 4 of ints
int (*p)[4] = ia; // p points to an array of four ints
p = &ia[2]; // p now points to the last element in ia

int *q = *p; // first element in the last row of ia
// Ofcourse we can use begin() and end() as
p = begin(ia); // First row
q = begin(*p); // First element of the First row

// Also we can even use typedef and using as
using int_four_arr = int[4]; // New style
typedef int int_four_arr[4]; // Equivalent typedef
// And now
int_four_arr *p = ia; // Now remember to first read from right to left. P is a pointer to int_four_arr -> pointer to array of four ints
```
