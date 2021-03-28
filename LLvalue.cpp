#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    //Constructor
    Node(int val, Node *next = NULL) : val(val), next(next){};

    //Insertion
    void InstRec(Node *&, int);

    //Traversal
    void TravRec(Node *&);

    //Counter
    int CoutRec(Node *&, int);
};

void Node::InstRec(Node *&temp, int val)
{
    if (temp == NULL)
    {
        Node *nd = new Node(val);
        temp = nd;
        return;
    }
    else if (temp->next == NULL)
    {
        Node *nd = new Node(val);
        temp->next = nd;
        return;
    }
    InstRec(temp->next, val);
}

void Node::TravRec(Node *&temp)
{
    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    cout << temp->val << " ";
    TravRec(temp->next);
}

int Node::CoutRec(Node *&temp, int val)
{
    if (temp == NULL)
        return 0;
    else if (temp->val == val)
        return 1 + CoutRec(temp->next, val);
    else
        return 0 + CoutRec(temp->next, val);
}

int main()
{
    Node *head = NULL;
    head->InstRec(head, 4);
    head->InstRec(head, 42);
    head->InstRec(head, 4);
    head->TravRec(head);
    cout << head->CoutRec(head,4) << endl;
    return 0;
}