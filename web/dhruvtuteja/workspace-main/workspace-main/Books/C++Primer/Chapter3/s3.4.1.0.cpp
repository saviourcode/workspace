#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("some string"); // Direct Initialization form

    if(s.begin() != s.end()) // make sure it is not empty
    {
        auto it = s.begin();
        *it = toupper(*it);
    }

    cout << s << endl;

    return 0;
}