#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> fr;
const int MAXN = 1e5 + 10;
const ll mod = 998'244'353;
const ll MOD = 998'244'353;
/*
1. Calculate contribution of each s[i] in terms of bit in the subarrays formed.
*/

// Fast modular exponentiation
ll mod_pow(ll base, ll exp)
{
    ll result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
int main()
{
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        fr.assign(MAXN, 0);
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                continue;
            for (int j = i; j < n; j++)
            {
                fr[j - i]++;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                continue;

            for (int j = 1; j < i; j++)
            {
                fr[j]++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < MAXN; i++)
        {
            if (fr[i] % 2 == 0)
                continue;
            ans = (ans % mod + mod_pow(2, i) % mod) % mod;
        }

        cout << ans << "\n";
    }
}
