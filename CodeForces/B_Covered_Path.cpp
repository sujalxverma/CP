#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v;
    cin >> u >> v;
    int t, d;
    cin >> t >> d;
    if (d == 0)
    {
        cout << u * t << "\n";
        return 0;
    }
    ll ans = u;
    int current = u;
    for (int i = 2; i <= t - 1; i++)
    {
        ans += min(current + d, abs(t - i) * d + v);
        current = min(current + d, abs(t - i) * d + v);
    }
    ans += v;
    cout << ans << "\n";
    return 0;
}