#include "bits/stdc++.h"
std::vector<std::vector<int>> g;
std::vector<int> dist;
std::pair<int, int> bfs(int node, int parent)
{
    std::queue<std::tuple<int, int, int>> q;
    q.push({node, parent, 0});
    int dia = node;
    int dist = 0;

    while (!q.empty())
    {
        auto [u, p, d] = q.front();
        q.pop();
        if (d > dist)
        {
            dia = u;
            dist = d;
        }
        for (auto v : g[u])
        {
            if (p != v)
            {
                q.push({v, u, d + 1});
            }
        }
    }

    return {dia, dist};
}

void dfs(int u, int p, int d)
{
    dist[u] = std::max(dist[u], d);
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u, d + 1);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    g.resize(n + 1);
    dist.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::pair<int, int> p1 = bfs(1, -1);
    std::pair<int, int> p2 = bfs(p1.first, -1);

    dfs(p1.first, -1, 0);
    dfs(p2.first, -1, 0);

    for (int i = 1; i <= n; i++)
    {
        std::cout << dist[i] << " ";
    }
    std::cout << "\n";

    return 0;
}