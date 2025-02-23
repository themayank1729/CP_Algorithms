#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *mergeLinkedList(Node *head1, Node *head2)
{
    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
    Node *dHead = new Node(-1, nullptr);
    Node *tempD = dHead;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data > temp2->data)
        {
            tempD->next = temp2;
            tempD = tempD->next;
            temp2 = temp2->next;
        }
        else
        {

            tempD->next = temp1;
            tempD = tempD->next;
            temp1 = temp1->next;
        }
    }
    if (temp1 != nullptr)
        tempD->next = temp1;
    else
        tempD->next = temp2;

    Node *delHead = dHead;
    dHead = dHead->next;
    delete delHead;
    return dHead;
}
Node *findMiddleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *sortLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *mid = findMiddleNode(head);
    Node *right = mid->next;
    Node *left = head;
    mid->next = nullptr;
    left = sortLinkedList(left);
    right = sortLinkedList(right);
    return mergeLinkedList(left, right);
}
int main()
{
    vector<int> arr = {3, 4, 2, 1, 5, 0};

    Node *head = StandardOps::arrayToLL(arr);

    // StandardOps::printLL(head1);
    // StandardOps::printLL(head2);
    head = sortLinkedList(head);
    StandardOps::printLL(head);
}