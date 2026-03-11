#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<long long> dp(n + 1, -1e9);
    vector<int> parent(n + 1, -1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
    vector<int> toposort;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    dp[1] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        toposort.push_back(u);
        for (auto &v : g[u]) {
            degree[v]--;
            if (degree[v] == 0) {

                q.push(v);
            }
        }
    }

    for (auto &u : toposort) {
        if (dp[u] == -1e9) {
            continue;
        }

        for (auto &v : g[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = 1 + dp[u];
                parent[v] = u;
            }
        }
    }

    if (dp[n] == -1e9) {
        // for (int i = 1; i <= n; i++) {
        //     cout << i << " " << dp[i] << "\n";
        // }
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct path.
    vector<int> path;

    path.push_back(n);
    auto node = n;
    while (true) {
        node = parent[node];
        if (node == -1) {
            break;
        }
        path.push_back(node);
    }

    reverse(begin(path), end(path));
    if (path[0] != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << (int)path.size() << "\n";
    for (auto &x : path) {
        cout << x << " ";
    }
    cout << "\n";

    auto stop = high_resolution_clock::now();
    auto dpuration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << dpuration.count() << " microsecondps\n";

    return 0;
}