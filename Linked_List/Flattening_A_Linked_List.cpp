
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

Node *merge(Node *list1, Node *list2)
{

    Node *dumNode = new Node(-1);
    Node *res = dumNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = res->child;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = res->child;
            list2 = list2->child;
        }
        res->next = nullptr;
    }
    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    if (dumNode->child)
    {
        dumNode->child->next = NULL;
    }

    return dumNode->child;
}

Node *flattenLinkedList(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;
    Node *mergeHead = flattenLinkedList(head->next);
    head = merge(head, mergeHead);
    return head;
}

void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
