#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // check for bus
    bool f1 = false;
    bool f2 = false;
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1 && f1 == true)
        {
            f2 = true;
        }
        else if (g[i].size() == 1 && f1 == false)
        {
            f1 = true;
        }
        else if (g[i].size() == 2)
        {
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        if (f1 && f2)
        {
            cout << "bus topology" << "\n";
            return 0;
        }
    }
    // check for ring
    f = true;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() != 2)
        {
            f = false;
            break;
        }
    }

    if (f)
    {
        cout << "ring topology\n";
        return 0;
    }
    // check for star
    f = false;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == n - 1 && f != true)
        {
            f = true;
        }
        else if (g[i].size() == 1)
        {
        }
        else
        {
            cout << "unknown topology\n";
            return 0;
        }
    }
    if (f == true)
    {
        cout << "star topology\n";
    }

    return 0;
}