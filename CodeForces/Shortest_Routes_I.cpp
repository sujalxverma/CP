#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
       
    }

   priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>
> pq;

    vector<ll> d(n + 1, 1e18);
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [dist, u] = pq.top();
        pq.pop();

        if (d[u] < dist)
            continue;

        for (auto &[v, w] : g[u])
        {

            if (w + d[u] < d[v])
            {
                d[v] = w + d[u];
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (d[i] == 1e18 ? -1 : d[i]) << " ";
    }
    cout << "\n";
    return 0;
}