#include <bits/stdc++.h>
using namespace std;
int bruteUniqueElements(vector<int> v1)
{
    set<int> st;
    for (int i : v1)
    {
        st.insert(i);
    }
    return st.size();
}
int optimalUniqueElements(vector<int> v1)
{
    int i = 0;
    for (int j = 1; j < v1.size(); j++)
    {
        if (v1[i] != v1[j])
        {
            v1[i + 1] = v1[j];
            i++;
        }
    }
    return i + 1;
}
int removeDuplicates(vector<int> &nums)
{
    // leetcode solution
    int i = 0, j = 1;

    int n = nums.size();

    if (n == 1)
        return 1;

    // int cnt=0;

    while (j < n)
    {
        while (j < n && nums[i] == nums[j])
            j++;
        if (j >= n)
            break;
        i++;
        nums[i] = nums[j];
    }

    return i + 1;
}
int main()
{
    vector<int> v1{1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
    cout << bruteUniqueElements(v1) << endl;
    cout << optimalUniqueElements(v1) << endl;
    cout << removeDuplicates(v1);
}