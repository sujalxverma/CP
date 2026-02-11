#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll INF = -1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll>> edges;
    vector<vector<ll>> graph(n + 1);
    vector<vector<ll>> reverse_graph(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    // -------- Bellman-Ford (maximum path version) --------
    vector<ll> d(n + 1, INF);
    d[1] = 0;

    for (ll i = 1; i < n; i++)
    {
        bool updated = false;
        for (auto [u, v, w] : edges)
        {
            if (d[u] != INF && d[u] + w > d[v])
            {
                d[v] = d[u] + w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    // -------- Detect nodes affected by positive cycle --------
    vector<bool> in_cycle(n + 1, false);

    for (auto [u, v, w] : edges)
    {
        if (d[u] != INF && d[u] + w > d[v])
        {
            in_cycle[v] = true;
        }
    }

    // -------- BFS from 1 (reachable from source) --------
    vector<bool> reach_from_1(n + 1, false);
    queue<ll> q;
    q.push(1);
    reach_from_1[1] = true;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (ll nxt : graph[node])
        {
            if (!reach_from_1[nxt])
            {
                reach_from_1[nxt] = true;
                q.push(nxt);
            }
        }
    }

    // -------- BFS from n on reversed graph (can reach n) --------
    vector<bool> reach_to_n(n + 1, false);
    q.push(n);
    reach_to_n[n] = true;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (ll nxt : reverse_graph[node])
        {
            if (!reach_to_n[nxt])
            {

                reach_to_n[nxt] = true;

                q.push(nxt);
            }
        }
    }

    // -------- Final check --------
    for (int i = 1; i <= n; i++)
    {
        if (in_cycle[i] && reach_from_1[i] && reach_to_n[i])
        {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << d[n] << "\n";
    return 0;
}
