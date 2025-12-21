#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;   // ❌ no modulo here
    }

    vector<ll> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];   // ❌ no modulo here
    }

    sort(b.begin(), b.end());

    vector<ll> prefix(m);
    prefix[0] = b[0];
    for (int i = 1; i < m; i++)
    {
        prefix[i] = prefix[i - 1] + b[i];
    }

    ll totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        ll val = a[i];

        ll idx = upper_bound(b.begin(), b.end(), val) - b.begin();

        ll sumL = (idx == 0 ? 0LL : prefix[idx - 1]);
        ll sumR = prefix[m - 1] - sumL;

        ll left = val * idx - sumL;
        ll right = sumR - val * (m - idx);

        ll contrib = (left + right) % mod;
        if (contrib < 0) contrib += mod;

        totalSum = (totalSum + contrib) % mod;
    }

    cout << totalSum << "\n";
    return 0;
}
