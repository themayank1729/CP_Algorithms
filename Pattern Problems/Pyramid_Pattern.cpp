
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j< 2*n-1;j++)
        {
            if(i+j >=  n-1 && j<= i+ n-1 )
            {
                cout<<"*";
                
            }
            else
            cout<<" ";
        }
        cout<<"\n";
    }

    return 0; 
}
