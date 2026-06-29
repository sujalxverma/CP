#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> dp1, dp2;
// dp2[u] -> not taking any edge from u to any of its child.
// dp1[u] -> taking only single edge from u to any of its child, which leads to max answer.
vector<vector<int>> g;
void dfs(int u, int p) {
    if (g[u].size() == 1) {
        dp2[u] = 0;
        dp1[u] = 0;
    }

    for (int v : g[u]) {
        if (p == v)
            continue;
        dfs(v, u);
        dp2[u] += max(dp1[v], dp2[v]);
    }
    for (int v : g[u]) {
        if (p == v)
            continue;
        dp1[u] = max(dp1[u], (1 + dp2[v]) + (dp2[u] - (max(dp2[v], dp1[v]))));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n + 1);
    dp1.resize(n + 1, 0);
    dp2.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp1[1], dp2[1]) << "\n";

    return 0;
}