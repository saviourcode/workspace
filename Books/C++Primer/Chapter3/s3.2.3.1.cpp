#include <iostream>
#include <string>
#include <cctype> // for ispunct()
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("Hello World!!!"); // Direct Initialization
    // punct_cnt has the type that s.size returns
    decltype(s.size()) punct_cnt = 0;
    // print the characters in s one character at a line
    for(auto c : s)
        if(ispunct(c)) // check if a punctuation
            ++punct_cnt;
    cout << punct_cnt
         << " punctuation characters in " << s << endl;

    return 0; // Success
}