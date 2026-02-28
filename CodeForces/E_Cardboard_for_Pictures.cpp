#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll c;
    cin >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll s = 0;
    ll e = 1e18;

    while (s <= e)
    {
        ll mid = s + (e - s) / 2;

        __int128 sum = 0;

        for (int i = 0; i < n; i++)
        {
            __int128 val = (__int128)2 * mid + a[i];
            sum += val * val;

            if (sum > c)
                break; // early stop (important optimization)
        }

        if (sum == c)
        {
            cout << mid << "\n";
            return;
        }
        if (sum < c)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << "0\n";
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