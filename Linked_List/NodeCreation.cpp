#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class StandardOps
{
public:
    static Node *arrayToLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0], nullptr);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr);
            mover->next = temp;
            mover = mover->next;
        }
        return head;
    }
    static void printLL(Node *head)
    {
        if (head == nullptr)
        {
            cout << "\nEmpty linked list\n";
            return;
        }
        Node *temp = head;
        cout << "\n";
        while (temp != nullptr)
        {
            cout << " [ " << temp->data << " | " << temp->next << " ] ===>";
            temp = temp->next;
        }
        cout << "\n\n";
    }
    static int LengthOfLL(Node *head)
    {
        Node *mover = head;
        int length = 0;
        while (mover != nullptr)
        {
            mover = mover->next;
            length++;
        }
        return length;
    }
    static int searchInLL(Node *head, int element)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == element)
            return 1;
        temp = temp->next;
    }
    return 0;
}
};