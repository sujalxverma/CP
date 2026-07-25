/*
Articulation Points, only for undirected graphs.
*/
#include "bits/stdc++.h"
using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;
vector<vector<int>> g;

int vis[MAXN];
int dis[MAXN];
int low[MAXN];
int isAP[MAXN];
int timer = 0;

void dfs(int u, int p = -1)
{

    vis[u] = 1;
    dis[u] = low[u] = ++timer;

    int children = 0;

    for (int v : g[u])
    {

        if (v == p)
            continue;

        if (!vis[v])
        {

            children++;

            dfs(v, u);

            low[u] = min(low[u], low[v]);

            // u is not root
            if (p != -1 && low[v] >= dis[u])
                isAP[u] = 1;
        }
        else
        {

            // back edge
            low[u] = min(low[u], dis[v]);
        }
    }

    // root of DFS tree
    if (p == -1 && children > 1)
        isAP[u] = 1;
}

int main()
{

    cin >> n;

    g.resize(n + 1);

    // read edges
    // g[u].push_back(v);
    // g[v].push_back(u);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    for (int i = 1; i <= n; i++)
        if (isAP[i])
            cout << i << " ";

    cout << "\n";
}