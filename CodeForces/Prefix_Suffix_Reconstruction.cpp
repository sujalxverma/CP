#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n);
    for (auto &x : f)
    {
        cin >> x;
    }
    if (n == 2)
    {
    }

    bool ft = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (f[i] == 0)
        {
            continue;
        }
        else if (f[i] == 1)
        {
            ft = true;
            break;
        }
        else
        {
            break;
        }
    }
    if (ft)
    {
        cout << "-1\n";
        return;
    }
    vector<int> a(n, 0);

    int maxP = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (f[i] == 0)
        {
            continue;
        }
        else
        {
            a[maxP - f[i]] = i + 1;
            maxP = maxP - f[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
        }
    }
    for (auto x : a)
    {
        cout << x << " ";
    }

    cout << "\n";
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