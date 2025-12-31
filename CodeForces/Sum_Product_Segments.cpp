#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    for (ll i = 1; i * i <= y; i++)
    {
        if (y % i != 0)
            continue;
        ll s = i;
        ll e = (y / s);

        if (x - (s - 1) < (s - 1) && x - (s - 1) >= 0)
        {
            cout << x - (s - 1) << " " << s - 1 << "\n";
            cout << s << " " << e << "\n";
            return;
        }
        else if ((x - (e + 1) > e && (x - (e + 1)) > e + 1))
        {
            cout << e + 1 << " " << x - (e + 1) << "\n";
            cout << s << " " << e << "\n";

            return;
        }
    }
    cout << "-1\n";
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