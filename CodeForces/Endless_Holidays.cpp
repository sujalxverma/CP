#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
int n, m;
bool iscycle(vector<vector<int>> &g) {
    int N = g.size();
    vector<int> vis(N, 0);
    vector<int> com(N, 0);
    auto dfs = [&](auto self, int x) -> bool {
        vis[x] = 1;
        for (auto y : g[x]) {
            if (com[y])
                continue;
            if (vis[y])
                return true;
            if (self(self, y))
                return true;
        }
        vis[x] = 0;
        com[x] = 1;
        return false;
    };

    for (int i = 0; i < N; i++) {
        if (dfs(dfs, i)) {
            return true;
        }
    }
    return false;
}

void solve() {

    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u, v});
        edges.push_back({v, u});
    }

    int w;
    cin >> w;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    // self loop.
    for (int i = 0; i < n; i++) {
        edges.push_back({i, i});
    }

    vector<vector<int>> g(n * w);

    for (auto &[x, y] : edges) {
        for (int i = 0; i < w; i++) {
            int j = (i + 1) % w;
            if (s[x][i] == 'o' && s[y][j] == 'o') {
                g[n * i + x].push_back(n * j + y);
            }
        }
    }

    if (iscycle(g)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}