#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const string hexdigits = "0123456789ABCDEF"; // Copy initialization with string literal
    cout << "Enter space-seperated digits between 0 to 15" << endl;

    string result; // default initialization, empty

    decltype(hexdigits.size()) n;

    while(cin >> n)
        if(n < hexdigits.size())
            result += hexdigits[n];

    cout << "result: " << result << endl;

    return 0; // Success
}