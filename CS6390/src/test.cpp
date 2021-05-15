#include <iostream>
#include <functional>
using namespace std;

struct test
{
    void test1(int (&)[10][10], function<void(int &)> func);

    void test2(int &x);

    void test3(int &x);
};

void test::test1(int (&x)[10][10], function<void(int &)> func)
{
    x[0][0] = 1;

    func(x[0][1]);
    cout << x[0][0] << " " << x[0][1] << endl;
}

void test::test2(int &x)
{
    x = 1;
}

void test::test3(int &x)
{
    x = 2;
}

int main()
{
    test* t = new test;
    int a[10][10] = {{0}};

    t->test1(a, bind(&test::test3,t));

    cout << a[0][0] << " " << a[0][1] << endl;
}

