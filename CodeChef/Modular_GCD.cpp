#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Modular Exponention
ll mul_mod(ll a, ll b, ll m)
{
    return (ll)((__int128)a * b % m);
}

ll mod_pow(ll base, ll exp, ll m)
{
    ll res = 1;
    base %= m;
    while (exp > 0)
    {
        if (exp & 1)
            res = mul_mod(res, base, m);
        base = mul_mod(base, base, m);
        exp >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll mod_A = mod_pow(a, n, mod);
        ll mod_B = mod_pow(b, n, mod);
        ll diff = abs(a - b);
        if (diff == 0)
        {
            cout << (2 * mod_pow(a, n, mod)) % mod << "\n";
            continue;
        }
        ll x = (mod_pow(a, n, diff) + mod_pow(b, n, diff)) % diff;
        cout << gcd(diff, x) << "\n";
    }

    return 0;
}