#include <bits/stdc++.h>
#include "Doubly_Linked_List/NodeCreation.cpp"
using namespace std;
void printDLL(Node *head)
    {
        cout << "\n";
        Node *temp1 = head;
        while (temp1 != nullptr)
        {
            cout << "[ " << temp1->prev << " | " << temp1->data << " | " << temp1->next << " ] <==> ";
            temp1 = temp1->prev;
        }
        cout << "\n\n";
    }
void brute_ReverseDLL(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    StandardOps::printDLL(head);
}
Node* optimal_ReverseDLL(Node *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *previous = head->prev;
    Node *current = head;
    while (current != nullptr)
    {
        previous = current->prev;
        current->prev = current->next;
        current->next = previous;
        current = current->prev;
    }
    head = previous->prev;
    return head;
}
int main()
{
    vector<int> arr = {2, 1, 3, 8, 9};
    Node *head = StandardOps::convert2DLL(arr);
     
    optimal_ReverseDLL(head);
    StandardOps::printDLL(optimal_ReverseDLL(head));
}