// #include "bits/stdc++.h"
// using namespace std;

// vector<int> kahn_sort(vector<vector<int>> &graph, vector<int> &incoming_edges)
// {
//     int n = graph.size();
//     vector<int> indeg = incoming_edges;
//    queue<int>pq;
//     vector<int> top_sort;

//     for (int i = 1; i < n; i++)
//     {
//         if (indeg[i] == 0)
//             pq.push(i);
//     }

//     while (!pq.empty())
//     {
//         int node = pq.front();
//         pq.pop();
//         top_sort.push_back(node);

//         for (int neigh : graph[node])
//         {
//             indeg[neigh]--;
//             if (indeg[neigh] == 0)
//                 pq.push(neigh);
//         }
//     }

//     return top_sort;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>>g(n+1);
//     vector<int>ind(n+1,0);
//     for(int i = 0; i < m ; i++){
//         int a,b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         ind[b]++;
//     }
//     vector<int>ans = kahn_sort(g,ind);

//     if(ans.size() != n)
//     {cout<<"No\n";
//         return 0;
//     }
//     map<int,int>mp;
//     for(int i = 0 ; i < ans.size() ; i++){
//         mp[ans[i]] = i+1;
//     }
//     cout<<"Yes\n";
//     for(int i = 1 ; i <= n ; i++){
//         cout<<mp[i]<<" ";
//     }
//     cout<<"\n";

//     return 0;
// }

#include "bits/stdc++.h"
using namespace std;

/*
1. We used rank[] to tell the rank of this neigbor : rank[neig] = max(rank[neig] , rank[node]+1)

*/

vector<vector<int>> kahn_sort(vector<set<int>> &graph, vector<int> &incoming_edges)
{
    int n = graph.size();
    vector<int> indeg = incoming_edges;
    queue<int> pq;

    vector<int> rank(n, 1);
    vector<vector<int>> top_sort(n);

    for (int i = 1; i <= n-1; i++)
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
    int t = 1;
    // cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<set<int>> g(n + 1);
        vector<int> inc(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (g[a].find(b) == g[a].end())
            {
                g[a].insert(b);
                inc[b]++;
            }
        }

        vector<vector<int>> ans = kahn_sort(g, inc);

        for (int i = 1; i <= n; i++)
        {
            if (ans[i].size() != 1)
            {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {

            mp[ans[i][0]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << mp[i] << " ";
        }
    }
    return 0;
}
