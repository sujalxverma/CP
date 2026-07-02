#include "bits/stdc++.h"
using namespace std;
#define int long long

// dp[i][0] -> max ans for subtree from i, when taking range lowest.
// dp[i][1] -> max ans for subtree from i, when taking range highest.
vector<vector<int>> dp;
vector<vector<int>> range;
vector<vector<int>> g;

void dfs(int u, int p) {

    for (int v : g[u]) {
        if (p == v)
            continue;
        dfs(v, u);
        dp[u][0] += max({
            abs(range[u][0] - range[v][0]) + dp[v][0],
            abs(range[u][0] - range[v][1]) + dp[v][1],
        });
        dp[u][1] += max({
            abs(range[u][1] - range[v][0]) + dp[v][0],
            abs(range[u][1] - range[v][1]) + dp[v][1],
        });
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        range.resize(n + 1);
        dp.assign(n + 1, vector<int>(2, 0));
        g.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            range[i] = {u, v};
            // dp[i][0] = u;
            // dp[i][1] = v;
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, -1);
        cout << max(dp[1][0], dp[1][1]) << "\n";
        // for (int i = 1; i <= n; i++) {
        //     cout << i << " -> " << dp[i][0] << " " << dp[i][1] << "\n";
        // }
        g.clear();
        range.clear();
        dp.clear();
    }
    return 0;
}