#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
const int inf = -1e18; // neg
vector<vector<int>> g;
vector<int> dp;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dp.resize(n + 1, inf);
    g.resize(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
    vector<int> toposort;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 0)
            continue;
        q.push(i); // will start from the nodes, with no earlier dependencies.
    }
    dp[1] = 1;
    vector<int> path(n + 1, -1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        toposort.push_back(u);
        for (int v : g[u]) {
            degree[v]--;
            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // already its given, its a DAG.
    // we only need to find dependency order, which is toposort.
    for (auto &u : toposort) {
        if (dp[u] == inf) { // possible case, 3 -> 1, so there is 3 before visiting 1.
            continue;       // but we start from 1, so we discard all paths from 3.
        }
        for (auto &v : g[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                path[v] = u;
            }
        }
    }

    if (dp[n] == inf) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> trace;
    int v = n;
    while (v != -1) {
        trace.push_back(v);
        v = path[v];
    }
    if (trace.back() != 1) { // its plausible, that 1 and n are on different components.
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dp[n] << "\n";
    for (int i = (int)trace.size() - 1; i >= 0; i--) {
        cout << trace[i] << " ";
    }
    cout << "\n";

    return 0;
}