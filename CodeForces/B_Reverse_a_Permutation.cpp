#include "bits/stdc++.h"
using namespace std;
vector<int> a;

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = -1;
    int r = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == n - i)
        {
            continue; ;
        }
        else
        {
             l = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == n - i)
                {
                    r = j;
                    reverse(a.begin() + l, a.begin() + r + 1);
                    for (int i = 0; i < n; i++)
                    {
                        cout << a[i] << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
    if (l == -1 && r == -1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return;
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