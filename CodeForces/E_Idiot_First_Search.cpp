#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<long long> subtree;
vector<long long> ans;
vector<vector<long long>> tree;
vector<long long> parent;
const long long mod = 1e9 + 7;
long long dfs(long long u) {
    if (tree[u].size() == 0) {
        subtree[u] = 0;
        return 1;
    }
    for (long long &v : tree[u]) {
        subtree[u] += dfs(v);
    }
    return subtree[u] + 1;
}
void bfs() {
    queue<long long> q;
    parent[1] = 0;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (long long &v : tree[u]) {
            parent[v] = u;
            q.push(v);
        }
    }
}
void cal() {
    queue<pair<long long, long long>> q;
    q.push({1, subtree[1]});
    ans[1] = (2 * subtree[1] + 1) % mod;
    while (!q.empty()) {
        long long u = q.front().first;
        long long value = q.front().second;
        q.pop();

        for (long long &v : tree[u]) {
            ans[v] = (2 * subtree[v] + ans[u] + 1) % mod;
            q.push({v, ans[v]});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        // tree [0 , n], n+1 nodes.
        subtree.assign(n + 1, 0);
        ans.assign(n + 1, 0);
        tree.resize(n + 1);
        tree[0].push_back(1);
        parent.resize(n + 1);
        for (long long i = 1; i <= n; i++) {
            long long u, v;
            cin >> u >> v;
            if (u == 0 && v == 0)
                continue;
            tree[i].push_back(u);
            tree[i].push_back(v);
        }
        long long _ = dfs(0);
        bfs();
        for (long long i = 1; i <= n; i++) {
            ans[i] = (2 * (subtree[i] % mod)) % mod;
        }
        cal();
        for (long long i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        subtree.clear();
        ans.clear();
        tree.clear();
        parent.clear();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}