#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *oddEvenListOptimal(Node *head)
{
    // O (  N / 2  * 2)
    if (head == nullptr && head->next == nullptr)
        return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
Node *oddEvenListBetter(Node *head)
{
    if (head == nullptr && head->next == nullptr)
        return head;
    Node *head1 = new Node(-1, nullptr);
    Node *temp1 = head1;
    Node *head2 = new Node(-1, nullptr);
    Node *temp2 = head2;
    int count = 1;
    while (head != nullptr)
    {
        if (count & 1)
        {
            Node *newNode = new Node(head->data, nullptr);
            temp1->next = newNode;
            temp1 = temp1->next;
        }
        else
        {
            Node *newNode = new Node(head->data, nullptr);
            temp2->next = newNode;
            temp2 = temp2->next;
        }
        head = head->next;
        count++;
    }
    Node *t1 = head1;
    head1 = head1->next;
    t1->next = nullptr;
    delete t1;

    Node *t2 = head2;
    head2 = head2->next;
    t2->next = nullptr;
    delete t2;

    temp1->next = head2;
    return head1;
}
int main()
{
    vector<int> a = {1, 2, 3};
    Node *head = StandardOps::arrayToLL(a);
    head = oddEvenListOptimal(head);
    StandardOps::printLL(head);
}