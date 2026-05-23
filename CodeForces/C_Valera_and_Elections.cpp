#include "bits/stdc++.h"
using namespace std;

void dfs(vector<vector<pair<int, int>>> &g, int u, vector<int> &vis, set<int> &s, int p) {
    for (auto [v, k] : g[u]) {
        if (v == p) {
            continue;
        }
        dfs(g, v, vis, s, u);
        if (k == 2) {
            if (vis[v] == 0) {
                vis[v] = 1;
                s.insert(v);
                vis[u] = 1;
            } else {
                vis[u] = 1;
            }
        }
        if (k == 1) {
            if (vis[v] == 1) {
                vis[u] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> vis(n + 1, 0);
    set<int> s;

    for (int i = 1; i <= n - 1; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        g[u].push_back({v, k});
        g[v].push_back({u, k});
    }
    dfs(g, 1, vis, s, -1);
    cout << (int)s.size() << "\n";
    for (auto &x : s) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}