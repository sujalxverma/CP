#include "bits/stdc++.h"
using namespace std;
const long long inf = 1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> g(n + 1, vector<long long>(n + 1, inf));

    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    for (int i = 0; i <= n; i++)
    {
        g[i][i] = 0;
    }
    vector<pair<long long, long long>> p;
    for (long long i = 0; i < q; i++)
    {
        long long u, v;
        cin >> u >> v;
        p.push_back({u, v});
    }
    for (long long k = 1; k <= n; k++)
    {
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= n; j++)
            {

                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (auto &[x, y] : p)
    {
        cout << (g[x][y] == inf ? -1 : g[x][y]) << "\n";
    }
    return 0;
}
