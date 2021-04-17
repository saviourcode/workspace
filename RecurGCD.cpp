#include <iostream>
using namespace std;

int GCD(int, int);

int main()
{
    cout << GCD(2,5) << endl;
}

int GCD(int x, int y)
{
    cout << "x: " << x;
    cout << " y: " << y << endl;
    if (x == 0)
        return y;
    else
        return GCD(y % x,x);
}