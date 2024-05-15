
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char ch = 'A';
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            
        if(abs(i - 5)+ abs(j - 5) <=4)
            cout<<"x";
        else
            cout<<" ";

        }
        cout << "\n";
    }

    return 0;
}
