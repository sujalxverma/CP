#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int z = 0;
    int o = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            z++;
        }
        else
        {
            o++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (z > 0)
        {
            z--;
            ans += o;
        }
        else
        {
            o--;
            ans += o;
        }
    }
    cout << ans << "\n";
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