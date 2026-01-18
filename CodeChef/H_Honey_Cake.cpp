#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    ll w, h, d;
    cin >> w >> h >> d;
    ll n;
    cin >> n;
    // if ((w * h * d) % n != 0)
    // {
    //     cout << "-1\n";
    //     return;
    // }
    if (n == 1)
    {
        cout << "0 0 0\n";
        return;
    }
    vector<ll> f;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            if (n / i != i)
            {
                f.push_back(n / i);
            }
        }
    }
    sort(begin(f), end(f));

    // now can check every combination.
    for (ll i = 0; i < (ll)f.size() && f[i] <= w; i++)
    {
        for (ll j = 0; j < (ll)f.size() && f[j] <= h; j++)
        {
            for (ll k = 0; k < (ll)f.size() && f[k] <= d; k++)
            {
                if ((f[i] * f[j] * f[k]) == n)
                {
                    if (w % (f[i]) == 0 && h % (f[j]) == 0 && d % (f[k]) == 0)
                    {
                        cout << f[i] - 1 << " " << f[j] - 1 << " " << f[k] - 1 << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}