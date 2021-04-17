#include <iostream>
using namespace std;

int linearSum(int *, size_t);

int main()
{
    int arr[] = {1,1,1,1,1,1,1,1,1,1};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int sum = linearSum(arr,n-1);
    cout << sum << endl;
    return 0;
}

int linearSum(int *a, size_t n)
{
    if(n==0)
        return a[0];
    else 
        return a[n] + linearSum(a,n-1);
}