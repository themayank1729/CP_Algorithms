#include<bits/stdc++.h>
using namespace std;
void printPermutation(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int freq[])
{
    //Brute Force Approach 
    //Time Complexity - n! * n
    //Space Complexity        O(n) + O (n)
     if(ds.size() == nums.size())
   {
    ans.push_back(ds);
    return;
   }
   for (int i = 0; i < nums.size(); i++)
   {
        if(!freq[i])// if element is not taken that is frequency is zero 
        {
             ds.push_back(nums[i]);
             freq[i] = 1;
             printPermutation(ds,nums,ans,freq);
             freq[i] = 0;
             ds.pop_back();
        }
   }
   
}
int main()
{
    vector<int>nums = {3,1,2};
    vector<int>ds;
    vector<vector<int>>ans;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
    {
        freq[i] = 0;
    }
    printPermutation(ds,nums,ans,freq);
        for ( auto it : ans)
        {
            for (auto i : it)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        
}