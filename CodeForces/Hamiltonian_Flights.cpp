#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u][v]++;
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, 0));

    dp[0][1] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
        if ((mask & 1) == 0) {
            // city 1 not visited, not possible, cause we start from city 1.
            continue;
        }
        if (mask != ((1 << n) - 1) && (mask & (1 << (n - 1)))) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                // this city is visited.
                // so from this ciry we can go to all its neigbours which are not visited.
                for (int k = 0; k < n; k++) {
                    if (k != j && !(mask & (1 << k)) && g[j][k] > 0) {
                        dp[k][mask | (1 << k)] = (dp[k][mask | (1 << k)] % mod + (g[j][k] % mod * (dp[j][mask] % mod)) % mod) % mod;
                    }
                }
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1] % mod << "\n";
    return 0;
}