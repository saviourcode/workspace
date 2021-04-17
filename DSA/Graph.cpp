#include <iostream>
using namespace std;

#define NUMNODES 10

class Queue
{
public:
    Queue(size_t size) : f(0), r(0), n(0), cap(size), queue(new int[cap]){};
    void enqueue(int);
    int dequeue();
    bool empty();

private:
    int f, r, n;
    size_t cap;
    int *queue;
};

void Queue::enqueue(int val)
{
    if (n == cap)
    {
        //Queue FULL
        return;
    }
    queue[r] = val;
    r = (r + 1) % cap;
    n++;
}

int Queue::dequeue()
{
    if (n == 0)
    {
        //Queue Emtpy
        return -1;
    }
    int temp = queue[f];
    f = (f + 1) % cap;
    n--;
    return temp;
}

bool Queue::empty()
{
    if (n)
        return false;
    else
        return true;
}

class Graph
{
public:
    Graph(size_t n, int *arr) : numNodes(n), adjMatrix(arr), visited(new int[n]{0}), Q(new Queue(n)){};
    void Display();
    void DFS();
    void BFS();

private:
    size_t numNodes;
    int *adjMatrix;
    int *visited;
    Queue *Q;

    int getAdjMat(int, int);
    void DFStree(int);
    void BFStree(int);
};

int Graph::getAdjMat(int i, int j)
{
    return *((adjMatrix + i * numNodes) + j);
}

void Graph::Display()
{
    cout << "Node \t"
         << "Edge" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < numNodes; j++)
        {
            if (getAdjMat(i, j))
            {
                cout << i << "-->" << j << ", ";
            }
        }
        cout << "\b\b " << endl;
    }
}

void Graph::DFStree(int v)
{
    visited[v] = 1;
    cout << v << " ";
    for (int w = 0; w < numNodes; w++)
        if (getAdjMat(v, w))
            if (!visited[w])
                DFStree(w);
}

void Graph::BFStree(int r)
{
    visited[r] = 1;
    Q->enqueue(r);
    while (!Q->empty())
    {
        int v = Q->dequeue();
        cout << v << " ";
        for (int w = 0; w < numNodes; w++)
        {
            if (getAdjMat(v, w))
            {
                if (!visited[w])
                {
                    visited[w] = 1;
                    Q->enqueue(w);
                }
            }
        }
    }
}

void Graph::DFS()
{
    delete[] visited;
    visited = new int[numNodes]{0};
    for (int i = 0; i < numNodes; i++)
        if (!visited[i])
        {
            cout << endl;
            DFStree(i);
        }
}

void Graph::BFS()
{
    delete[] visited;
    visited = new int[numNodes]{0};
    for (int i = 0; i < numNodes; i++)
        if (!visited[i])
        {
            cout << endl;
            BFStree(i);
        }
}

int main()
{
    int arr[NUMNODES][NUMNODES] = {
        {0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    Graph G(NUMNODES, (int *)arr);
    G.Display();
    cout << "DFS Traversal:";
    G.DFS();
    cout << "\nBFS Traversal:";
    G.BFS();

    return 0;
}