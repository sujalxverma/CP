#include <iostream>
#include <vector>
using namespace std;
#define int long long
int n;
vector<vector<int>> tree;
vector<vector<int>> dp;
// dp[i][0] -> take node, dp[i][1] -> do not take node.

void dfs(int u, int p) {
    if (tree[u].size() == 0) { // leaf node
        dp[u][0] = 0;
        dp[u][1] = 0;
        return;
    }

    for (int &v : tree[u]) {
        if (p == v)
            continue;
        dfs(v, u);
        dp[u][1] += max(dp[v][0], dp[v][1]);
        // dp[u][1] -> do not take node u.
        // now i can either take child's best ans.
        // either inlude child or not.
    }

    // dp[u][1] -> means total edges in subtree of u, if node u is not taken.

    for (int &v : tree[u]) {
        if (p == v)
            continue;
        // now i have to decide with edge to take, so that node u is part of.
        // but talk, is that i can only take one child edge of u, otherwise say,
        // if i take two edges, then in the matching set, then u comes two times.
        dp[u][0] = max(dp[u][0], (dp[u][1] - max(dp[v][1], dp[v][0])) + (1 + dp[v][1]));
        // max(dp[u][0] , take edge u->v)
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.resize(n + 1);
    dp.resize(n + 1, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}