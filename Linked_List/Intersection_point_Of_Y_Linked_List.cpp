#include <bits/stdc++.h>
#include "NodeCreation.cpp"

using namespace std;
Node *IntersectionofYLL_Optimal(Node *head1, Node *head2)
{
    //Time complexity = O ( n1 + n2)
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == nullptr)
            temp1 = head2;
        if (temp2 == nullptr)
            temp2 = head1;
    }
    return temp1;
}
//*************************************************************************************************** */
Node *collisionPoint(Node *temp1, Node *temp2, int d)
{
    
    while (d)
    {
        d--;
        temp2 = temp2->next;
    }
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}
Node *IntersectionofYLL_Better(Node *head1, Node *head2)
{
    //Time complexity - O ( n1+ n2  ) + O ( max(n1,n2))

    int l1 = 0;
    int l2 = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != nullptr)
    {
        temp1 = temp1->next;
        l1++;
    }
    while (temp2 != nullptr)
    {
        temp2 = temp2->next;
        l2++;
    }
    if (l1 < l2)
    {
        return collisionPoint(head1, head2, l2 - l1);
    }
    else
    {
        return collisionPoint(head2, head1, l1 - l2);
    }
}
/****************************************************************************************************** */
int main()
{
    vector<int> arr = {3, 1};
    vector<int> prr = {1, 2, 4, 5};
    vector<int> trr = {4, 6, 2};
    Node *head1 = StandardOps::arrayToLL(arr);
    Node *head2 = StandardOps::arrayToLL(prr);
    Node *head3 = StandardOps::arrayToLL(trr);
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    temp1->next = head3;
    temp2->next = head3;
    /// Node* ans  = IntersectionofYLL_Better(head1,head2);
    /// cout<<"\n";
    Node *ans = IntersectionofYLL_Optimal(head1, head2);
    cout << ans->data;
    // StandardOps::printLL(head1);
    // StandardOps::printLL(head2);
}