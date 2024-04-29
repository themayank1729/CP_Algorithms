#include <bits/stdc++.h>
using namespace std;
vector<int> rotate_array(vector<int> v1, int D)
{
    int n = v1.size();
    D = D % n;
    // Brute force approach
    int temp[D];
    for (int i = 0; i < D; i++)
    {
        temp[i] = v1[i];
    }
    for (int i = D; i < n; i++)
    {
        v1[i - D] = v1[i];
    }
    for (int i = n - D; i < n; i++)
    {
        v1[i] = temp[i - (n - D)];
    }

    return v1;
}
vector<int> rotatedArray(vector<int> v1)
{
    int temp = v1[0];
    for (int i = 1; i < v1.size(); i++)
    {
        v1[i - 1] = v1[i];
    }
    v1[v1.size() - 1] = temp;
    return v1;
}
int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v1_rotated = rotate_array(v1, 3);
    for (vector<int>::iterator it = v1_rotated.begin(); it < v1_rotated.end(); it++)
    {
        cout << *it << " ";
    }
}