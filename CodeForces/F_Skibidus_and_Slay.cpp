#include "bits/stdc++.h"
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int> ans(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v]) {
            ans[c[u]] = 1;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // all [k,k] checked, now have to check for [k,0,k]

    for (int u = 1; u <= n; u++) {
        // [k , 0 , k] -> u is with color 0.
        // considering i to be the center.
        map<int, int> mp;
        for (int &v : g[u]) {
            mp[c[v]]++;
            if (mp[c[v]] >= 2) {
                ans[c[v]] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}