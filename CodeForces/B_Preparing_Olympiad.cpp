#include "bits/stdc++.h"
using namespace std;
using ll = long long;
/*
Complete search on every subset possible. 1<<n
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    ll ans = 0;

    for (ll i = 1; i < (1LL << n); i++)
    {

        int count = 0;
        ll sum = 0;
        ll maxi = -1e18;
        ll mini = 1e18;
        for (int j = 0; j < n; j++)
        {
            if ((1LL << j) & i)
            {
                count++;
                sum += a[j];
                maxi = max(maxi, a[j]);
                mini = min(mini, a[j]);
            }
        }

        if (count >= 2)
        {
            if (sum >= l && sum <= r)
            {
                if (maxi - mini >= x)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}