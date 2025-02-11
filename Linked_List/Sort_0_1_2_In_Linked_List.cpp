#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *sortMayank(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *head0 = new Node(-1, nullptr);
    Node *head1 = new Node(-1, nullptr);
    Node *head2 = new Node(-1, nullptr);
    Node *temp0 = head0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            temp0->next = temp;
            temp0 = temp0->next;
        }
        else if (temp->data == 1)
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp1->next = nullptr;
    temp1->next = nullptr;
    temp2->next = nullptr;

    Node *tp = nullptr;

    tp = head1;
    head1 = head1->next;
    tp->next = nullptr;

    tp = head2;
    head2 = head2->next;
    tp->next = nullptr;

    tp = head0;
    head0 = head0->next;
    tp->next = nullptr;
    tp = nullptr;
    delete tp;
    temp0->next = head1;
    temp1->next = head2;
    return head0;
}
Node *sortStriver(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *head0 = new Node(-1, nullptr);
    Node *head1 = new Node(-1, nullptr);
    Node *head2 = new Node(-1, nullptr);
    Node *zero = head0;
    Node *one = head1;
    Node *two = head2;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = two;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (head1->next) ? head1->next : head2->next;
    one->next = head2->next;
    two->next = nullptr;

    Node *newHead = head0->next;
    delete head0, head1, head2;
    return newHead;
}
int main()
{
    vector<int> a = {2, 1, 0};
    Node *head = StandardOps::arrayToLL(a);
    head = sortMayank(head);
    StandardOps::printLL(head);
}