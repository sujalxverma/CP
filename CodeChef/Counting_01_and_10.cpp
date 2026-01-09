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
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        ll ans = 0;

        ll adds = 1 + (n / 2);
        for (ll j = 1; j <= n / 2; j++)
        {
            ans += (j) * (n - j);
        }
        ans += adds;

        cout << ans << "\n";
    }
    return 0;
}