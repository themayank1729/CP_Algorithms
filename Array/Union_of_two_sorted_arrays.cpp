#include <bits/stdc++.h>
using namespace std;
set<int> union_of_array(vector<int> &v1, vector<int> &v2)
{
    // time complexity - O(nlogn)+O(mlogm)+
    set<int> st;
    for (int i = 0; i < v1.size(); i++)
    {
        st.insert(v1[i]);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        st.insert(v2[i]);
    }
    return st;
}
vector<int> sortedArrayOptimal(const vector<int> &a, const vector<int> &b)
{
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (unionArr.empty() || a[i] != unionArr.back())
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            if (unionArr.empty() || b[j] != unionArr.back())
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
        else
        { // If both elements are equal
            if (unionArr.empty() || a[i] != unionArr.back())
            {
                unionArr.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    while (i < a.size())
    {
        if (unionArr.empty() || a[i] != unionArr.back())
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while (j < b.size())
    {
        if (unionArr.empty() || b[j] != unionArr.back())
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

int main()
{
    vector<int> v1{
        1,
        2,
        3,
        3,
        4,
        4,
        4,
        5,
        5,
        5,
        5,
    };
    vector<int> v2{
        2,
        2,
        3,
        3,
        4,
        5,
        6,
        7,
        7,
        8,
        8,
    };

    vector<int> vec = sortedArrayOptimal(v1, v2);
    for (auto it : vec)
    {
        cout << it << " ";
    }
}