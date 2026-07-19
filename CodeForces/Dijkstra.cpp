#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dis(n + 1, inf);
    vector<int> parent(n + 1, -1);
    priority_queue<array<int, 3>, std::vector<array<int, 3>>, std::greater<array<int, 3>>> pq;

    pq.push({0, 1, -1}); // dist , u , p
    dis[1] = 0;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int d = x[0];
        int u = x[1];
        int p = x[2];
        if (d > dis[u])
            continue;

        parent[u] = p;
        for (auto &y : g[u]) {
            int v = y[0];
            int w = y[1];
            if (v == p) {
                continue;
            }
            if (dis[v] > w + dis[u]) {
                dis[v] = w + dis[u];
                pq.push({dis[v], v, u});
            }
        }
    }

    if (dis[n] == inf) {
        cout << "-1\n";
        return 0;
    }
    vector<int> path;
    int node = n;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(begin(path), end(path));
    for (int &v : path) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}