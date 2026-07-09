#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, k;
vector<vector<int>> dp1, dp2;

vector<vector<int>> tree;
vector<int> dist;

void dfs1(int u, int p) {
    dp1[u][0] = 1;
    for (int &v : tree[u]) {
        if (p == v)
            continue;
        dfs1(v, u);
    }
    for (int x = 1; x <= k; x++) {
        for (int &v : tree[u]) {
            if (p == v)
                continue;
            dp1[u][x] = (dp1[u][x] + dp1[v][x - 1]);
        }
    }
}

void dfs2(int u, int p) {
    dp2[u][0] = 1;
    for (int i = 1; i <= k; i++) {
        dp2[u][i] = dp1[u][i];
    }

    if (p != -1) { // if p == -1, then u is root.
        dp2[u][1] += dp2[p][0];
        for (int i = 2; i <= k; i++) {
            dp2[u][i] = (dp2[u][i] + dp2[p][i - 1] - dp1[u][i - 2]);
        }
    }
    for (int &v : tree[u]) {
        if (p == v) {
            continue;
        }
        dfs2(v, u);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    tree.resize(n + 1);
    dist.resize(n + 1, 0);
    dp1.resize(n + 1, vector<int>(k + 1, 0));
    dp2.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp2[i][k];
    }

    cout << ans / 2 << "\n";
    return 0;
}