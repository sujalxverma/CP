#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> p(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            ll k;
            cin >> k;
            p[i] = k + p[i - 1];
        }

        ll s = 1;
        ll e = n;
        ll ans = 0;

        while (s <= e)
        {
            ll m = s + (e - s) / 2;
            cout << "? " << (m-s+1) << " ";
            for (ll i = s; i <= m; i++)
            {
                cout << i << " ";
            }
            cout << "\n";
            cout.flush();

            ll x = 0;
            cin >> x;

            if (x == (p[m] - p[s - 1]))
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
                ans = m;
            }
        }

        cout << "! " << ans << "\n";
        cout.flush();
    }

    return 0;
}