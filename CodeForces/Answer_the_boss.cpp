#include "bits/stdc++.h"
using namespace std;

/*
1. We used rank[] to tell the rank of this neigbor : rank[neig] = max(rank[neig] , rank[node]+1)

*/

vector<vector<int>> kahn_sort(vector<vector<int>> &graph, vector<int> &incoming_edges)
{
    int n = graph.size();
    vector<int> indeg = incoming_edges;
    queue<int> pq;

    vector<int> rank(n, 1);
    vector<vector<int>> top_sort(n + 1);

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int node = pq.front();
        pq.pop();

        top_sort[rank[node]].push_back(node);

        for (int neigh : graph[node])
        {
            rank[neigh] = max(rank[neigh], rank[node] + 1);
            if (--indeg[neigh] == 0)
                pq.push(neigh);
        }
    }

    return top_sort;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int z = 1;
    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n);
        vector<int> inc(n, 0);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[b].push_back(a);
            inc[a]++;
        }

        vector<vector<int>> ans = kahn_sort(g, inc);
        cout << "Scenario #" << z << ":" << "\n";
        z++;

        for (int i = 1; i <= n; i++)
        {
            if (ans[i].empty())
                continue;

            sort(ans[i].begin(), ans[i].end());
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << i << " " << ans[i][j] << "\n";
            }
        }
    }
    return 0;
}
