#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *reverseLinkedListRecursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *newHead = reverseLinkedListRecursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
int main()
{
    vector<int> arr = {3, 2, 5, 6, 8};
    Node *head = StandardOps::arrayToLL(arr);
    head = reverseLinkedListRecursive(head);
    StandardOps::printLL(head);
}