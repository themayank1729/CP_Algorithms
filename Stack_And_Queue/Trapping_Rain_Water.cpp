#include <bits/stdc++.h>

using namespace std;
int trap(vector<int> &height)
{
    int lMax = 0, rMax = 0, l = 0, total = 0;
    int r = height.size() - 1;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (lMax > height[l])
            {
                total += (lMax - height[l]);
            }
            else
            {
                lMax = height[l];
            }
            l++;
        }
        else
        {
            if (height[r] < rMax)
            {
                total += (rMax - height[r]);
            }
            else
            {
                rMax = height[r];
            }
            r--;
        }
    }
    return total;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}