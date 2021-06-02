#include <iostream>
#include <string>
#include <cctype> // for toupper() function
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("Hello World!!!"); // Direct Initialization
    
    for(auto &c : s) // using reference for the string
        c = toupper(c);

    cout << s << endl;

    return 0; // Success
}