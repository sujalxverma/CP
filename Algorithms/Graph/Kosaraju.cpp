/*
 * Kosaraju algo is used to find SCCs, and also the condensed graphs, which will
 * definitely be DAG, and we can use toposort and DP on it.
 * TC : O(E+V)
 */

int n, m;               // number of nodes and edges.
vector<vector<int>> g;  // original graph.
vector<vector<int>> rg; // transpose graph.
vector<int> order;      // order of nodes as per finished time.
vector<int> vis;        // visited array.
vector<int> ids;        // SCC ids.
vector<vector<int>> cg; // condensed graph

void dfs(int u)
{ // first dfs call on g.
    vis[u] = 1;
    for (int &v : g[u])
    {
        if (vis[v] == 1)
            continue;
        dfs(v);
    }
    order.push_back(u);
}
void dfs2(int u, int id)
{ // second dfs call on rg.
    vis[u] = 1;
    ids[u] = id;
    for (int &v : rg[u])
    {
        if (vis[v] == 1)
            continue;
        dfs2(v, id);
    }
}

void Kosaraju()
{
    cin >> n >> m;
    g.resize(n + 1);
    cg.resize(n + 1);
    ids.resize(n + 1);
    rg.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
    vis.assign(n + 1, 0);
    reverse(begin(order), end(order));
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        int u = order[i];
        if (vis[u] == 0)
        {
            dfs2(u, u);
            cnt++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int &j : g[i])
        {
            if (ids[j] != ids[i])
            {
                cg[ids[i]].push_back(ids[j]);
            }
        }
    }
}