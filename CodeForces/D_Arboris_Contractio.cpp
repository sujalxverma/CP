#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> adj;
int n;

// DFS to find farthest node and distance from given start node
pair<int,int> dfs(int u, int p, int depth) {
    pair<int,int> res = {depth, u};
    for (int v : adj[u]) {
        if (v == p) continue;
        auto cur = dfs(v, u, depth + 1);
        if (cur.first > res.first) res = cur;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        adj.assign(n+1, vector<int>());
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Find diameter of tree
        // Find farthest from node 1 (or any node)
        auto [_, u] = dfs(1, -1, 0);
        // Find farthest from u
        auto [diameter, v] = dfs(u, -1, 0);

        // Step 2: Calculate minimum operations
        // If diameter <= 2, no operation needed
        int res = 0;
        if (diameter > 2) {
            res = (diameter + 1) / 2 - 1;
        }

        cout << res << "\n";
    }

    return 0;
}
