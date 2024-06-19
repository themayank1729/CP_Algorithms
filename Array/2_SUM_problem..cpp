#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
string TWO_SUM(int n, vector<int> book, int target)
{
    // It is optimal in case  of "YES" or "NO" only else the better one is the most optimal one
    //  Time Complexity - O(NlogN + N)
    // Space Complexity - O(1)
    sort(book.begin(), book.end());
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int sum = book[i] + book[j];
        if (sum == target)
        {
            return "YES";
        }
        if (sum < target)
            i++;
        else
            j--;
    }
    return "NO";
}

string read(int n, vector<int> book, int target)
{
    // Better Approach
    // Time Complexity - O(NlogN)
    // Space Complexity - O(N)
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int moreneeded = target - a;
        if (mp.find(moreneeded) != mp.end())
        {
            return "YES"; // return {mp[moreneeded] , i};
        }
        mp[a] = i;
    }
    return "NO";
}
int main()
{
}
