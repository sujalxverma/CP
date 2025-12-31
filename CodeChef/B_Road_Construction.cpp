#include "bits/stdc++.h"
using namespace std;
/*
1. Since, 0<=m<n/2 , at least one node  will be present, who have no problem with every other node.
2. Connect every node to it.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            // connect every node to this.
            cout << n - 1 << "\n";
            for (int j = 1; j <= n; j++)
            {
                if (j == i)
                    continue;
                cout << i << " " << j << "\n";
            }
            return 0;
        }
    }
    return 0;
}