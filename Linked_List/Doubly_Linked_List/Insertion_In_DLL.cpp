#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
// All these insertion are done efore a given node
Node *insertionBeforeHead(Node *head, int value)
{
    if (head == nullptr)
    {
        Node *newHead = new Node(value);
        return newHead;
    }
    Node *newHead = new Node(value, nullptr, head);
    head->prev = newHead;
    return newHead;
}
Node *insertionBeforeTail(Node *head, int value)
{
    if (head == nullptr)
    {
        Node *newHead = new Node(value);
        return newHead;
    }
    if (head->next == nullptr)
    {
        return insertionBeforeHead(head, value);
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *previousTemp = tail->prev;
    Node *newNode = new Node(value, previousTemp, tail);
    previousTemp->next = newNode;
    tail->prev = newNode;
    return head;
}
Node* insertionBefore_Kth_Element(Node* head,int k,int value)
{
   if(k == 1)
   {
       return insertionBeforeHead(head,value);
   }
   Node* temp = head;
   int count = 0;
   while(temp != nullptr)
   {
    count++;
    if(count == k)
    {
        break;
    }
    temp = temp->next;
   }
   Node* previousTemp = temp->prev;
   Node* newNode = new Node(value,previousTemp,temp);
   previousTemp->next = newNode;
   temp->prev = newNode;
   return head;
}
void insertionBeforeGivenNode(Node* node,int value)
{ 
    Node* previousNode = node->prev;
    Node* newNode = new Node(value,previousNode,node);
    previousNode->next = newNode;
    node->prev = newNode;
    return;
}
int main()
{
    vector<int> arr = {12,5,8,7};
    Node *head = StandardOps::convert2DLL(arr);

    insertionBeforeGivenNode(head->next->next, 100);
    StandardOps::printDLL(head);
    ///   StandardOps::printDLL(head);
}