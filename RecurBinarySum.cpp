#include <iostream>
#include <cmath>
using namespace std;

int binarySum(int *, size_t, size_t);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySum(arr, 0, n) << endl;

    return 0;
}

int binarySum(int *a, size_t i, size_t n)
{
    if (n == 1)
        return a[i];
    else
        return binarySum(a, i, ceil(n / 2.0)) + binarySum(a, i + ceil(n / 2.0), floor(n / 2.0));
}