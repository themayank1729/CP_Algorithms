
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
void matrixDiagonal(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
}
void nonmatrixDiagonal(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
}
void shadedRegions(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j <= n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
}
void crossPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
    cout << "\n\n";
}

int main()
{
    int n;
    cin >> n;
    matrixDiagonal(n);
    cout << "\n\n";
    nonmatrixDiagonal(n);
    cout << "\n\n";
    shadedRegions(n);
    cout << "\n\n";
    crossPattern(n);
}