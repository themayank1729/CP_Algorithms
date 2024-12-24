#include<bits/stdc++.h>
using namespace std;
void printPermutation(int i,vector<int>&nums,vector<vector<int>>&ans)
{
     //Optimal Approach 
    //Time Complexity - n! * n
    //Space Complexity        no extra space , only used for returning
    if(i==nums.size())
    {
        ans.push_back(nums);
       return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i],nums[j]);
        printPermutation(i+1,nums,ans);
        swap(nums[i],nums[j]);
    }
    

}
int main()
{
    vector<int>nums = {3,1,2};
    vector<vector<int>>ans;
    printPermutation(0,nums,ans);
        for ( auto it : ans)
        {
            for (auto i : it)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        
}