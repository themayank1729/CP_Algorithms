#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node *findNthNode(Node *temp, int k)
{
  int count = 1;
  while (temp != nullptr)
  {
    if (count == k)
    {
      return temp;
    }
    count++;
    temp = temp->next;
  }
  return temp;
}
Node *rotateLinkedList(Node *head, int k)
{
  if (head == nullptr || k == 0)
    return head;
  int length = 1;

  Node *tail = head;
  while (tail->next != nullptr)
  {
    length++;
    tail = tail->next;
  }
  if (k % length == 0)
    return head;
  k = k % length;
  tail->next = head;
  Node *newLastNode = findNthNode(head, length - k);
  head = newLastNode->next;
  newLastNode->next = nullptr;
  return head;
}
int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = StandardOps::arrayToLL(arr);
  head = rotateLinkedList(head, 5);
  StandardOps::printLL(head);
}