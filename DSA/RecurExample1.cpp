#include <iostream>
using namespace std;

void myFunction(int);

int main()
{
    myFunction(-8);
    return 0;
}

void myFunction(int counter)
{
    cout << "hello " << counter << endl;

    if (counter <= 0)
    {
        myFunction(++counter);
        cout << counter << endl;
    }
    return;
}