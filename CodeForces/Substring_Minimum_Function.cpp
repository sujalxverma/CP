#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        if (m == 0)
        {
            // no 1 is present.
            cout << n * (n + 1) / 2 << "\n";
            continue;
        }
        if (n == m)
        {
            cout << "0\n";
            continue;
        }
        if (m >= (n / 2))
        {
            cout << (n - m) << "\n";
            continue;
        }
        long long ans = 0;
        if (m == 1)
        {
            if (n % 2 == 0)
            {
                // means odd zeros.
                ll p = (n - 1) / 2;
                ll r = n - 1 - p;
                ans += 1LL * p * (p + 1) / 2;
                ans += 1LL * r * (r + 1) / 2;
                // cout<<r<<" "<<p<<"\n";
            }
            else
            {
                ll p = (n - 1) / 2;
                ans += 1LL * 2 * (p + 1) / 2 * (p);
            }
            cout << ans << "\n";
            continue;
        }
        ll z = (n - m);
        ll gaps = m + 1;
        ll r = (z) % gaps;
        ll rem = (z - r) / gaps; // properly divided by number of gaps.
        // remaining zeroes will be partitioned equally in gaps.
        ans += (gaps - r) * (rem) * (rem + 1) / 2;
        ans += (r) * (rem + 1) * (rem + 2) / 2;
        cout << ans << "\n";
    }
    return 0;
}