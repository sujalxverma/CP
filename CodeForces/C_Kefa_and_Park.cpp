#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> g;
vector<int> cats;
int n, m, ans;
void dfs(int node, int cat, int parent)
{
    cat = (cats[node] == 1 ? cat + 1 : 0);
    if (cat > m)
        return;
    for (auto child : g[node])
    {
        if (child == parent)
            continue;
        dfs(child, cat, node);
    }
    if (node != 1 && g[node].size() == 1)
    {
        ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n + 1);
    cats.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cats[i];
    for (int i = 0; i < n - 1; i++)
    {
        // make it directed
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, -1);
    cout << ans << "\n";

    return 0;
}