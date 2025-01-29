#include <bits/stdc++.h>

using namespace std;

//****************************************************************************************************************************************** */
int rangeSumBrute(vector<int> &arr)
{
    int maxi = INT_MIN, mini = INT_MAX;
    int total = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = INT_MIN, mini = INT_MAX;
        for (int j = i+1; j < n; j++)
        {
            ///we are using j = i + 1 because  self element is not contributing
            maxi = max(arr[j], maxi);
            mini = min(arr[j], mini);
            //cout << mini << " " << maxi << " " << (maxi - mini) << '\n';
            total += (maxi - mini);
        }
    }

    return total;
}
//******************************************************************************************************************************** */
int main()
{
    vector<int> arr;
    arr = {1, 4, 3, 2};
   /// cout << optimalRangeSum(arr);
}