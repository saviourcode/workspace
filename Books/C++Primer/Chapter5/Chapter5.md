# Range for
1. In a range-for the value of `end()` is cached. If we add elements to (Or remove them from) the sequence, the value of `end` might be invalidated.
2. Example of a `range-for` using `for` loop:
```cpp
for(auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
    auto &r = *beg; // r must be a reference so we can change the element
    r *= 2; // double the value of each element in v
}
```
# `do while`
1. The variables can't be declared in the condition. Because if we did that then the variable would be used even before the definition!

# `goto`
1. It is an error to transfer control from a point where an initialized variable is out of scope to a point where that variable is in scope.
```cpp
    goto end;
    int ix = 10; // error
end:
    // error
    ix = 42;
```
# Try and Catch Exception handling
## `throw` Expression
1. The type `runtime_error` is one of the standard library exception types and is defined in the `stdexcept` header.
2. We must initialize a `runtime_error` by giving it a `string` or a C-style character string.
```cpp
while(cin >> item1 >> item2){
    try {
        // execute some code
        // if any error then throw a runtime_error exception
    } catch (runtime_error err) {
        cout << err.what() << "Try again" << endl;
    }
}
```
3. The `what` member function of the `runtime_error` class takes no arguments and return a C-style character string (a `const char*`). This `string` was passed during initialization phase.
## Functions are exited during the search for a handler
1. In many systems, there are multiple `try` blocks. For example, a `try` block might call a function that contains a `try`, which calls another function with its own `try`, and so on.
2. The search for a handler reverses the call chain. When an exception is thrown, the function that threw the exception is searched first. If no matching `catch` is found, that function terminates.
The function that called the one that threw is searched next. If no handler is found, that function also exits. That functions's caller is searched next, and so on back up the exection path until a `catch` of an appropriate type is found.
3. If no appropriate `catch` is found, execution is transferred to a library function named `terminate`. The behaviour of that function is system dependent but is guaranteed to stop further execution of the program.
> Programs that properly "clean up" during execption handling are said to be exception safe.
## Standard Excptions
```cpp
exception // The msot general kind of problem
runtime_error // Problem that can be detected only at run time
range_error // Run-time error: result generated outside the range of values that are meaningful.
overflow_error // Run-time error: computation that overflowed
underflow_wrror // Run-time error: computation that underflowed
logic_error // Error in the logic of the program
domain_error // Logic Error: argument for which no result exists
invalid_argument // Logic Error: Inappropriate argument
length_error // Logic Error: Attempt to create an object larger than the maximum size for that type.
out_of_range // Logic Error: Used a value outside the valid range
```
1. There are `bad_alloc` and `bad_cast` exception type as well.
2. The library exception classes have only a few operations. We can create, copy, and assign objects of any of the exception types.
3. We can only default initialize `exception`, `bad_alloc` and `bad_cast` objects. It is not possible to provide an initializer for objects of these exception types.
4. The other exception types have opposite behavior. We can initialize those objects from either a `string` or a C-style string, but we cannot default initialize them.










