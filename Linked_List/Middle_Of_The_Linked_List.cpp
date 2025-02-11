#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *middleOFLL_Brute(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    int length = StandardOps::LengthOfLL(head);

    int mid = (length / 2) + 1;
    mid = mid--;
    while (temp != nullptr)
    {
        mid--;
        if (mid == 0)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
// Tortoise and Hare Algorithm // fast and slow pointer
Node *middleOFLL_Optimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *fast = head;
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = StandardOps::arrayToLL(arr);
    Node *temp = middleOFLL_Optimal(head);
    // StandardOps::printLL(temp->data);
    cout << temp->data << " \n";
}