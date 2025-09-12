#include "bits/stdc++.h"
using namespace std;
#define ll long long

bool check(ll i, ll m, vector<ll> &v)
{
    if (m == 0)
        return true;
    ll right = i + m;
    ll left = m - 1;

    if (v[left] + v[right] <= 2 * v[i])
        return true;
    else
        return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    vector<ll> pf(n, 0);
    pf[0] = v[0];
    for (ll i = 1; i < n; i++)
        pf[i] = pf[i - 1] + v[i];

    ll total = pf[n - 1];
    ll ans = total;

    for (ll i = 0; i < n; i++)
    {
        ll el = min(i, n - i - 1);
        ll l = 0, r = el;

        ll val;
        while (abs(l - r) > 1)
        {
            ll mid = (l + r) / 2;
            // cout << mid << endl;
            if (!check(i, mid, v))
                r = mid;
            else
                l = mid;
        }
        // cout << r << endl;
        if (check(i, r, v))
            val = r;
        else
            val = l;

        ll cur = 0;
        if (val - 1 >= 0)
            cur += pf[val - 1];
        cur += pf[i + val] - pf[i];

        cur = (2 * val) * v[i] - cur;
        ans = max(ans, cur + total);
    }
    cout << ans << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
