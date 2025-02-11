#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
// for brute force use stack, then again traverse and compare
Node* reverseLL(Node* head)
{
    if(head == nullptr || head->next == nullptr ) return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
bool isPalendrome(Node *head)
{
    // Optimal  approach
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *fast = head;
    Node *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr)
    {
        if(first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}
int main()
{
    vector<int> arr = {1,3,4,4,3};
    Node *head = StandardOps::arrayToLL(arr);
    cout << isPalendrome(head);
    // StandardOps::printLL(head);
}