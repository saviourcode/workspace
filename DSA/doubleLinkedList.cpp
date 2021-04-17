#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;

    //Constructor
    Node(int val, Node *next = NULL, Node *prev = NULL) : val(val), next(next), prev(prev){};

    //Insertion
    void InstRec(Node *&, Node *&, int);
    void InstBefRec(Node *&, Node *&, int);
    void InstAftRec(Node *&, Node *&, Node *&, int);

    //Deletion
    void DeltRec(Node *&, Node *&, Node *&);

    //Traversal
    void ForwTravRec(Node *&);
    void RevsTravRec(Node *&);
};

void Node::InstRec(Node *&temp, Node *&tail, int val)
{
    if (temp == NULL)
    {
        Node *nd = new Node(val);
        temp = nd;
        tail = temp;
        return;
    }
    else if (temp->next == NULL)
    {
        Node *nd = new Node(val);
        temp->next = nd;
        nd->prev = temp;
        tail = nd;
        return;
    }
    InstRec(temp->next, tail, val);
}

void Node::ForwTravRec(Node *&temp)
{
    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    cout << temp->val << " ";
    ForwTravRec(temp->next);
}

void Node::RevsTravRec(Node *&temp)
{
    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    cout << temp->val << " ";
    RevsTravRec(temp->prev);
}

void Node::InstBefRec(Node *&temp, Node *&targetNode, int val)
{
    if (temp == targetNode)
    {
        Node *nd = new Node(val);
        nd->next = temp;
        temp->prev = nd;
        temp = nd;
        return;
    }
    else if (temp->next == targetNode)
    {
        Node *nd = new Node(val);
        nd->next = temp->next;
        temp->next = nd;
        nd->prev = temp;
        nd->next->prev = nd;
        return;
    }
    InstBefRec(temp->next, targetNode, val);
}

void Node::InstAftRec(Node *&temp, Node *&tail, Node *&targetNode, int val)
{
    if (tail == targetNode)
    {
        Node *nd = new Node(val);
        nd->prev = tail;
        tail->next = nd;
        tail = nd;
        return;
    }
    else if (temp == targetNode)
    {
        Node *nd = new Node(val);
        nd->next = temp->next;
        temp->next = nd;
        nd->prev = temp;
        return;
    }
    InstAftRec(temp->next, tail, targetNode, val);
}

void Node::DeltRec(Node *&temp, Node *&tail, Node *&targetNode)
{
    if(temp == NULL)
        return;
    else if(temp == targetNode)
    {
        temp->next->prev = NULL;
        temp = temp->next;
        return;
    }
    else if(tail == targetNode)
    {
        tail->prev->next = tail->next;
        tail = tail->prev;
        return;
    }
    else if(temp->next == targetNode)
    {
        temp->next = temp->next->next;
        temp->next->prev = temp;
        return;
    }
    DeltRec(temp->next, tail, targetNode);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    head->InstRec(head, tail, 10);
    head->InstRec(head, tail, 20);
    head->InstRec(head, tail, 5);
    cout << "Original DLL: " << endl;
    head->ForwTravRec(head);
    head->RevsTravRec(tail);
    cout << "Insert 700 before 5: " << endl;
    head->InstBefRec(head, head->next->next, 700);
    head->ForwTravRec(head);
    head->RevsTravRec(tail);
    cout << "Insert 1000 after tail: " << endl;
    head->InstAftRec(head, tail, tail, 1000);
    head->ForwTravRec(head);
    head->RevsTravRec(tail);
    cout << "Deleting 5: " << endl;
    head->DeltRec(head,tail,tail);
    head->ForwTravRec(head);
    head->RevsTravRec(tail);

    return 0;
}
