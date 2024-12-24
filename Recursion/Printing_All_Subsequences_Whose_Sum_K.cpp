#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define nline "\n"
void printSubsequence(int i,int n,int toBeSum,int sum,vector<int>&arr,vector<int>&ans)
{
   if(i >= n)
   {
     if(toBeSum == sum )
     {
       for (int i = 0; i < ans.size(); i++)
       {
        cout<<ans[i]<<" ";
       }
       cout<<nline;
     }
     return;
   }
   ans.pb(arr[i]);
   toBeSum = toBeSum + arr[i];
   printSubsequence(i+1,n,toBeSum,sum,arr,ans);
   ans.ppb();
   toBeSum = toBeSum - arr[i];
   printSubsequence(i+1,n,toBeSum,sum,arr,ans);

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
    printSubsequence(0,n,0,sum,arr,ans);
}


