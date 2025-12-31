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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll maxi = 0;
    for (auto &x : a)
    {
        cin >> x;
        maxi = max(maxi, x);
    }
    vector<ll> f = sieveOfEratosthenes(sqrt(maxi));
    for (auto &x : a)
    {
        if (x == 1)
        {
            cout << "NO\n";
            continue;
        }
        if (floor(sqrt(x)) * floor(sqrt(x)) == x)
        {
            if (f[floor(sqrt(x))] == 0)
            {
                //    cout<<sqrt(x)<<"\n";
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}