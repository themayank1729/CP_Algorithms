
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << max(abs(i - 5), abs(j - 5));
        }
        cout << "\n";
    }

    return 0;
}
