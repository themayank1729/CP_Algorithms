#include <bits/stdc++.h>
#include "NodeCreation.cpp"
Node *makeLoop(Node *head)
{
    Node *temp = head;
    temp = temp->next->next;
    Node *temp1 = head;
    while (temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}
// for brute force approach use -- hashing or map to store Node* and its occurence
Node *lengthOfLoopInLinkedList(Node *head)
{
    // Optimal Approach  - Tortoise and Hare Algorithm || Fast and slow pointer
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    // Time Complexity - O ( N )
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = StandardOps::arrayToLL(arr);
    head = makeLoop(head);
    Node *temp = lengthOfLoopInLinkedList(head);
    cout << temp->data << "\n";
}