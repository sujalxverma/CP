#include "bits/stdc++.h"
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &v, vector<int> &output, vector<int> &colors, int node)
{

    v[node] = 1;
    output.push_back(node);
    for (auto n : g[node])
    {
        if (v[n] == 0 && colors[n] == colors[node])
        {

            dfs(g, v, output, colors, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> colors(n + 1);
    int b = 0;
    int w = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> colors[i];
        if (colors[i] == 0)
        {
            w++;
        }
        else
        {
            b++;
        }
    }

    vector<vector<int>> g(n + 1); // 1 based indexing.

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        g[a].push_back(b);
    }

    if (b == n || w == n)
    {
        cout << "0\n";
        return 0;
    }
    vector<vector<vector<int>>> d(2);
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            // run dfs.
            vector<int> output;
            dfs(g, v, output, colors, i);
            d[colors[i]].push_back(output);
            output.clear();
        }
    }

    if (d[0].size() >= d[1].size())
    {
        cout << d[1].size() << "\n";
    }
    else
    {
        cout << d[0].size() << "\n";
    }
    // for(auto x : d){
    //     for(auto y : x){
    //         for(auto z : y){
    //             cout<<z<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    //     cout<<"\n";
    // }

    return 0;
}