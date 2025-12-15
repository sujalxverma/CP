#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;
    int m = n-1;
    vector<set<int>> x(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);

        x[a].insert(b);
        x[b].insert(a);
    }

    vector<int> color(n + 1, -1); // -1 = unvisited, 0/1 = teams
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            q.push(i);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int v : g[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = !color[u];
                        q.push(v);
                    }
                    // else if (color[v] == color[u])
                    // {
                    //     cout << "IMPOSSIBLE\n";
                    //     return 0;
                    // }
                }
            }
        }
    }

    vector<set<int>> v(2);
    for (int i = 1; i <= n; i++)
    {
        v[color[i]].insert(i);
    }
    ll count = 0;
    for (auto y : v[0])
    {

        
        count += 1LL*(v[1].size() - x[y].size());
    }

    cout<<count<<"\n";
    return 0;
}
