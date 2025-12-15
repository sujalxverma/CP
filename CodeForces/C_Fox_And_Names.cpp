#include "bits/stdc++.h"
using namespace std;

/*
1. Make graph of strings characters as we do in alien dictionary.
2. if s1 > s2 , and s2 is prefix of s1, then impossible,
3. if s1 -- s2, no problem, go ahead.
4. use khan sort from 0 to 25.
*/


vector<int> kahn_sort(vector<vector<int>> &graph, vector<int> &incoming_edges)
{
    int n = graph.size();
    vector<int> indeg = incoming_edges;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> top_sort;

    for (int i = 0; i < n; i++)
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
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }

    vector<vector<int>> g(26);
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = a[i];
        string s2 = a[i + 1];

        int j = 0;
        int k = 0;
        while (j < s1.length() && k < s2.length())
        {
            if (s1[j] != s2[k])
            {
                g[s1[j] - 'a'].push_back(s2[k] - 'a');
                break;
            }
            k++;
            j++;
        }
        if (j == s2.length() && j < s1.length())
        {
            cout << "Impossible" << "\n";
            return 0;
        }
    }

    vector<int> e(26, 0);
    for (auto x : g)
    {
        for (auto y : x)
        {
            e[y]++;
        }
    }
    vector<int> ans = kahn_sort(g, e);
    if(ans.size() < 26){
        cout << "Impossible" << "\n";
            return 0;
    }
    // cout<<ans.size()<<"\n";
    for (auto x : ans)
    {
        cout << char(x+'a') << "";
    }
    cout<<"\n";

    return 0;
}