//There are two types of getline methods, one in iostream(uses char ptr) and another in string(uses string object)
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char *, size_t, size_t);

int main()
{
    char str[20];
    cout << "Enter a String: ";
    cin.getline(str, 20, '\n');
    cout << "The entered string " << ((isPalindrome(str, 0, strlen(str)-1)) ? "is" : "is not") << " a Palindrome string." << endl;
    return 0;
}

bool isPalindrome(char* s, size_t i,size_t j)
{
    if(i>=j)
        return true;
    else if(s[i]!=s[j])
        return false;
    return isPalindrome(s,++i,--j);
}