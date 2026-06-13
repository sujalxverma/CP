#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll n, m;
vector<vector<ll>> g;
vector<vector<ll>> dp;
const ll mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u][v]++;
    }
    dp.resize(1 << (n), vector<ll>(n, 0));

    dp[1][0] = 1;

    for (ll mask = 2; mask < (1 << (n)); mask++) {
        if ((mask & (1 << (n - 1))) && mask != (1 << n) - 1)
            continue;
        if (!(mask & 1))
            continue;
        for (ll i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // this is part of subset, and assuming this is last city.
                for (ll j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    if (((mask ^ (1 << i)) & (1 << j)) && g[j][i] >= 1) {
                        dp[mask][i] = (dp[mask][i] % mod + (g[j][i] * dp[mask ^ (1 << i)][j]) % mod) % mod;
                    }
                }
            }
        }
    }
    cout << dp[(1 << (n)) - 1][n - 1] % mod;

    return 0;
}