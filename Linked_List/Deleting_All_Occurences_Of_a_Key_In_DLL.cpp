#include <bits/stdc++.h>
#include "Doubly_Linked_List/NodeCreation.cpp"
using namespace std;
Node *deletingOccurencesOfKey(Node *head, int key)
{
    Node *temp = head;
    Node *nextNode = nullptr;
    Node *prevNode = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if (nextNode)
            {
                nextNode->prev = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    Node *head = StandardOps::convert2DLL(arr);

    StandardOps::printDLL(head);
    head = deletingOccurencesOfKey(head, 10);
    StandardOps::printDLL(head);
    ///   StandardOps::printDLL(head);
}