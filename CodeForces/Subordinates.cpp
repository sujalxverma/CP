#include "bits/stdc++.h"
using namespace std;
vector<int> ans;
vector<vector<int>> g;
vector<int> v;
void dfs(int node)
{

    v[node] = 1;
    if (g[node].size() == 0)
    {
        return;
    }
    for (auto neg : g[node])
    {
        if (v[neg] == -1)
        {
            dfs(neg);

            ans[node] += 1 + ans[neg]; // it means ans[neg] + neg itself, i.e why : (1 + ans[neg])
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n + 1);
    v.assign(n + 1, -1);
    ans.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int k;
        cin >> k;
        g[k].push_back(i);
    }
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}