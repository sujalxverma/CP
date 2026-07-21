#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 1e9;
int n, m;
vector<vector<int>> g;
vector<int> coins;
vector<int> scc;
vector<int> low, disc;
vector<int> onstack;
vector<vector<int>> cg;
vector<int> cgcoins;
vector<array<int, 2>> edges;
vector<int> dp;
stack<int> st;
int timer = 0;
int comp = 1;
void tarjan(int u) {
    low[u] = disc[u] = timer;
    timer = timer + 1;
    st.push(u);
    onstack[u] = 1;
    for (int &v : g[u]) {
        if (disc[v] == inf) {
            tarjan(v);
            low[u] = min(low[u], low[v]); // we want best low answer from child.
        } else if (onstack[v]) {
            low[u] = min(low[u], disc[v]); // but if child already visited, means we found back edge, so we compare
                                           // low[u] with disc[v].
        }
    }
    if (low[u] == disc[u]) {
        while (!st.empty() && st.top() != u) {
            scc[st.top()] = comp;
            onstack[st.top()] = 0;
            st.pop();
        }
        scc[u] = comp;
        comp = comp + 1;
        onstack[u] = false;
        st.pop();
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    coins.assign(n + 1, 0);
    scc.resize(n + 1);
    disc.assign(n + 1, inf);
    low.assign(n + 1, inf);
    onstack.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        g[u].push_back(v);
    }
    // Instead of just tarjan(1);
    for (int i = 1; i <= n; i++) {
        if (disc[i] == inf) {
            tarjan(i);
        }
    }
    cg.resize(comp + 3);
    cgcoins.assign(comp + 3, 0);
    for (int i = 1; i <= n; i++) {
        cgcoins[scc[i]] += coins[i];
    }
    for (auto &x : edges) {
        int u = x[0];
        int v = x[1];
        if (scc[u] == scc[v]) {
            continue;
        }
        cg[scc[u]].push_back(scc[v]);
    }

    // to remove duplicate edges.
    for (int i = 1; i < comp; i++) {
        sort(cg[i].begin(), cg[i].end());
        cg[i].erase(unique(cg[i].begin(), cg[i].end()), cg[i].end());
    }
    dp.assign(comp + 3, 0);
    int ans = 0;
    for (int i = 1; i < comp; i++) {
        dp[i] = cgcoins[i];
        ans = max(ans, dp[i]);
    }
    for (int u = comp - 1; u >= 1; u--) {
        for (int &v : cg[u]) {
            dp[v] = max(dp[v], cgcoins[v] + dp[u]);
            ans = max(ans, dp[v]);
        }
    }
    cout << ans << "\n";

    return 0;
}