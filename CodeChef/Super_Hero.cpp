#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// Segmented Seive

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

    vector<ll> primeFactors;
    for (ll i = 2; i <= n; i++)
    {
        if (!numbers[i])
        {
            primeFactors.push_back(i);
        }
    }

    return primeFactors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> f = sieveOfEratosthenes(1e6 + 5);
    while (t--)
    {
        ll h, k;
        cin >> h >> k;
        ll maxK = 1;
        while (maxK * 2 <= k)
        {
            maxK *= 2;
        }

        ll ans = log2(maxK);

        while (h > 1)
        {
            if (h % 2 == 0)
            {
                h /= 2;
                ans++;
            }
            else
            {
                bool ft = true;
                for (ll i = 0; i < (int)f.size(); i++)
                {
                    if (h % f[i] == 0)
                    {
                        h /= f[i];
                        ft = false;
                        ans++;
                        break;
                    }
                }
                if (ft)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}