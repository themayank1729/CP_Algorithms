#include<bits/stdc++.h>
using namespace std;
int calculateXOR(int n)
{
    if(n%4 ==1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n; 
}
int main()
{
     int l,r;
     cin>>l>>r;
     int an =0;
     cout<<(calculateXOR(l-1) ^ calculateXOR(r));
    
   
}