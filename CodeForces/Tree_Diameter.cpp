#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> g;
int n;
pair<int, int> bfs(int s, int p) {
    vector<int> dis(n + 1, 0);
    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &v : g[u]) {
            if (vis[v] == 1)
                continue;
            dis[v] = 1 + dis[u];
            q.push(v);
            vis[v] = 1;
        }
    }
    int node = -1;
    int d = -1;
    for (int i = 1; i <= n; i++) {
        if (d < dis[i]) {
            d = dis[i];
            node = i;
        }
    }
    return {d, node};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pair<int, int> p = bfs(1, -1);
    pair<int, int> ans = bfs(p.second, -1);
    std::cout << ans.first << "\n";

    return 0;
}