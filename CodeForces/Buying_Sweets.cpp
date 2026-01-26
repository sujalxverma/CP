#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<pair<ll, ll>> a;

/*
Imp : Cashback < Cost
1. To maximise the number of sweets. We need to select those sweets.
2. Whose cost <= x and which leads to minium decrease in x.
3. This can be done by sorting in ascending order in terms of (cost - cashback)
4. And simply iterate over it. 
5. Why the fcuk, i was doing DP in this. Damn.
*/


bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    ll d1 = a.first - a.second;
    ll d2 = b.first - b.second;

    if (d1 != d2)
        return d1 < d2;       // primary: smaller (cost - cashback)
    return a.first < b.first; // tie-break: smaller cost
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x;
        cin >> x;
        a.resize(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a.begin(), a.begin() + n, cmp);
        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            if (a[i].first > x)
            {
                continue;
            }
            ll k = (x - a[i].first) / (a[i].first - a[i].second) + 1;
            ans += k;
            x = x - (k * (a[i].first - a[i].second));
        }
        cout << ans << "\n";
    }
    return 0;
}