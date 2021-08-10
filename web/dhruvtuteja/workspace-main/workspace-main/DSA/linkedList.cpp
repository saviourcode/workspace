#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *next;

  //Constructor
  Node(int val, Node *next = NULL) : val(val), next(next){};

  //Insertion
  void Inst(Node *&, int);
  void InstRec(Node *&, int);
  void InsBefRec(Node *&, Node *&, int);
  void InstAftRec(Node *&, Node *&, int);

  //Deletion
  void DeltRec(Node *&, Node *&);

  //Traversal
  void Trav();
  void TravRec(Node *&);
};

void Node::Trav()
{
  //Iterator
  Node *iptr = this;
  while (iptr != NULL)
  {
    cout << iptr->val << " ";
    iptr = iptr->next;
  }
  cout << endl;
}

void Node::TravRec(Node *&tmp)
{
  //Base Case
  if (tmp == NULL)
  {
    cout << endl;
    return;
  }
  //Recursive Case
  else
  {
    cout << tmp->val << " ";
    TravRec(tmp->next);
  }
}

void Node::Inst(Node *&temp, int val)
{
  //Iterator
  Node *iptr = temp;
  //New Node is created
  Node *nd = new Node(val);
  //If head is NULL
  if (temp == NULL)
    temp = nd;
  //Normal Case
  else
  {
    while (iptr->next != NULL)
    {
      iptr = iptr->next;
    }
    iptr->next = nd;
  }
}

void Node::InstRec(Node *&temp, int val)
{
  //Base Case
  if (temp == NULL)
  {
    Node *nd = new Node(val);
    temp = nd;
    return;
  }
  //Base case
  else if (temp->next == NULL)
  {
    Node *nd = new Node(val);
    temp->next = nd;
    return;
  }
  //Recursive Case
  InstRec(temp->next, val);
}

void Node::InsBefRec(Node *&temp, Node *&targetNode, int val)
{
  if (temp == targetNode)
  {
    Node *nd = new Node(val);
    nd->next = temp;
    temp = nd;
    return;
  }
  else if (temp->next == targetNode)
  {
    Node *nd = new Node(val);
    nd->next = temp->next;
    temp->next = nd;
    return;
  }
  InsBefRec(temp->next, targetNode, val);
}

void Node::InstAftRec(Node *&temp, Node *&targetNode, int val)
{
  if (temp == targetNode)
  {
    Node *nd = new Node(val);
    nd->next = temp->next;
    temp->next = nd;
    return;
  }
  InstAftRec(temp->next, targetNode, val);
}

void Node::DeltRec(Node *&temp, Node *&targetNode)
{
  if(temp == targetNode)
  {
    temp = temp->next;
    return;
  }
  else if(temp->next == targetNode)
  {
    temp->next = targetNode->next;
    return;
  }
  DeltRec(temp->next,targetNode);
}

int main()
{
  Node *head = NULL;
  head->Inst(head, 4);
  head->Inst(head, 5);
  head->InstRec(head, 6);
  cout << "Original LinkedList: " << endl;
  head->TravRec(head);
  cout << "Adding 10 before 5: " << endl;
  head->InsBefRec(head, head->next, 10);
  head->Trav();
  cout << "Adding 100 after 5: " << endl;
  head->InstAftRec(head, head->next->next, 100);
  head->TravRec(head);
  cout << "Deleting 5: " << endl;
  head->DeltRec(head,head->next->next);
  head->TravRec(head);
}
