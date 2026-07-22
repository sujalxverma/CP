#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 1e9;
const int mod = 1e9 + 7;
int n, m;
vector<vector<int>> g;
vector<int> coins;
vector<int> scc;
vector<int> low, disc;
vector<int> onstack;
stack<int> st;
int timer = 1;
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
    cin >> n;
    coins.assign(n + 1, 0);
    scc.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    low.assign(n + 1, inf);
    disc.assign(n + 1, inf);
    onstack.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (disc[i] == inf) {
            tarjan(i);
        }
    }

    vector<array<int, 2>> p(comp + 1, {inf, 0});
    for (int i = 1; i <= n; i++) {
        int c = scc[i];
        int v = coins[i];

        if (p[c][0] == v) {
            p[c][1]++;
        } else if (p[c][0] > v) {
            p[c][0] = v;
            p[c][1] = 1;
        }
    }
    int sum = 0;
    int ways = 1;
    for (int i = 1; i <= comp - 1; i++) {
        sum = (sum + p[i][0]);
        ways = (ways % mod * p[i][1] % mod) % mod;
    }
    cout << sum << " " << ways << "\n";

    return 0;
}