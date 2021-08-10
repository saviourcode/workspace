#include <iostream>
using namespace std;

bool isPrime(int,int);

int main()
{
    cout << boolalpha << isPrime(9,2) << endl;

    return 0;
}

bool isPrime(int n, int d)
{
    if(n>d*d)
    {
        if(n%d==0)
            return false;
        else
            return isPrime(n,++d);
    }
    return true;
}