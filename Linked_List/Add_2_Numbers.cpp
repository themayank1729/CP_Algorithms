#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* temp1 = l1;
    Node* temp2 = l2;
    Node* head = new Node(-1, nullptr);
    Node* temp = head;
    int carry = 0, data = 0;
    while (temp1 != nullptr || temp2 != nullptr)
    {
        if (temp1 != nullptr && temp2 != nullptr)
        {
            data = (temp1->data + temp2->data + carry) % 10;
            carry = (temp1->data + temp2->data + carry) / 10;
            Node* newNode = new Node(data, nullptr);
            temp->next = newNode;
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1 != nullptr && temp2 == nullptr)
        {
            data = (temp1->data + carry) % 10;
            carry = (temp1->data + carry) / 10;
            Node* newNode = new Node(data, nullptr);
            temp->next = newNode;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else if (temp2 != nullptr && temp1 == nullptr)
        {
            data = (temp2->data + carry) % 10;
            carry = (temp2->data + carry) / 10;
            Node* newNode = new Node(data, nullptr);
            temp->next = newNode;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    if (carry != 0)
    {
        Node* newNode = new Node(carry, nullptr);
        temp->next = newNode;
    }
    temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return head;
}


int main()
{
    vector<int> a = {2, 4, 3};
    vector<int> b = {5, 6, 4};
    Node *l1 = StandardOps::arrayToLL(a);
    Node *l2 = StandardOps::arrayToLL(b);
    Node *head = addTwoNumbers(l1, l2);
    StandardOps::printLL(head);
}