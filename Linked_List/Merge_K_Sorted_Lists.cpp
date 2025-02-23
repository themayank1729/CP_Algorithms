#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *merge2LinkedList(Node *head1, Node *head2)
{
    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
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
Node *mergeKLinkedList_Better(vector<Node *> &lists)
{
    Node *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        head = merge2LinkedList(head, lists[i]);
    }
    return head;
}

Node *mergeKLinkedList_Optimal(vector<Node *> &lists)
{
    priority_queue<pair<int, Node *>,
                   vector<pair<int, Node *>>, greater<pair<int, Node *>>>
        pq;

    // Insert the first node of each list (if not null) into the priority queue
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] != nullptr)
            pq.push({lists[i]->data, lists[i]});
    }

    Node *dumNode = new Node(-1, nullptr);
    Node *temp = dumNode;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        Node *minNode = p.second;
        temp->next = minNode;
        temp = temp->next;

        // Push next node of the extracted node into heap if exists
        if (minNode->next != nullptr)
        {
            pq.push({minNode->next->data, minNode->next});
        }
    }

    temp->next = nullptr; // Mark end of merged list
    return dumNode->next;
}

int main()
{
    // Create linked lists
    Node *head1 = new Node(2, new Node(4, new Node(6, nullptr)));
    Node *head2 = new Node(1, new Node(5, nullptr));
    Node *head3 = new Node(1, new Node(1, new Node(3, new Node(7, nullptr))));
    Node *head4 = new Node(8, nullptr);

    // Populate the lists vector
    vector<Node *> lists = {head1, head2, head3, head4};

    Node *mergedList = mergeKLinkedList_Better(lists);

    cout
        << "Merged Linked List: ";
    StandardOps::printLL(mergedList);

    return 0;
}
