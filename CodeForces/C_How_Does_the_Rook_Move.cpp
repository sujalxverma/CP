#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll f(ll i, vector<ll> &dp)
{
    if (i == 0 || i == 1) return 1;
    if (dp[i] != -1) return dp[i];
    
    return dp[i] = (f(i-1, dp) + 2LL * (i-1) * f(i-2, dp) % MOD) % MOD;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll used = 0;

    for (int i = 0; i < k; i++) {
        ll r, c;
        cin >> r >> c;
        used += 2 - (r == c);  // adds 1 or 2
    }

    ll m = n - used;

    if (m <= 0) {
        cout << 1 << "\n";
        return;
    }

    vector<ll> dp(m+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    cout << f(m, dp) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
