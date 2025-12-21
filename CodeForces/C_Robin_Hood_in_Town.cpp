#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool f(const vector<ll> &a, ll mid, ll s)
{
    int n = a.size();
    int c = 0;

    for (int i = 0; i < n - 1; i++)
    { // exclude richest
        if (2LL * n * a[i] < s + mid)
            c++;
        else
            break;
    }

    return c > n / 2;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
    }

    ll ans = -1;
    ll s = 0;
    ll e = 1e18;
    sort(a.begin(), a.end());
    while (s <= e)
    {
        ll mid = s + (e - s) / 2;
        if (f(a, mid, sum))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
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