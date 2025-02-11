#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    // when we wnat to pass both data and address
    Node(int data, Node *next1)
    {
        this->data = data;
        this->next = next1;
    }
};
//To insert array elemnts in LL
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
//To get the Length of linked list
int LengthOfLL(Node* head)
{
     Node* mover = head;
     int length = 0;
     while(mover != nullptr)
     {
        mover =  mover->next;
        length++;
     }
     return length;
}
int searchInLL(Node* head,int element)
{
      Node* temp = head;
      while(temp != nullptr)
      {
        if(temp->data == element) return 1;
        temp = temp->next;
      }
      return 0;
}
int main()
{
    vector<int> arr = {2, 1, 3, 8};

    Node *head = arrayToLL(arr);
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << " [ " << temp->data << " | " << temp->next << " ] ===>";
        temp = temp->next;
    }
  cout<<"\nthe length of LL is : "<<LengthOfLL(head);
  cout<<"\nIs present or not : "<<searchInLL(head,3);
}