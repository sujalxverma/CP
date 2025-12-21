#include "bits/stdc++.h"
using namespace std;
using ll = long long;

long long rangeSum(long long l, long long r)
{
    return (r - l + 1) * (l + r) / 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int a[n], b[n];

    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }

    vector<ll> suffix(n);
    suffix[n - 1] = b[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + b[i];
    }

    ll maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum = max(maxSum, 1LL * a[i] + (i + 1 < n ? suffix[i + 1] : 0LL));
    }
    maxSum = max(maxSum, suffix[0]);

    ll steps = maxSum - suffix[0]; // after clearing this much S[0] will dominate.

    if (steps >= m)
    {
        cout << maxSum * m << "\n";
        return;
    }

    cout << steps * maxSum + rangeSum(steps + 1, m) + (m - steps) * suffix[0] << "\n";
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