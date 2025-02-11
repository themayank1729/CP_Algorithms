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
    // when we just want to pass data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    // y is just a pointer variable that stores the address of the head node (the first node of the linked list in this case).
    //Node *head = new Node(arr[0], nullptr);
    Node *head = new Node(arr[0]);
    //   head -----> [ data: 2 | next: nullptr ]
    cout << head->data << " " << head->next << " \n";

    Node *newNode = new Node(arr[1]);
    head->next = newNode;

    // Now :  head  --> [ data: 2 | next ] --> [ data: 5 | nullptr ]
    Node *newNode1 = new Node(arr[2]);
    newNode->next = newNode1;

    Node *newNode2 = new Node(arr[3]);
    newNode1->next = newNode2;
    // Traversing the Linked List
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << "[ " << temp->data << " | " << temp->next << " ] ===>  ";
        temp = temp->next;
    }
    
    ////   [ 2 | 0x5936ef88c700 ] ===>  [ 5 | 0x5936ef88c720 ] ===>  [ 8 | 0x5936ef88c740 ] ===>  [ 7 | 0 ] ===>
}