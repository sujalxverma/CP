#include "bits/stdc++.h"
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &c, int u, int p, int &size, int cl) {
    c[u] = cl;
    if (size == -1) {
        size = -1;
    } else {

        size++;
    }
    for (auto &v : g[u]) {
        if (v != p && c[v] == c[u]) {
            size = -1;
            // return;
        }
        if (v != p && c[v] == -1) {
            c[v] = !c[u];
            dfs(g, c, v, u, size, !c[v]);
        }
    }
}

int f(vector<vector<int>> &g, int &n) {
    int ans = 0;
    vector<int> c(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (c[i] == -1) {
            int size = 0;
            dfs(g, c, i, -1, size, 0);
            ans += max(size, 0);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (m == 0) {
            cout << n << "\n";
            continue;
        }
        int ans = f(g, n);
        cout << ans << "\n";
    }

    return 0;
}