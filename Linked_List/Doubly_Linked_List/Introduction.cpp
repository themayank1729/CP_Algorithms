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
int main()
{
  

}