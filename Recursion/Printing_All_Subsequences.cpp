#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
#define ppb pop_back
#define nline "\n" 
void printingAllSubsequences(int i,int n,vector<int>&ans,vector<int>&arr)
{
 if(i>=n)
 {
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<nline;
    return;
    
 }  
 ans.pb(arr[i]);
 printingAllSubsequences(i+1,n,ans,arr);
 ans.ppb();
 printingAllSubsequences(i+1,n,ans,arr);

}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        arr.pb(num);
    }
    vector<int>ans;
  printingAllSubsequences(0,arr.size(),ans,arr);   
}