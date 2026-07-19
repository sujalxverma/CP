#include "bits/stdc++.h"
using namespace std;
int n, m;
vector<vector<int>> g;
vector<vector<int>> rg;
vector<int> order;
vector<int> vis;
vector<int> ids;
vector<vector<int>> cg;
void dfs(int u) { // first dfs call on g.
    vis[u] = 1;
    for (int &v : g[u]) {
        if (vis[v] == 1)
            continue;
        dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u, int id) { // second dfs call on rg.
    vis[u] = 1;
    ids[u] = id;
    for (int &v : rg[u]) {
        if (vis[v] == 1)
            continue;
        dfs2(v, id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n + 1);
    cg.resize(n + 1);
    ids.resize(n + 1);
    rg.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    vis.assign(n + 1, 0);
    reverse(begin(order), end(order));
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int u = order[i];
        if (vis[u] == 0) {
            dfs2(u, u);
            cnt++;
        }
    }
    if (cnt == 2) {
        // complete graph is single SSC.
        cout << "YES\n";
    }

    int idx = ids[order[0]];
    for (int i = 1; i <= n; i++) {
        for (int &j : g[i]) {
            if (idx != ids[j]) {
                cout << "NO\n";
                cout << j << " " << order[0] << "\n";
                return 0;
            }
        }
    }

    return 0;
}