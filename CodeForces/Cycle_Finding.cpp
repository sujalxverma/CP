#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    // sort(begin(edges) , end(edges));

    vector<ll> d(n + 1, 0); // important change
    vector<ll> parent(n + 1);

    ll x = -1;

    // Bellman-Ford
    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto [u, v, w] : edges)
        {
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }
    for (ll i = 0; i < m; i++)
    {
        auto [u, v, w] = edges[i];
        if (d[u] != 1e18 && d[u] + w < d[v])
        {
            d[v] = d[u] + w;
            parent[v] = u;
            x = v;
        }
    }

    if (x == -1)
    {
        cout << "NO\n";
        return 0;
    }
    for (ll i = 0; i < n; i++)
    {
        x = parent[x];
    }
    cout<<"YES\n";
    // now x points to start of a cycle.
    vector<ll> cycles;
    cycles.push_back(x);
    x = parent[x];
    while (x != cycles[0])
    {
        cycles.push_back(x);
        x = parent[x];
    }
    cycles.push_back(x);
    reverse(begin(cycles), end(cycles));
    for (auto &X : cycles)
    {
        cout << X << " ";
    }
    cout << "\n";
}
