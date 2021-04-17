#include <iostream>
using namespace std;

int power(int, int);
int main()
{
    cout << power(4, 4);
    return 0;
}

int power(int a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}