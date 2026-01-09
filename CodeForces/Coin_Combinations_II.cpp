#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

/*
It is a combnational DP,
means 1 + 2 + 3 = x , is same as 2 + 3 + 1 = x. and so on.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n;
    cin >> m >> n;
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < m; i++)
    {
        for (ll j = a[i]; j <= n; j++)
        {
            dp[j] += dp[j - a[i]] % mod;
        }
    }
    cout << dp[n] % mod << "\n";
    return 0;
}
