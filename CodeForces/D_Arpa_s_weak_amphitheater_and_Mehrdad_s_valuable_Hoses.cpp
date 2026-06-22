#include <iostream>
#include <vector>
using namespace std;
#define int long long
int n, m, W;
vector<vector<int>> dp;
vector<vector<int>> g;
vector<int> vis;
vector<vector<pair<int, int>>> sets;
vector<int> w, b;

void dfs(int u, vector<pair<int, int>> &p) {
    p.push_back({w[u], b[u]});
    for (auto &v : g[u]) {
        if (vis[v] == 0) {
            vis[v] = 1;
            dfs(v, p);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> W;
    g.resize(n + 5);
    vis.resize(n + 5, 0);
    w.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1)
            continue;
        vector<pair<int, int>> p;
        vis[i] = 1;
        dfs(i, p);
        int totalW = 0;
        int totalV = 0;
        for (auto &[x, y] : p) {
            totalV += y;
            totalW += x;
        }
        p.push_back({totalW, totalV});
        sets.push_back(p);
    }
    // we got components, and also the Combine weight,value of the components
    dp.resize((int)sets.size() + 5, vector<int>(W + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < (int)sets.size(); i++) {
        for (int j = 0; j <= W; j++) {
            dp[i + 1][j] = dp[i][j];
            for (int k = 0; k < (int)sets[i].size(); k++) {
                if (sets[i][k].first <= j) {
                    dp[i + 1][j] = max(dp[i + 1][j], sets[i][k].second + dp[i][j - sets[i][k].first]);
                }
            }
        }
    }

    cout << dp[(int)sets.size()][W] << "\n";
    return 0;
}