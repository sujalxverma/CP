#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define line cout << "\n"

void dfs(vector<vector<int>> &edges, vector<int> &visited, vector<int> &order, int start) {
    visited[start] = 1;
    for (auto node : edges[start]) {
        if (visited[node] == -1) {
            dfs(edges, visited, order, node);
        }
    }
    order.push_back(start);
}

void solve() {
    int n;
    cin >> n;
    vi extras(n);
    rep(i, 0, n) {
        cin >> extras[i];  // 0: i -> n+1, 1: n+1 -> i
    }

    vector<vector<int>> edges(n + 2);  // villages: 1 to n+1

    // Type 1 roads: i -> i+1 (for 1 <= i <= n-1)
    for (int i = 1; i <= n - 1; i++) {
        edges[i].push_back(i + 1);
    }

    // Type 2 roads based on extras
    for (int i = 0; i < n; i++) {
        if (extras[i] == 1) {
            edges[n + 1].push_back(i + 1);  // n+1 -> i+1
        } else {
            edges[i + 1].push_back(n + 1);  // i+1 -> n+1
        }
    }

    // DFS + Topological Sort
    vector<int> visited(n + 2, -1);
    vector<int> order;
    for (int i = 1; i <= n + 1; i++) {
        if (visited[i] == -1) {
            dfs(edges, visited, order, i);
        }
    }

    // Check if we visited all nodes
    if ((int)order.size() != n + 1) {
        cout << -1 << endl;
        return;
    }

    // Reverse topological order to get path
    reverse(order.begin(), order.end());

    // Verify if each consecutive pair in order is connected
    bool valid = true;
    for (int i = 0; i < n; i++) {
        int u = order[i], v = order[i + 1];
        // Check if there's a directed edge from u to v
        if (find(edges[u].begin(), edges[u].end(), v) == edges[u].end()) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << -1 << endl;
        return;
    }

    // Output the valid path
    for (int v : order) cout << v << " ";
    line;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
