#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
vector<int> a;
vector<vector<int>> g;
vector<int> ans;
vector<int> temp;
vector<int> subtree;
vector<int> sum;
vector<int> dis;
int maxAns = -1e18;

void dfs1(int u, int p) { // subtree sum
    subtree[u] += a[u];
    for (int &v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            subtree[u] += subtree[v];
        }
    }
}

void dfs2(int u, int p, int d) {
    temp[u] += a[u] * d;
    dis[u] = d;
    for (int &v : g[u]) {
        if (v != p) {
            dfs2(v, u, d + 1);
            temp[u] += temp[v];
        }
    }
}

void dfs3(int u, int p) {
    if (u != 1) {
        ans[u] = ((ans[1] - temp[u]) + dis[u] * (subtree[1] - subtree[u]) - dis[u] * (subtree[u]));
    }
    for (int &v : g[u]) {
        if (v != p) {
            dfs3(v, u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    temp.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    subtree.assign(n + 1, 0);
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << subtree[i] << " ";
    }
    cout << "\n";
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";
    ans[1] = temp[1];
    dfs3(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}