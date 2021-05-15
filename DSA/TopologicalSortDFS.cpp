#include <iostream>
using namespace std;

#define NUMNODES_1 14
#define NUMNODES_2 8

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
    Graph(size_t n, int *mat) : adjMat(mat), numNodes(n), Q(new Queue(numNodes)), visited(new bool[numNodes]{false}), done(new int[numNodes]{-1}), label(new int[numNodes]{-1}), predcount(new int[numNodes]{0}), noDepNode(new bool[numNodes]{0}){};
    void toposortDFS();
    void toposortBFS();
    void printorder_graphone();
    void printorder_graphtwo();

private:
    int numNodes = 14;
    int labelNum;
    bool getAdj(int, int);
    void findNoDepNodes();
    void findPredCount();
    void topologicalSortDFS(int);
    void topologicalSortBFS();
    bool *visited;
    int *done;
    int *label;
    int *predcount;
    bool *noDepNode;
    int *adjMat;
    Queue *Q;

    char display[14] = {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
};

void Graph::findNoDepNodes()
{
    for (int v = 0; v < numNodes; v++)
    {
        for (int w = 0; w < numNodes; w++)
        {
            if (getAdj(w, v))
            {
                noDepNode[v] = false;
                break;
            }
        }
    }
}

bool Graph::getAdj(int v, int w)
{
    return *((adjMat + v * numNodes) + w);
}

void Graph::topologicalSortDFS(int v)
{
    visited[v] = true;
    done[v] = 0;
    for (int w = 0; w < numNodes; w++)
    {
        if (getAdj(v, w))
        {
            if (!visited[w])
            {
                topologicalSortDFS(w);
            }
            else if (visited[w] && !done[w])
            {
                throw "Loop Encountered";
                return;
            }
        }
    }
    done[v] = 1;
    label[labelNum] = v;
    labelNum--;
}

void Graph::toposortDFS()
{
    for (int i = 0; i < numNodes; i++)
    {
        visited[i] = false;
        done[i] = -1;
        label[i] = -1;
        noDepNode[i] = true;
    }

    labelNum = numNodes - 1;
    findNoDepNodes();

    for (int i = 0; i < numNodes; i++)
    {
        if (noDepNode[i])
        {
            topologicalSortDFS(i);
        }
    }
}

void Graph::findPredCount()
{
    for (int v = 0; v < numNodes; v++)
    {
        for (int w = 0; w < numNodes; w++)
        {
            if (getAdj(w, v))
            {
                predcount[v]++;
            }
        }
    }
}

void Graph::topologicalSortBFS()
{
    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i] && predcount[i] == 0)
        {
            visited[i] = true;
            label[labelNum] = i;
            labelNum++;
            Q->enqueue(i);
        }
    }

    while (!Q->empty())
    {
        int v = Q->dequeue();
        for (int w = 0; w < numNodes; w++)
        {
            if (getAdj(v, w))
            {
                predcount[w]--;
            }
        }

        for (int i = 0; i < numNodes; i++)
        {
            if (!visited[i] && predcount[i] == 0)
            {
                visited[i] = true;
                label[labelNum] = i;
                labelNum++;
                Q->enqueue(i);
            }
        }
    }

    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            throw "Loop Encountered";
            break;
        }
    }
}

void Graph::toposortBFS()
{
    for (int i = 0; i < numNodes; i++)
    {
        predcount[i] = 0;
        visited[i] = false;
        label[i] = -1;
    }

    labelNum = 0;

    findPredCount();

    topologicalSortBFS();
}

void Graph::printorder_graphone()
{
    cout << "Order\tNode" << endl;
    cout << "------------" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        cout << i << "\t" << display[label[i]];
        cout << endl;
    }
}

void Graph::printorder_graphtwo()
{
    cout << "Order\tNode" << endl;
    cout << "------------" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        cout << i << "\t" << label[i] + 1;
        cout << endl;
    }
}

int main()
{
    int mat_1[NUMNODES_1][NUMNODES_1] = {
        //0  1  2  3  4  5  6  7  8  9  10 11 12 13
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // 0
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 1
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, // 2
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1}, // 3
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // 5
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // 9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 11
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 13
    };

    Graph graph_one(NUMNODES_1, (int *)mat_1);

    cout << "\nDFS Topological Sort" << endl;
    try
    {
        graph_one.toposortDFS();
        graph_one.printorder_graphone();
    }
    catch (const char *c)
    {
        cerr << c << endl;
    }

    cout << "\nBFS Topological Sort" << endl;
    try
    {
        graph_one.toposortBFS();
        graph_one.printorder_graphone();
    }
    catch (const char *c)
    {
        cerr << c << endl;
    }

    int mat_2[NUMNODES_2][NUMNODES_2] = {
        // 1  2  3  4  5  6  7  8
        {0, 1, 0, 0, 1, 1, 0, 0}, // 1
        {0, 0, 1, 0, 1, 0, 1, 0}, // 2
        {0, 0, 0, 1, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 1, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 1, 1}, // 5
        {0, 0, 0, 0, 1, 0, 0, 1}, // 6
        {0, 0, 0, 1, 0, 0, 0, 1}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0}  // 8
    };

    Graph graph_two(NUMNODES_2, (int *)mat_2);

    cout << "\nDFS Topological Sort" << endl;
    try
    {
        graph_two.toposortDFS();
        graph_two.printorder_graphtwo();
    }
    catch (const char *c)
    {
        cerr << c << endl;
    }

    cout << "\nBFS Topological Sort" << endl;
    try
    {
        graph_two.toposortBFS();
        graph_two.printorder_graphtwo();
    }
    catch (const char *c)
    {
        cerr << c << endl;
    }
}