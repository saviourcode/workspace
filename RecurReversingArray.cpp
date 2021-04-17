#include <iostream>
using namespace std;

void reverseArray(int *, size_t, size_t);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

void reverseArray(int *a, size_t n, size_t len)
{
    if (n == len / 2)
        return;
    else
    {
        int temp = a[len - n];
        a[len - n] = a[n - 1];
        a[n - 1] = temp;
        reverseArray(a, n - 1, len);
    }
}