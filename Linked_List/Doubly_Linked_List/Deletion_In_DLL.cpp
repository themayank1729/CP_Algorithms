#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;

Node *removeHead(Node *head)
{
    if (head == nullptr || head->next == nullptr) return nullptr;
    Node *newHead = head->next;
    newHead->prev = nullptr;
    head->next = nullptr;
    delete head;
    return newHead;
}

Node* removeTail(Node* head)
{
    if(head->next == nullptr || head == nullptr) return nullptr;
    Node* tail = head;
    while(tail->next != nullptr)
    {
        tail = tail->next;
    }
   Node* newTail = tail->prev;
   newTail->next = nullptr;
   tail->prev = nullptr;
   delete tail;
   return head;

}
Node* removeSpecificPosition(Node* head,int k)
{
    if(head == nullptr)
    {
        return head;
    }
   
    int count = 0;
    Node* temp = head;
    while(temp->next != nullptr)
    {
        count++;
        if(count == k)
        {
            break;
        }
        temp = temp->next;
    }
      Node* previousTemp = temp->prev;
      Node* nextTemp = temp->next;
      if(previousTemp == nullptr && nextTemp == nullptr)
      {
         delete temp;
         return NULL;
      }
      else if(previousTemp == nullptr)
      {
          return removeHead(head);
      }
      else if(nextTemp == nullptr)
      {
        return removeTail(head);
      }
      previousTemp->next = nextTemp;
      nextTemp->prev = previousTemp;
      temp->next = nullptr;
      temp->prev = nullptr;
      delete temp;
    return head;

}
Node* removeSpecificElement(Node* head,int element)
{
  if(head == nullptr)
    {
        cout<<"DLL is empty";
        return head;
    }
   
    Node* temp = head;
    while(temp->next != nullptr)
    {
        if(temp->data == element)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp->next == nullptr && temp->data != element)
    {
        cout<<"\nElement is not Present\n ";
        return head;
    }
    
      Node* previousTemp = temp->prev;
      Node* nextTemp = temp->next;
      if(previousTemp == nullptr && nextTemp == nullptr)
      {
         delete temp;
         return NULL;
      }
      else if(previousTemp == nullptr)
      {
          return removeHead(head);
      }
      else if(nextTemp == nullptr)
      {
        return removeTail(head);
      }
      previousTemp->next = nextTemp;
      nextTemp->prev = previousTemp;
      temp->next = nullptr;
      temp->prev = nullptr;
      delete temp;
    return head;
}

void deleteGivenNode(Node* temp)
{
 //Note :It will be given temp will never be head node.
    Node* previousTemp = temp->prev;
    Node* nextTemp = temp->next;
    if(nextTemp == nullptr)
    {
        previousTemp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    nextTemp->prev = previousTemp;
    previousTemp->next = nextTemp;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
     


}
int main()
{
    vector<int> arr = {2, 1, 3, 8,9,32};
    Node *head = StandardOps::convert2DLL(arr);
    StandardOps::printDLL(head);
    deleteGivenNode(head->next);
    StandardOps::printDLL(head);
}