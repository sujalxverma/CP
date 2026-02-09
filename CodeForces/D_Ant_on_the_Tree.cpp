#include "bits/stdc++.h"
using namespace std;

/*
1. First we create adjacency list for graph.
2. Since my path is of type: 1 , k1 , k2 ,... kn , 1.
4. And total nodes in this path should be (2n-1), if its not, then return -1.
5. Now to construct the ans.
6. We simply use dfs in this fashion.
   k1 to 1,
   k2 to k1,
   ...
   1 to kn.
7. For each path from u to v, we traversed reverse, so as not to reverse ans array.
8. Since its a tree, we only need parent variable, no need for visited array.
9. Look at the code again, and you will understand it.
*/

int n, u, v;
vector<vector<int>> g;
vector<int> ans;
bool dfs(int node, int target, int parent)
{
    if (node == target)
    {
        return 1;
    }

    for (auto &neg : g[node])
    {
        if (neg != parent && dfs(neg, target, node))
        {
            ans.push_back(node);
            return 1;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
       
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans.push_back(1);
    u = 1;
    while (cin >> v)
    {
        dfs(v, u, 0);
        u = v;
    }
    dfs(1, u, 0);
    if ((int)ans.size() != 2 * n - 1)
    {
        cout << "-1\n";
        return 0;
    }
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}