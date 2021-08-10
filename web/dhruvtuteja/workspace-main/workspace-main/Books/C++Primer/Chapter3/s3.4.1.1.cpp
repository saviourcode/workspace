#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("some string"); // Direct Initialization form

    for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // Cao the current char

    cout << s << endl;

    return 0;
}