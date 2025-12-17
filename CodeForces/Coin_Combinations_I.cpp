#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

/*
It is a permutational DP,
means 1 + 2 + 3 = x , is not same as 2 + 3 + 1 = x. and so on.
*/

ll f_tab(vector<ll> &a, ll n)
{
    vector<ll> dp(n + 1, 0);

    dp[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j < a.size(); j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] += (dp[i - a[j]]) % mod;
            }
        }
    }

    return dp[n] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n;
    cin >> m >> n;
    vector<ll> a(m + 1);
    a[0] = 0;
    for (ll i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    ll ans = f_tab(a, n);
    cout << ans << "\n";

    return 0;
}