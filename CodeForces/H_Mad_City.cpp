#include "bits/stdc++.h"
using namespace std;

/*
As per problem.
1. If G(N,E) : N - 1 == E, then its a tree.
2. But N == E, and no double edges and self loop, and it is one component only, then
   it means graph has 1 cylce.
3. If V can reach cyclic nodes before M, then Yes, else NO.
*/

vector<vector<int>> g;
vector<int> cycle;
vector<int> path; // 1 -> visiting , 0 -> unvisited , 2 - > visited
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int p)
{
    path[u] = 1;
    parent[u] = p;

    for (int v : g[u])
    {
        if (v == p)
            continue;

        if (path[v] == 0)
        {
            if (dfs(v, u))
                return true;
        }
        else if (path[v] == 1)
        {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }

    path[u] = 2;
    return false;
}

void bfs(vector<int> &d, int start)
{
    queue<pair<int, int>> q;
    d[start] = 0;
    q.push({start, 0});

    while (!q.empty())
    {
        auto [node, dist] = q.front();
        q.pop();

        for (auto &v : g[node])
        {
            if (dist + 1 < d[v])
            {
                d[v] = dist + 1;
                q.push({v, d[v]});
            }
        }
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    g.assign(n + 1, {});

    path.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    parent.assign(n + 1, -1);

    if (dfs(1, -1))
    {
        cycle.assign(n + 1, 0);

        cycle[cycle_start] = 1;
        for (int v = cycle_end; v != cycle_start; v = parent[v])
        {
            cycle[v] = 1;
        }
    }

    vector<int> cyclicNodes;

    for (int i = 1; i <= n; i++)
    {
        if (cycle[i])
        {
            cyclicNodes.push_back(i);
        }
    }

    // now have to use BFS(unit weighted) to find shortest distance from nodes M and V, to all cyclic nodes.
    vector<int> dist_M(n + 1, 1e9);
    vector<int> dist_V(n + 1, 1e9);
    bfs(dist_M, a);
    bfs(dist_V, b);

    for (auto &x : cyclicNodes)
    {
        if (dist_M[x] > dist_V[x])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}