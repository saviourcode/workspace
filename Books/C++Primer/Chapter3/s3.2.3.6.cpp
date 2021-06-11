#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const string s("some string"); // Direct initialization form

    for(const auto &c : s)
    {
        // legal
    }
    cout << s << endl;
}