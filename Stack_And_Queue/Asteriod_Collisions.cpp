#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    ////Time Complexity - O (2 * N)
    //Space Complexity - O ( n )
    vector<int>list;
    int n = asteroids.size();
    for (int i = 0; i < n; i++)
    {
        if(asteroids[i] > 0) 
        {
            list.push_back(asteroids[i]);
        }
        else
        {
            while(!list.empty() && (list.back() > 0 ) &&  ( list.back() < abs(asteroids[i]))  )
            {
                list.pop_back();
            }
            if(!list.empty() && list.back() == abs(asteroids[i]))
            {
                list.pop_back();
            }
            else if(list.empty()  || list.back() < 0)
            {
                   list.push_back(asteroids[i]);
            }
        }
    }
    
    return list;
}
int main()
{
    vector<int> asteriods = {8,-8};
    vector<int> ans = asteroidCollision(asteriods);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}