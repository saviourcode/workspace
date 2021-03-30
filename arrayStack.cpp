#include <iostream>
using namespace std;

struct ArrayStack
{
    int *stack;
    int cap;
    int top;

    //Constructor
    ArrayStack(int c) : stack(new int[c]), cap(c), top(-1){};

    //Push
    void Push(int);

    //Pop
    int Pop();

    //Aux Func
    bool Empty();
    int Size();
    int Top();
};

int ArrayStack::Size()
{
    return top + 1;
}

int ArrayStack::Top()
{
    try
    {
        if (Empty())
            throw "Stack Empty";
        else
            return stack[top];
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

bool ArrayStack::Empty()
{
    if (Size())
        return false;
    else
        return true;
}

void ArrayStack::Push(int val)
{
    try
    {
        if (Size() == cap)
            throw "Stack Full";
        else
            stack[++top] = val;
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

int ArrayStack::Pop()
{
    try
    {
        if (Empty())
            throw "Stack Empty";
        else
            return stack[top--];
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

int main()
{
    ArrayStack S(2);
    cout << "Stack Empty: " << boolalpha << S.Empty() << endl;
    cout << "Stack Top: " << S.Top() << endl;
    cout << "Stack Size: " << S.Size() << endl;

    cout << "Pushing 20" << endl;
    S.Push(20);

    cout << "Stack Empty: " << boolalpha << S.Empty() << endl;
    cout << "Stack Top: " << S.Top() << endl;
    cout << "Stack Size: " << S.Size() << endl;

    cout << "Pushing 10" << endl;
    S.Push(10);

    cout << "Stack Empty: " << boolalpha << S.Empty() << endl;
    cout << "Stack Top: " << S.Top() << endl;
    cout << "Stack Size: " << S.Size() << endl;

    cout << "Pushing 30" << endl;
    S.Push(30);

    return 0;
}