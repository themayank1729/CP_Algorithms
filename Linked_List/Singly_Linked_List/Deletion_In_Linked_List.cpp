#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;

Node *arrayToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
int LengthOfLL(Node *head)
{
    Node *mover = head;
    int length = 0;
    while (mover != nullptr)
    {
        mover = mover->next;
        length++;
    }
    return length;
}

int searchInLL(Node *head, int element)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == element)
            return 1;
        temp = temp->next;
    }
    return 0;
}
Node *removeHead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *removeLastNode(Node *head)
{
    // When the linked list is empty
    if (head == nullptr)
        return head;
    // when the linked list only contians single element
    if (head->next == nullptr)
    {
        // first we have to delte the last node then return nullptr
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node *removeSpecificPosition(Node *head, int pos)
{
    // 1 Indexing based deletion
    if (head == nullptr)
        return head;
    // for start index position
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == pos)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
Node* removeSpecificValue(Node* head,int val)
{
   if(head == nullptr) return head;
   if(head->data == val)
   {
      Node* temp = head;
      head = head->next;
      delete temp;
      return head;
   }
  Node *temp = head;
    Node *prev = nullptr;
    int count = 0;
    while (temp != nullptr)
    {
        
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
int main()
{
    vector<int> arr = {2, 1, 3, 8, 9};

    Node *head = StandardOps::arrayToLL(arr);
    StandardOps::printLL(head);
    head = removeSpecificValue(head, 3);
    StandardOps::printLL(head);
}