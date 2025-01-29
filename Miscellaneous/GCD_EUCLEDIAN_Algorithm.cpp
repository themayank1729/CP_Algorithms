#include <bits/stdc++.h>
using namespace std;
int numGCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a + b);
}
int main()
{
    int a, b;
    cout << "enter two numbers : ";
    cin >> a >> b;
    cout << "\n GCD is : " << numGCD(a, b);
    return 0;
}