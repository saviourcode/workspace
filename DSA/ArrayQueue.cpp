#include <iostream>
using namespace std;

struct ArrayQueue
{
    int *queue;
    int f;
    int r;
    int n;
    int cap;

    //Constructor
    ArrayQueue(int c) : queue(new int[c]), f(0), r(0), n(0), cap(c){};

    //Enqueue
    void Enqueue(int val);

    //Dequeue
    int Dequeue();

    //Aux
    int Size();
    int Front();
    bool Empty();
};

int ArrayQueue::Size()
{
    return n;
}

bool ArrayQueue::Empty()
{
    if (n == 0)
        return true;
    else
        return false;
}

int ArrayQueue::Front()
{
    try
    {
        if (Empty())
            throw "Queue Empty";
        else
        {
            return queue[f];
        }
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

void ArrayQueue::Enqueue(int val)
{
    try
    {
        if (Size() == cap)
            throw "Queue Full";
        else
        {
            queue[r] = val;
            r = (r + 1) % cap;
            n++;
        }
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

int ArrayQueue::Dequeue()
{
    try
    {
        if (Empty())
            throw "Queue Empty";
        else
        {
            int temp = queue[f];
            f = (f + 1) % cap;
            n--;
            return temp;
        }
    }
    catch (const char *c)
    {
        cerr << c;
    }
}

int main()
{
    ArrayQueue Q(4);

    for (int i = 0; i <=4; i++)
    {
        cout << "Queue Size: " << Q.Size() << endl;
        cout << "Queue Empty: " << boolalpha << Q.Empty() << endl;
        cout << "Queue Front: " << Q.Front() << endl;

        Q.Enqueue(10*i);
    }
    cout << endl << "\nDQ\n" << endl;
    for (int i = 0; i <=4; i++)
    {
        cout << "Queue Size: " << Q.Size() << endl;
        cout << "Queue Empty: " << boolalpha << Q.Empty() << endl;
        cout << "Queue Front: " << Q.Front() << endl;

        Q.Dequeue();
    }
    

    return 0;
}