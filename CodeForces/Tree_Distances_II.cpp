#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<vector<ll>> g;
vector<ll> subtree;
vector<ll> sum;
vector<ll> ans;
ll n;

// only for finding sum for root 1.
void dfsDown(ll u, ll p)
{
    subtree[u] = 1;
    sum[u] = 0;
    for (auto &v : g[u])
    {

        if (v != p)
        {
            dfsDown(v, u);
            subtree[u] += subtree[v];
            sum[u] += sum[v] + subtree[v];
        }
    }
}

void dfsUP(ll u, ll p, ll total)
{
    ans[u] = total;
    for (auto &v : g[u])
    {
        if (v != p)
        {
            dfsUP(v, u, total - subtree[v] + (n - subtree[v]));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n + 1);
    ans.resize(n + 1);
    subtree.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsDown(1, -1);
    dfsUP(1, -1, sum[1]);
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}