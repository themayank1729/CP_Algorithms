#include <bits/stdc++.h>
#include "./Singly_Linked_List/NodeCreation.cpp"
using namespace std;
Node *DeleteNthNodeFromEnd(Node *head, int n)
{
    // Brute force approach
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    if (length == n)
    {
        Node *newHead = head;
        head = head->next;
        newHead->next = nullptr;
        delete newHead;
        return head;
    }
    int res = length - n;
    temp = head;
    while (temp != nullptr)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    deleteNode->next = nullptr;
    delete deleteNode;
    return head;
}
Node *DeleteNthNodeFromEnd_Optimal(Node *head, int n)
{
    // Optimal  approach - fast and slow pointer
    if(head == nullptr) return head;
    Node *fastp = head;
    Node *slowp = head;
    for (int i = 0; i < n; i++)
    {
        fastp = fastp->next;
    }
    if (fastp == nullptr)
    {
        Node *deltedNode = head;
        head = head->next;
        deltedNode->next = nullptr;
        delete deltedNode;
        return head;
    }
    while (fastp->next != nullptr)
    {
        slowp = slowp->next;
        fastp = fastp->next;
    }
    Node *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
int main()
{
    vector<int> arr = {3, 2, 5, 6, 8, 45, 78, 6, 845, 34};
    Node *head = StandardOps::arrayToLL(arr);
    head = DeleteNthNodeFromEnd_Optimal(head, arr.size());
    StandardOps::printLL(head);
}