#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> vis, parent;
vector<vector<int>> g;
vector<int> cycle;
bool dfs(int u, int p) {
    vis[u] = 1;
    parent[u] = p;
    for (int v : g[u]) {
        if (v == p)
            continue;
        if (vis[v]) {
            // cycle found
            int curr = u;
            cycle.push_back(v);
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            return true;
        }
        if (dfs(v, u))
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1))
                break;
        }
    }
    if (cycle.size() < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << "\n";
    for (auto x : cycle)
        cout << x << " ";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}