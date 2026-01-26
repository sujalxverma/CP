#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // precompute();

    for (ll i = 1; i <= n; i++)
    {
        ll deg = g[i].size();
        // C(n, n - 1 - deg) == C(n, deg + 1)
        ll num = n - 1 - deg;
        cout << num * (num - 1) * (num - 2) / 6 << " ";
    }
    cout << "\n";

    return 0;
}
