#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat)
{
    // Time Complexity for transpose - O(N/2 * N/2)
    int n = mat.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Time Complexity for reverse - O(N* N/2);
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}