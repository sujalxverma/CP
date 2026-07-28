/*
 * 2SAT problem.
 * make implication graph.
 * Do correct assignment.
 */
// CSES : GIANT PIZZA
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MAXN = 1e5;
const int NUM = 2 * MAXN + 10;
int n, m;
vector<vector<int>> g;
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    n = N;
    m = M;
    // m -> toppings, n -> members
    g.resize(2 * MAXN + 10);
    cg.resize(2 * MAXN + 10);
    ids.resize(2 * MAXN + 10);
    rg.resize(2 * MAXN + 10);
    vis.assign(2 * MAXN + 10, 0);
    char a, b;
    int u, v;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> u >> b >> v;

        auto add_edge = [&](int x, int y)
        {
            g[x].push_back(y);
            rg[y].push_back(x);
        };

        if (a == '+')
        {
            if (b == '+')
            { // u ∨ v : !u -> v, !v -> u
                add_edge(MAXN + u, v);
                add_edge(MAXN + v, u);
            }
            else
            { // u ∨ !v : !u -> !v, v -> u
                add_edge(MAXN + u, MAXN + v);
                add_edge(v, u);
            }
        }
        else
        {
            if (b == '+')
            { // !u ∨ v : u -> v, !v -> !u
                add_edge(u, v);
                add_edge(MAXN + v, MAXN + u);
            }
            else
            { // !u ∨ !v : u -> !v, v -> !u
                add_edge(u, MAXN + v);
                add_edge(v, MAXN + u);
            }
        }
    }

    for (int i = 1; i < NUM; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
    vis.assign(NUM, 0);
    reverse(begin(order), end(order));
    int cnt = 0;
    for (int i = 0; i < (int)order.size(); i++)
    {
        int u = order[i];
        if (vis[u] == 0)
        {
            dfs2(u, cnt);
            cnt++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (ids[i] == ids[i + MAXN])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (ids[i] < ids[MAXN + i])
        {
            cout << "- ";
        }
        else
        {
            cout << "+ ";
        }
    }
    cout << "\n";
    return 0;
}