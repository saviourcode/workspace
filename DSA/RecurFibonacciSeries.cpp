#include <iostream>
using namespace std;

int fibonacciSeries(int);

int main()
{
    int n=5;
    for(int i=0;i<=n;i++) //iterating
        cout << fibonacciSeries(i) << " ";
}

int fibonacciSeries(int n) //finding the kth term
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}