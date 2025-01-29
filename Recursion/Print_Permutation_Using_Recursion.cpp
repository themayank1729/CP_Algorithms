#include <bits/stdc++.h>
#define ll long long int

using namespace std;
void printPermutation(vector<int>&v,vector<int>&ds,int fre[],vector<vector<int>>&ans)
{
    
    if(ds.size()  == v.size())
    {
        ans.push_back(ds);
        for (auto num : ds)
        {
            cout<<num<<" ";
        }
        cout<<"\n";
        return;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if(!fre[i])
        {
            ds.push_back(v[i]);
            fre[i] = 1;
            printPermutation(v,ds,fre,ans);
           
            fre[i] = 0;
            ds.pop_back();
        }
    }

}
void solve()
{
   int n;
   cin>>n;
   std::vector<int> v;
   for (int i = 1; i <= n ; ++i)
   {
      v.push_back(i);
   }
   vector<int>ds;
   vector<vector<int>>ans;
   int fre[n] = {0};
   for (int i = 0; i < n; ++i)
   {
       fre[i] = 0;
   }
   printPermutation(v,ds,fre,ans);
   


}
int main()
{
   int t=1;
   //cin>>t;
   while(t--)
   {
    solve();
   }
}
