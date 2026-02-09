#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> d(n + 1, inf);
    vector<char> v(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    parent[1] = 0;
    v[1] = 1;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node == n)
        {
            break;
        }
        for (auto neg : g[node])
        {
            if (v[neg] == 0)
            {
                v[neg] = 1;
                parent[neg] = node;
                d[neg] = d[node] + 1;
                q.push(neg);
            }
        }
    }

    if (d[n] == inf)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << d[n] + 1 << "\n";
        vector<int> ans;
        auto node = n;
        while (node != 0)
        {
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(), ans.end());
        for (auto &x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}