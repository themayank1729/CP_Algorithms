#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
Node *Add1ToLL(Node *head)
{
    if (head == nullptr)
        return head;
    head = reverseLL(head);
    int carry = 1;
    Node *temp = head;
    Node *previous = head;
    while (temp != nullptr)
    {
        int sum = carry + temp->data;
        temp->data = sum % 10;
        carry = sum / 10;
        if (carry == 0)
            break;
        previous = temp;
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newnode = new Node(1, nullptr);
        previous->next = newnode;
    }
    head = reverseLL(head);
    return head;
}
int helper(Node *temp)
{
    if (temp == nullptr)
        return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}
Node *functionRecursive(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1, nullptr);
        newNode->next = head;
        return newNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {9, 9, 9};
    Node *head = StandardOps::arrayToLL(arr);
    head = functionRecursive(head);
    StandardOps::printLL(head);
}