#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Optimal  approach maths
    int n = a.size();
    long long SN = (n * 1LL * (n + 1)) / 2;
    long long SN2 = (n * 1LL * (n + 1) * 1LL * (2 * n + 1)) / 6;
    long long S = 0;
    long long S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 = S2 + (a[i] * 1LL * a[i]);
    }
    long long val1 = (S - SN);   //  (x-y)
    long long val2 = (S2 - SN2); // (x^2 - y^2)
    val2 = val2 / val1;          // (x+y)
    long long x = (val2 + val1) / 2;
    long long y = (x - val1);
    return {(int)x, (int)y};
}
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Optimal  approach XOR
    int n = a.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    int setBit = 0;
    while (1)
    {
        if ((xr & (1 << setBit)) != 0)
        {
            break;
        }
        setBit++;
    }
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of  zer club
        if ((a[i] & (1 << setBit)) == 0)
        {
            zero ^= a[i];
        }
        else
        {
            one ^= a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // part of  zer club
        if ((i & (1 << setBit)) == 0)
        {
            zero ^= i;
        }
        else
        {
            one ^= i;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            count++;
    }
    if (count == 2)
        return {zero, one};
    else
        return {one, zero};
}