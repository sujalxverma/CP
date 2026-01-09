#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
// the mental shift from node-based paths to state-based paths
int djikstra(vector<vector<int>> &g, vector<int> &ans, set<array<int, 3>> &forbidden)
{

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>>
        pq; // {dist , current , parent}
    // source = 1. dest = n
    int n = g.size() - 1;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, inf)); // {parent,curent} = distance.

    vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(n + 1, {-1, -1})); // {current , next}
    // To reach node c with previous node p, we came from state
    // (parent[p][c].first , parent[p][c].second)
    d[0][1] = 0; // starting, to reach S from 0 is 0.
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        auto [dist, node, papa] = pq.top();
        pq.pop();

        if (d[papa][node] < dist)
            continue; // latest d[node] check.

        for (auto next : g[node])
        {
            if (forbidden.count({papa, node, next}))
            {
                // this path is forbidden.
                continue; // skip
            }
            else
            {
                if (d[papa][node] + 1 < d[node][next])
                {
                    parent[node][next] = {papa, node}; // jinse aaye the, ab wo parent ban gaye.
                    d[node][next] = 1 + d[papa][node];
                    pq.push({d[node][next], next, node});
                }
            }
        }
    }

    pair<int, int> best = {-1, -1};
    int bestDist = inf;
    int D = n;
    for (int p = 0; p <= n; p++)
    {
        if (d[p][D] < bestDist)
        {
            bestDist = d[p][D];
            best = {p, D};
        }
    }

    if (bestDist == inf)
    {
        // no path exist.
        return 0;
    }

    // path reconstruction

    auto cur = best;

    while (!(cur.first == 0 && cur.second == 1))
    {
        ans.push_back(cur.second);
        cur = parent[cur.first][cur.second];
    }

    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1); // 1 based
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    set<array<int, 3>> forbidden;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden.insert({a, b, c});
    }
    vector<int> ans;

    int check = djikstra(g, ans, forbidden);
    if (check == 0)
    {
        cout << "-1\n";
        return 0;
    }
    cout << (int)ans.size() - 1 << "\n";
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}