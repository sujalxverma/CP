#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() == 1)
    {
        cout << v + min(u,v) << "\n";
        return;
    }
    int pos = a[0];
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - pos) > 1)
        {
            cout << 0 << "\n";
            return;
        }
        else
        {
            pos = a[i];
            if (pos == 0)
            {
                cout << min(u, v) << "\n";
                return;
            }
        }
    }
    pos = a[0];
    for (int i = 1; i < n; i++)
    {
        if (pos != a[i])
        {
            cout << min(u, v) << "\n";
            return;
        }
        else
        {
            pos = a[i];
        }
    }
    cout << u + v << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}