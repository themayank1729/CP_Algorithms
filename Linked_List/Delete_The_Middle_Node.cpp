#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *deletingMiddleElement_Optimal1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *fast = head;
    Node *slow = head;
    Node *prev = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
}
// Tortoise and Hare Algorithm // fast and slow pointer
Node *deletingMiddleElement_Optimal2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *fast = head;
    Node *slow = head;
    fast = fast->next->next;
    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5,6};
    Node *head = StandardOps::arrayToLL(arr);
    //head = deletingMiddleElement_Optimal1(head);
    head = deletingMiddleElement_Optimal2(head);
    StandardOps::printLL(head);
    // cout << temp->data << " \n";
}