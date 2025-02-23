
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};

// Function to insert a copy of each
// node in between the original nodes
void insertCopyInBetween(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
}

void connectRandomPointers(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        Node *copiedNode = temp->next;
        if (temp->random != nullptr)
        {
            copiedNode->random = temp->random->next;
        }
        else
        {
            copiedNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node *getDeepCopyList(Node *head)
{
    Node *dumNode = new Node(-1);
    Node *res = dumNode;
    Node *temp = head;

    while (temp != nullptr)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dumNode->next;
}

Node *cloneLL(Node *head)
{
    if (!head)
        return nullptr;

    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

void printClonedLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->data;
        if (head->random != nullptr)
        {
            cout << ", Random: " << head->random->data;
        }
        else
        {
            cout << ", Random: nullptr";
        }
        cout << endl;

        head = head->next;
    }
}

int main()
{
    // 7-> 14 -> 21 -> 28
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node *clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
