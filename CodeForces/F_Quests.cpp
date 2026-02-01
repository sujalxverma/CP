#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;

bool f(vector<ll> &a, ll c, ll d, ll mid)
{
    // a is sorted in descending order.
    // how many times i can use a[0] : say on , 1 , 1+(mid+1),  1 + 2*(mid+1)
    int n = (int)a.size();
    ll sum = 0;
    ll cnt_days = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt_days > d)
        {
            return false;
        }
        cnt_days += 1 + ((d - (i + 1)) / (mid + 1));
        sum += a[i] + (((d - (i + 1)) / (mid + 1)) * a[i]);
        if (sum >= c && cnt_days <= d)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    ll n, d;
    ll c;
    cin >> n >> c >> d;
    a.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    // when answer is infinity, if the sum of array is >= c && days <= d.
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (i + 1 <= d && sum >= c)
        {
            cout << "Infinity\n";
            return;
        }
    }

    ll s = 0;
    ll e = 1e9;
    ll ans = -1;
    while (s <= e)
    {
        ll mid = s + (e - s) / 2;
        if (f(a, c, d, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (ans == -1)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << ans << "\n";
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