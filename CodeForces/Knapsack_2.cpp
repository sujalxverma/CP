#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int n;
ll W;
vector<ll> w, v;
// vector<vector<ll>> dp;
const ll inf = 1e18;
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> W;
    v.resize(n);
    w.resize(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        total += v[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(total + 1, inf));
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= total; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j - v[i - 1] >= 0) {
                dp[i][j] = min(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= total; i++) {
        if (dp[n][i] <= W) {
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}