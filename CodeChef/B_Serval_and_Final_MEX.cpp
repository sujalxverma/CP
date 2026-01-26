#include "bits/stdc++.h"
using namespace std;
vector<int> a;

void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    int z = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            z++;
    }
    // if 0 is absent then, only in 1 step.
    if (z == 0)
    {
        cout << "1\n";
        cout << 1 << " " << n << "\n";
        return;
    }

    if (z == n)
    {
        cout << "3\n";
        cout << (n + 1) / 2 + 1 << " " << n << "\n";
        cout << 1 << " " << (n + 1) / 2 << "\n";
        cout << "1 2\n";
        return;
    }

    
    
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