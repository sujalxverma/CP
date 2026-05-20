#include "bits/stdc++.h"
using namespace std;
const int maxN = 1e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<set<int>> cnt(maxN + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v])
            continue;
        cnt[c[u]].insert(c[v]);
        cnt[c[v]].insert(c[u]);
    }
    int ans = -1e9;
    int color = 0;
    for (int i = 1; i <= maxN; i++) {
        if ((int)cnt[i].size() > ans) {
            color = i;
            ans = (int)cnt[i].size();
        }
    }
    cout << color << "\n";
    return 0;
}