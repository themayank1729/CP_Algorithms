//Max Length Subarray with atmost  two types of fruits that is  k = 2
#include<bits/stdc++.h>
using namespace std;
int maxFruitBasketBrute(vector<int>&arr,int k)
{
    //Time complexity - O ( n ^ 2)
   int maxLen = 0 ;
   int n = arr.size();
   for (int i = 0; i < n; i++)
   {
    set<int>st;
    for (int j = i; j < n; j++)
    {
       st.insert(arr[j]);   //maximum of log(3) cann e donnne which is nearly one
       if(st.size() <=  2 ) 
       {
        maxLen = max(maxLen,j-i+1);
       }
       else
       {
        break;
       }
    }
    
   }
   return maxLen;
   
}
int maxFruitBasketBetter(vector<int>&arr,int k)
{
    //Time complexity - O ( 2n )
   int maxLen = 0 ;
   int n = arr.size();
   map<int,int>mpp;
   int l=0,r=0;
   while(r<n)
   {
    mpp[arr[r]]++;
    if(mpp.size() > k)
    {
             while(mpp.size()  > k )
            {
                mpp[arr[l]]--;
               if(mpp[arr[l]] == 0) 
               {
                       if (mpp.find(arr[l]) != mpp.end()) {
                           mpp.erase(arr[l]); 
                          }
               }
               l++;
            }
   }
   if(mpp.size() <= k)
   {
    maxLen = max(maxLen,r-l+1);
   }
   r++;
}
   return maxLen;
   
}
int maxFruitBasketOptimal(vector<int>&arr,int k)
{
   //Time complexity - O ( n )
   int maxLen = 0 ;
   int n = arr.size();
   map<int,int>mpp;
   int l=0,r=0;

   while(r<n)
   {
    mpp[arr[r]]++;

    if(mpp.size() > k)
    {
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++; 
   }
    if(mpp.size() <= k)
   {
    maxLen = max(maxLen,r-l+1);
   }
   r++;
}
   return maxLen;

}
int main()
{
    vector<int>arr = {3,3,3,1,2,1,1,2,3,3,4};
    int k = 2;
    cout<<maxFruitBasketBrute(arr,k);
    cout<<maxFruitBasketBetter(arr,k);
    cout<<maxFruitBasketOptimal(arr,k);
}