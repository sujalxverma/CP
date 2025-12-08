#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// all factors of 'n' including 1.
vector<ll> factors(ll n)
{
    vector<ll> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            { // avoid duplicates
                ans.push_back(n / i);
            }
        }
    }
    if (n > 1)
    {
        ans.push_back(1);
        ans.push_back(n);
    }
    return ans;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        if (((a + b) & 1) == 1)
        {
            cout << "-1\n";
            return;
        }
        else
        {
            cout << a + b << "\n";
            return;
        }
    }
    if (a == 1)
    {
        if ((a + b) % 2 == 0)
        {
            cout << a + b << "\n";
            return;
        }
    }
    vector<ll> f = factors(b);
    ll ans = -1;
    if ((a + b) % 2 == 0)
    {
        ans = (a + b);
    }
    for (ll i = 0; i < (f.size())/2 + 1; i++)
    {
        if (f[i] == 1)
        {
            continue;
        }
        ll x = a;
        ll y = b;

        while (y > 1)
        {
            if (y % (f[i]) != 0)
            {
                break;
            }
            else
            {
                y = y / f[i];
                x *= f[i];
                if (((x + y) & 1) == 0)
                {
                    ans = max(ans, x + y);
                }
            }
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