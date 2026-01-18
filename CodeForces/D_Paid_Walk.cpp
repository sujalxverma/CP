#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll n, m, x, mini, maxi;
void dfs(vector<vector<pair<ll, ll>>> &g, ll node, vector<ll> &ans, ll level, ll cost)
{
    if (level > x)
    {
        return;
    }
    if (level == x)
    {
        if (cost >= mini && cost <= maxi)
        {
            ans.push_back(node);
            return;
        }
    }

    for (auto neg : g[node])
    {
        dfs(g, neg.first, ans, level + 1, cost + neg.second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> mini >> maxi;

    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<ll> ans;
    dfs(g, 1, ans, 0, 0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(begin(ans), end(ans)), ans.end());
    for (auto &x : ans)
    {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}