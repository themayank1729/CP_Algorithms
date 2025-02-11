#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data, Node *prev, Node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    Node(int data)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};
class StandardOps
{
public:
    static void printDLL(Node *head)
    {
        cout << "\n";
        Node *temp1 = head;
        while (temp1 != nullptr)
        {
            cout << "[ " << temp1->prev << " | " << temp1->data << " | " << temp1->next << " ] <==> ";
            temp1 = temp1->next;
        }
        cout << "\n\n";
    }
    static Node *convert2DLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *visit = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], visit, nullptr);
            visit->next = temp;
            visit = temp;
        }
        return head;
    }
};