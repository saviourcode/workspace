#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("some string"); // Direct Initialization

    // print the characters in s one character at a line
    for(auto c : s)
        cout << c << endl;

    return 0; // Success
}