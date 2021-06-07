#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1,s2; // default initialized to empty string
    cin >> s1; // input s1
    cin >> s2; // input s2
    if(s1==s2)
        cout << "Same" << endl;
    else
    {
        if(s1>s2)
            cout << "First is bigger" << endl;
        else
            cout << "Second is bigger" << endl;
    }
}