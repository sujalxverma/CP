#include "bits/stdc++.h"
using namespace std;
vector<int> kahn_sort(vector<vector<int>> &graph, vector<int> &incoming_edges)
{
    int n = graph.size();
    vector<int> indeg = incoming_edges;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> top_sort;

    for (int i = 1; i < n; i++)
    {
        if (indeg[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        top_sort.push_back(node);

        for (int neigh : graph[node])
        {
            indeg[neigh]--;
            if (indeg[neigh] == 0)
                pq.push(neigh);
        }
    }

    return top_sort;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> inc(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        inc[b]++;   // ✅ correct
    }

    vector<int> ans = kahn_sort(g, inc);

    if (ans.size() == n)
    {
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    else
    {
        cout << "Sandro fails.\n";
    }
    return 0;
}
