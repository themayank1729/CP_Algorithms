#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool>isPrime(N,1);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<N;i++)
	{
       if(isPrime[i]==true)
       {
         for(int j=2*i;j<N;j+=i)
         {
         	isPrime[j]=false;
         }
	 
	   }
    }

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cout<<isPrime[i]<<"\n";
    }
   
}
