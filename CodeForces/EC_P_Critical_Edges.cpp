#include "bits/stdc++.h"
using namespace std;
int t, n, m;
const int inf = 1e9;
vector<vector<int>> g;
vector<int> low, dis;
vector<int> vis;
int timer;
vector<array<int, 2>> bridge;
void dfs(int u, int p) {
    vis[u] = 1;
    low[u] = dis[u] = timer;
    timer++;
    bool parent_skipped = false;
    for (int &v : g[u]) {
        if (v == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[v] == 1) {
            low[u] = min(low[u], dis[v]);
        }
        if (vis[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dis[u]) {
                bridge.push_back({u, v});
            }
        }
    }
}

void solve(int tc) {
    timer = 0;
    cin >> n >> m;

    low.assign(n + 1, inf);
    dis.assign(n + 1, inf);
    bridge.clear();
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << "Caso #" << tc << "\n";
    if (bridge.size() == 0) {
        cout << "Sin bloqueos\n";
        return;
    }
    cout << bridge.size() << "\n";
    for (auto &x : bridge) {
        if (x[0] > x[1])
            swap(x[0], x[1]);
    }
    sort(bridge.begin(), bridge.end());
    sort(begin(bridge), end(bridge));
    for (auto &x : bridge) {
        cout << x[0] << " " << x[1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    int tc = 1;
    while (tc <= t) {
        solve(tc);
        tc++;
    }

    return 0;
}