

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 4 * n + 5; j++)
        {
            if (i % 4 + j % 4 == 5 - 1 || i % 4 == j % 4)
            {
                cout << "X";
            }
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
