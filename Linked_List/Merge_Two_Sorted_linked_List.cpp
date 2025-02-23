#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *merge2LinkedList(Node *head1, Node *head2)
{
    if(head1 == nullptr && head2 == nullptr) return nullptr;
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
int main()
{
    vector<int> arr = {1, 2, 2, 7, 8, 9};
    vector<int> brr = {3, 4, 5};
    Node *head1 = StandardOps::arrayToLL(arr);
    Node *head2 = StandardOps::arrayToLL(brr);
    // StandardOps::printLL(head1);
    // StandardOps::printLL(head2);
    Node *head = merge2LinkedList(head1, head2);
    StandardOps::printLL(head);
}