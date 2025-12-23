#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
Need dp optimizations.
How ?
Convert memo -> teb -> space optimization.
*/

ll f(vector<pair<ll, ll>> &p, ll Weight)
{

    // if (idx < 0)
    // {
    //     return 0;
    // }
    // if (idx == 0)
    // {
    //     if (p[0].first <= Weight)
    //     {
    //         return p[0].second;
    //     }
    //     return 0;
    // }

    // if (dp[idx][Weight] != -1)
    // {
    //     return dp[idx][Weight];
    // }

    // ll nottake = f(p, idx - 1, Weight, dp);
    // ll take = 0;
    // if (p[idx].first <= Weight)
    // {
    //     take = p[idx].second + f(p, idx - 1, Weight - p[idx].first, dp);
    // }

    // return dp[idx][Weight] = max(nottake, take);

    vector<ll> dp(Weight + 1, 0);
    for (int i = 0; i <= Weight; i++)
    {
        if (p[0].first <= i)
        {
            dp[i] = p[0].second;
        }
    }
    vector<ll> prev = dp;
    for (int i = 1; i < p.size(); i++)
    {
        for (int j = 1; j <= Weight; j++)
        {
            dp[j] = max(prev[j], (p[i].first <= j ? (p[i].second + prev[j - p[i].first]) : 0));
        }
        prev = dp;
    }

    return dp[Weight];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<ll, ll>> p;
    ll total_weight = 0;
    ll total_value = 0;
    for (int i = 0; i < n; i++)
    {
        ll w, h, b;
        cin >> w >> h >> b;
        total_weight += w;
        total_value += b;
        p.push_back({w, max(h - b, 0LL)});
    }
    vector<vector<ll>> dp((int)p.size(), vector<ll>((500 * 500) / 2 + 100, -1));

    cout << total_value + f(p, total_weight / 2) << "\n";

    return 0;
}