#include <bits/stdc++.h>
#include "Doubly_Linked_List/NodeCreation.cpp"
using namespace std;
Node *removeDuplicates(Node *head)
{

    /// Without deleting the repeating nodes
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        Node *nextNode = temp->next;
        while (nextNode != nullptr && nextNode->data == temp->data)
        {
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if (nextNode)
        {
            nextNode->prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
Node *removeDuplicates_Deletion(Node *head)
{

    // deleting the repeating nodes
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        Node *nextNode = temp->next;
        if (nextNode != nullptr && nextNode->data == temp->data)
        {
            if (nextNode->next == nullptr)
            {
                temp->next = nullptr;
                nextNode->prev = nullptr;
                delete nextNode;
                break;
            }
            Node *delNode = nextNode;
            nextNode = nextNode->next;
            delNode->next = nullptr;
            delNode->prev = nullptr;
            temp->next = nextNode;
            nextNode->prev = temp;
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
    vector<int> arr = {0,1, 1, 1, 2, 3, 3, 4, 5, 6, 6};
    Node *head = StandardOps::convert2DLL(arr);

    StandardOps::printDLL(removeDuplicates_Deletion(head));
}