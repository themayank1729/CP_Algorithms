#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
vector<int> lowestPrime(N, 0), highestPrime(N, 0);
vector<bool> isPrime(N, true);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            lowestPrime[i] = highestPrime[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highestPrime[j] = i;
                if (lowestPrime[j] == 0)
                    lowestPrime[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "  " << lowestPrime[i] << "  " << highestPrime[i] << "\n";
    }
    return 0;
}
