#include "bits/stdc++.h"
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<int>& visited) {
    visited[u] = 1;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, g, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, g, visited);
        }
    }

    cout << m - n + count << "\n";
    return 0;
}
