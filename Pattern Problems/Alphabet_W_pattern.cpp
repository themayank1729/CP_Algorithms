
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char ch='A';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == j%8 || i+j%8 ==8)
            {
                 cout<<char('A'+j);

                    }
            else
                cout <<" ";
        }
        cout << "\n";
    }

    return 0;
}
