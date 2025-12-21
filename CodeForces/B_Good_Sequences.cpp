#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        size_t h1 = hash<int>()(p.first);
        size_t h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int f(vector<int> &a, int idx, int prev,
      unordered_map<pair<int, int>, int, PairHash> &dp)
{

    if (idx < 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        if (gcd(a[0], prev) > 1 && a[0] < prev)
            return 1;
        return 0;
    }

    if (dp.count({idx, prev}))
    {
        return dp[{idx, prev}];
    }

    int nottake = f(a, idx - 1, prev, dp);
    int take = 0;
    if ((prev == 0 || a[idx] < prev) &&
        (prev == 0 || gcd(a[idx], prev) > 1))

    {
        take = 1 + f(a, idx - 1, a[idx], dp);
    }

    return dp[{idx, prev}] = max(take, nottake);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }

    unordered_map<pair<int, int>, int, PairHash> dp;
    int ans = f(a, n - 1, 0, dp);
    cout << ans << "\n";

    return 0;
}