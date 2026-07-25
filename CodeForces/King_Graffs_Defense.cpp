#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int MAXN = 3e5 + 10;

int n, m;
vector<vector<pair<int, int>>> g; // {neighbor, edge_id}
int vis[MAXN];
int low[MAXN];
int dis[MAXN];
int timer = 0;
int ans = 0;

void dfs(int u, int parent_edge = -1) {
    vis[u] = 1;
    dis[u] = low[u] = timer++;

    for (auto [v, id] : g[u]) {

        // Skip only the edge we came through
        if (id == parent_edge)
            continue;

        if (vis[v]) {
            low[u] = min(low[u], dis[v]);
        } else {
            dfs(v, id);

            low[u] = min(low[u], low[v]);

            if (low[v] > dis[u])
                ans++;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset(vis, 0, sizeof(vis));
    fill(low, low + MAXN, 1e9);
    fill(dis, dis + MAXN, 1e9);

    g.assign(n + 1, {});

    int edge_id = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back({v, edge_id});
        g[v].push_back({u, edge_id});

        edge_id++;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }
    cout << ans / ((n * (n - 1) / 2) * 1.0) << '\n';

    return 0;
}