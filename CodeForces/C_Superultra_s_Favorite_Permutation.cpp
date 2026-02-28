#include "bits/stdc++.h"
using namespace std;

using ll = long long;

vector<ll> sieveOfEratosthenes(ll n)
{
    vector<ll> numbers(n + 1, 0); // 0 = prime, 1 = not prime

    for (ll i = 2; i * i <= n; i++)
    {
        if (numbers[i])
            continue;

        for (ll j = i * i; j <= n; j += i)
        {
            numbers[j] = 1; // mark as not prime
        }
    }

        return numbers;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> f = sieveOfEratosthenes(200010);
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 4)
        {
            cout << "-1\n";
            continue;
        }
        int i = 2;
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
        i -= 2;
        int j = 1;
        int k = -1;
        while (j <= n)
        {

            if (f[j + i] == 1) // not prime.
            {
                k = j - 2;
                break;
            }
            j += 2;
        }

        while (j <= n)
        {
            cout << j << " ";
            j += 2;
        }
        if (k > -1)
        {
            while (k >= 1)
            {
                cout << k << " ";
                k -= 2;
            }
        }
        cout << "\n";
    }
    return 0;
}