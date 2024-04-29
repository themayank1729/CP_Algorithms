#include <bits/stdc++.h>
using namespace std;
int bruteSecondlargest(vector<int> v1)
{
    // time complexity   O(nlogn)+O(n)
    sort(v1.begin(), v1.end());
    int largest = v1[v1.size() - 1];
    for (int i = v1.size() - 2; i >= 0; i--)
    {
        if (v1[i] != largest)
        {
            return v1[i];
        }
    }
    return -1; // if there is no second largest element
}
int betterSecondlargest(vector<int> v1)
{
    // time complexity   O(n)+O(n)=O(2n)
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] > largest)
            largest = v1[i];
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if ((v1[i] > slargest) && (v1[i] != largest))
        {
            slargest = v1[i];
        }
    }
    return slargest;
}
int optimalSecondlargest(vector<int> v1)
{
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] > largest)
        {
            slargest = largest;
            largest = v1[i];
        }
        else if (v1[i] > slargest && v1[i] < largest)
            slargest = v1[i];
    }
    return slargest;
}
int main()
{
    vector<int> v1{1, 34, 5, 7, 4, 5476, 87, 8};
    cout << bruteSecondlargest(v1) << endl;
    cout << betterSecondlargest(v1) << endl;
    cout << optimalSecondlargest(v1) << endl;
}