#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *insertionAtHead(Node *head, int value)
{
    if (head == nullptr)
    {
        return new Node(value, nullptr);
    }

    Node *temp = new Node(value, head);
    head = temp;
    return head;
}
Node *insertionAtLast(Node *head, int value)
{
    if (head == nullptr)
    {
        return new Node(value, nullptr);
    }
    Node *temp2 = new Node(value, nullptr);
    Node *temp = head;

    while (temp->next = nullptr)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    return head;
}
Node *insertionAtSpecificPosition(Node *head, int value, int pos)
{
    if (head == NULL)
    {
        if (pos == 1)
            return new Node(value, nullptr);
        return nullptr;
    }
    if (pos == 1)
    {
        Node *temp = new Node(value, head);
        return temp;
    }
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == pos - 1)
        {
            Node *temp2 = new Node(value, temp->next);
            temp->next = temp2;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *insertionBehindSpecificValue(Node *head, int value, int element)
{
    // It  is guaranteed that the posvalue is present
    if (StandardOps::searchInLL(head, element) == 0)
    {
        cout << "Elemnt is not present\n";
        return head;
    }
    if (head == NULL)
    {
        return head;
    }
    if (head->data == element)
    {
        Node *temp = new Node(value, head);
        return temp;
    }
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->next->data == element)
        {
            Node *temp2 = new Node(value, temp->next);
            temp->next = temp2;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 1, 3, 8, 9};

    Node *head = StandardOps::arrayToLL(arr);
    StandardOps::printLL(head);
    head = insertionBehindSpecificValue(head, 32, 3);
    StandardOps::printLL(head);
}