#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MAXN = 3e5 + 10;
const int inf = 1e9;
vector<vector<array<int, 2>>> g;
vector<vector<int>> bg; // bridge tree.
int timer = 0;
int vis[MAXN];
int compid[MAXN];
int id[MAXN]; // marks if edge with id->i , is a bridge or not.
int n, m;
int low[MAXN];
int dis[MAXN];
void dfs(int u, int pid = -1) {
    low[u] = dis[u] = timer;
    timer++;
    vis[u] = 1;
    for (auto &x : g[u]) {
        int v = x[0];
        int i = x[1];
        if (i == pid) {
            continue;
        }
        if (vis[v] == 1) {
            low[u] = min(low[u], dis[v]);
        } else {
            dfs(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dis[u]) {
                id[i] = 1;
            }
        }
    }
}

// assign component id.
void dfs2(int u, int comp) {
    vis[u] = 1;
    compid[u] = comp;
    for (auto &x : g[u]) {
        int v = x[0];
        int i = x[1];
        if (id[i] == 1) {
            // skip
        } else if (vis[v] == 0) {

            dfs2(v, comp);
        }
    }
}

int treeDiameter(const vector<vector<int>> &g) {
    int n = g.size();

    // local DFS lambda: finds farthest node and distance from a start
    auto dfs = [&](int start) {
        vector<int> dist(n, -1);
        stack<int> st;
        st.push(start);
        dist[start] = 0;

        int farthestNode = start;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    st.push(v);
                    if (dist[v] > dist[farthestNode]) {
                        farthestNode = v;
                    }
                }
            }
        }
        return pair<int, int>{farthestNode, dist[farthestNode]};
    };

    // 1st DFS from arbitrary node (0)
    int v = dfs(1).first;

    // 2nd DFS from v gives the diameter
    int diameter = dfs(v).second;

    return diameter; // number of edges
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n + 1);
    bg.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    fill(&low[0], &low[0] + MAXN, inf);
    fill(&dis[0], &dis[0] + MAXN, 0);
    fill(&vis[0], &vis[0] + MAXN, 0);
    fill(&id[0], &id[0] + MAXN, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }
    fill(&vis[0], &vis[0] + MAXN, 0);
    int comp = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs2(i, comp);
            comp++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto &x : g[i]) {
            int v = x[0];
            if (compid[i] < compid[v]) {
                bg[compid[i]].push_back(compid[v]);
                bg[compid[v]].push_back(compid[i]);
            }
        }
    }

    // now, diameter is the path, which has max number of edges in b/w the ends
    // of a diamter, so we can choose that.
    cout << treeDiameter(bg) << "\n";
    return 0;
}