#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v)
{
    // Time comlexity - O(N)
    unordered_map<int, int> hash;
    for (int i = 0; i < v.size(); i++)
    {
        hash[v[i]]++;
    }
    for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++)
    {
        if ((it->second) > (v.size() / 2))
        {
            return (it->first);
        }
    }
    return -1;
}

int majorityElement(vector<int> v)
{
    // Moore's voting Algorithm
    // Time complexity - O(N)
    int count = 0;
    int el;
    for (int i = 0; i < v.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            el = v[i];
        }
        else if (v[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    // if majority element is there then following loop will happen
    int count1 = 0;
    for (int i : v)
    {
        if (i == el)
        {
            count1++;
        }
    }
    if (count1 > (v.size() / 2))
    {
        return el;
    }
    return -1;
}
int main()
{
}