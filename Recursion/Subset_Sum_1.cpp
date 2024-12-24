#include<bits/stdc++.h>
using namespace std;
void subsetSum(int ind,int sum,vector<int>arr,int N,vector<int>&ans)
{
     if(ind >= N)
     {
        ans.push_back(sum);
        return;
     }
    subsetSum(ind+1,sum+arr[ind],arr,N,ans);
    subsetSum(ind+1,sum,arr,N,ans);
}
int main()
{
int n;
cin>>n;
vector<int>arr;
for (size_t i = 0; i < n; i++)
{
int num;
cin>>num;
arr.push_back(num);
}
vector<int>ans;
subsetSum(0,0,arr,n,ans);
sort(ans.begin(),ans.end());

for (auto it : ans)
{
cout<<it<<" ";
}
}