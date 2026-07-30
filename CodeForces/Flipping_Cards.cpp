#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MAXN = 1e5;
const int NUM = 2 * MAXN + 10;
int n;
vector<vector<int>> g;
vector<vector<int>> rg; // transpose graph.
vector<int> order;      // order of nodes as per finished time.
vector<int> vis;        // visited array.
vector<int> ids;        // SCC ids.
vector<vector<int>> cg; // condensed graph
void dfs(int u) {       // first dfs call on g.
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
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        auto add_edge = [&](int x, int y) {
            g[x].push_back(y);
            rg[y].push_back(x);
        };
        g.assign(2 * MAXN + 10, vector<int>{});
        cg.assign(2 * MAXN + 10, vector<int>{});
        ids.assign(2 * MAXN + 10, -1);
        rg.assign(2 * MAXN + 10, vector<int>{});
        vis.assign(2 * MAXN + 10, 0);
        order.clear();
        set<int> used;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            used.insert(u);
            used.insert(v);
            // simple -> u or v : !u -> v and !v -> u
            add_edge(MAXN + u, v);
            add_edge(MAXN + v, u);
        }
        if (n == 1) {
            cout << "possible\n";
            continue;
        }
        if ((int)used.size() < n) {
            cout << "impossible\n";
            continue;
        }

        for (int i = 1; i < NUM; i++) {
            if (vis[i] == 0) {
                dfs(i);
            }
        }
        vis.assign(NUM, 0);
        reverse(begin(order), end(order));
        int cnt = 0;
        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            if (vis[u] == 0) {
                dfs2(u, cnt);
                cnt++;
            }
        }
        bool f = true;
        for (int i = 1; i <= n; i++) {
            if (ids[i] == ids[i + MAXN]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}