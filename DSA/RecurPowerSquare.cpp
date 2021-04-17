#include <iostream>
using namespace std;

int powerSquare(int, int);

int main()
{
    cout << powerSquare(4, 4) << endl;
    return 0;
}

int powerSquare(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
    {
        int imm = powerSquare(a, (n - 1) / 2);
        return a * imm * imm;
    }
    else if (n % 2 == 0)
    {
        int imm = powerSquare(a, n / 2);
        return imm * imm;
    }
    return -1;
}