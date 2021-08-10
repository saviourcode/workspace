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

    //Summation
    int SumRec(Node *&);

    //Greatest Value
    int GreaRec(Node *&);

    //Middle Node
    Node* MidlRec(Node *&, Node *&);

    //Messed
    bool MessRec(Node *&, Node *&);
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

int Node::SumRec(Node *&temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    return temp->val + SumRec(temp->next);
}

int Node::GreaRec(Node *&temp)
{
    if (temp == NULL)
    {
        return -1;
    }
    else if (temp->next == NULL)
    {
        return temp->val;
    }
    int larg = GreaRec(temp->next);
    if (temp->val > larg)
        return temp->val;
    else
        return larg;
    return -1;
}

Node* Node::MidlRec(Node *&temp, Node *&tempf)
{
    if(temp == NULL)
    {
        return NULL;
    }
    else if(tempf->next == NULL)
    {
        return temp;
    }
    return MidlRec(temp->next, tempf->next->next);
}

bool Node::MessRec(Node *&temp, Node *&tempf)
{
    if(temp == NULL)
        return 1;
    else if(temp == tempf)
        return 1;
    else if(tempf == NULL || tempf->next == NULL)
        return 0;
    return MessRec(temp->next,tempf->next->next);
}

int main()
{
    Node *head = NULL;
    head->InstRec(head, 4);
    head->InstRec(head, 42);
    head->InstRec(head, 4);
    head->InstRec(head, 49);
    head->InstRec(head, 4);
    head->TravRec(head);
    cout << head->CoutRec(head, 4) << endl;
    cout << head->SumRec(head) << endl;
    cout << head->GreaRec(head) << endl;
    Node *ans = head->MidlRec(head,head);
    cout << ans->val << endl;
    cout << head->MessRec(head,head->next) << endl;
    return 0;
}