#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define nline "\n"
bool printSubsequence(int i,int n,int toBeSum,int sum,vector<int>&arr,vector<int>&ans)
{
   if(i == n)
   {
     if(toBeSum == sum )
     {
       for (int i = 0; i < ans.size(); i++)
       {
        cout<<ans[i]<<" ";
       }
       cout<<nline;
       return true;
     }
     return false;
    }
    ans.pb(arr[i]);
    toBeSum = toBeSum + arr[i];
   if(printSubsequence(i+1,n,toBeSum,sum,arr,ans) == true) {
    return true;
   }
   
   toBeSum = toBeSum - arr[i];
   ans.ppb();
   if(printSubsequence(i+1,n,toBeSum,sum,arr,ans) == true)
   {
    return true;
   }
   return false;

}
int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        arr.pb(num);
    }
    vector<int>ans;
    bool result = printSubsequence(0,n,0,sum,arr,ans);
}


