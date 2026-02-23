#include "bits/stdc++.h"
using namespace std;
vector<int> a;
int n;

/*
If one operation 1, all elements are not equal, ie. 0, then no future operation can.
*/

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> b = a;
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                s.insert(b[j] + a[i]);
            }
            else
            {
                s.insert(b[j] - a[i]);
            }
        }
        if (s.size() == 1)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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