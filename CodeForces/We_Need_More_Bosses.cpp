#include "bits/stdc++.h"
using namespace std;
constexpr int MAXN = 3e5 + 10;
int n, m;
vector<vector<int>> g;

int vis[MAXN];
int low[MAXN];
int dis[MAXN];
int timer = 0;
int ans = 0;
void dfs(int u, int p = -1) {
    low[u] = dis[u] = timer++;
    vis[u] = 1;
    bool parent = false;
    for (int &v : g[u]) {
        if (v == p && !parent) {
            parent = true;
            continue;
        }
        if (v == p) {
            continue;
        }
        if (vis[v] == 1) {
            low[u] = min(low[u], dis[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dis[u]) {
                ans++;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(&vis, 0, sizeof(vis));
    fill(&low[0], &low[0] + MAXN, 1e9);
    fill(&dis[0], &dis[0] + MAXN, 1e9);
    g.assign(n + 1, vector<int>{});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    cout << ans << "\n";
    return 0;
}