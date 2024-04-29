#include <bits/stdc++.h>
using namespace std;
void moveZeroesBrute(vector<int> &v1)
{
    vector<int> non_zro;
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i] != 0)
            non_zro.push_back(v1[i]);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if (i < non_zro.size())
            v1[i] = non_zro[i];
        else
            v1[i] = 0;
    }
}
void optimalMoveZeroes(vector<int> &v1)
{
    // Time comlexity-O(n);
    // Space complexity-O(1)
    int j = -1;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        return;
    }
    for (int i = j + 1; i < v1.size(); i++)
    {
        if (v1[i] != 0)
        {
            swap(v1[i], v1[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> v1{1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    //  moveZeroesBrute(v1);
    optimalMoveZeroes(v1);
    for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
    {
        cout << *it << " ";
    }
}