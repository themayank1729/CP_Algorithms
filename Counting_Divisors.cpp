#include <bits/stdc++.h>
using namespace std;
void printDivisors(int n)
{
    vector<int> v1;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v1.push_back(i);
            if (n / i != i)
                v1.emplace_back(n / i);
        }
    }
    sort(v1.begin(), v1.end());
    cout << "\n";
    for (int it : v1)
    {
        cout << "   " << it << " ";
    }
}
int main()
{
    int num;
    cout << "enter number of  which you want to print the divisors ";
    cin >> num;
    printDivisors(num);
}