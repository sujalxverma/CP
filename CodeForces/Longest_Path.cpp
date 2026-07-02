#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, 0);
    vector<vector<int>> g(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
            dp[i] = 0;
        }
    }
    vector<int> toposort;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        toposort.push_back(u);
        for (int &v : g[u]) {
            degree[v]--;
            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }
    // dp[i] -> maximum path where last node is i.
    for (int &u : toposort) {
        for (int &v : g[u]) {
            dp[v] = max(dp[v], 1 + dp[u]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}