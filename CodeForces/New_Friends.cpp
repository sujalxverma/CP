#include "bits/stdc++.h"
using namespace std;
long long n, m;
vector<vector<long long>> g;
vector<long long> vis;
long long nodes, edges;
void dfs(long long u) {
    vis[u] = 1;

    nodes++;
    edges += g[u].size();

    for (long long v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
/*
 * In every union operation, the find() (also known as find() in many texts) function must be called for both nodes.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            edges /= 2;
            ans += (nodes * (nodes - 1)) / 2 - edges;
            edges = 0;
            nodes = 0;
        }
    }
    cout << ans << "\n";

    return 0;
}