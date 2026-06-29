#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*
if u is white, then v can be black or white, thus we have choice.
if v is black, then v must be white, no choice.

Now, but why  dp[u][0] = (dp[u][0] % mod * dp[v][1] % mod) % mod;
why multiply,
say node u has child v and w.
u -> {1,2} = 2 ways, v -> {3,4,5} = 3 ways.
both child are indepent of one another.
thus choices -> {1,3},{1,4},{1,5},{2,3},{2,4},{2,5} -> 2 x 3 = 6 ways.

Now,but why ->  dp[u][1] = (dp[u][1] % mod * (dp[v][0] % mod + dp[v][1] % mod) % mod) % mod;
if u is white, then v can be white or black, these are two alternate path, either choose this or that, thus we add.

*/
int n;
vector<vector<int>> g;
vector<vector<int>> dp;
void dfs(int u, int p) {
    if (g[u].size() == 1) {
        // leaf node.
        dp[u][0] = 1;
        dp[u][1] = 1;
        return;
    }
    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        // must be white.
        dp[u][0] = (dp[u][0] % mod * dp[v][1] % mod) % mod;
        // either can do black or white.
        dp[u][1] = (dp[u][1] % mod * (dp[v][0] % mod + dp[v][1] % mod) % mod) % mod;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << "2\n";
        return 0;
    }
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[1].push_back(-1); // fail safe, if 1 has only 1 child, with many child still works.
    dp.resize(n + 1, vector<int>(2, 1));
    // dp[i][0] -> number of ways to color node i black, dp[i][1]->color white
    dfs(1, -1);
    int ans = (dp[1][0] % mod + dp[1][1] % mod) % mod; // either black or white
    cout << ans << "\n";
    return 0;
}