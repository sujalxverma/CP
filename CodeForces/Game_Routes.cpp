#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const int mod = 1e9 + 7;

/*
First, create toposort order, then process the order to find ways, longest path, shortest path, and so on.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
    vector<int> ways(n + 1, 0);

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    ways[1] = 1;
    vector<int> toposort;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        toposort.push_back(u);
        for (auto &v : g[u]) {
            degree[v]--;
            if (degree[v] == 0) {

                q.push(v);
            }
        }
    }

    for (int &u : toposort) {
        if (ways[u] != 0) {
            for (auto &v : g[u]) {
                ways[v] = (ways[u] % mod + ways[v] % mod) % mod;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << ways[i] << "\n";
    // }
    // cout << "\n";

    cout << ways[n] % mod << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}