#include "bits/stdc++.h"
using namespace std;
using ll = long long;
/*
2D DP.
*/
const ll INF = 1e18;

// ll f(vector<ll> &a, ll idx, ll sum, vector<vector<ll>> &dp)
// {
//     if (sum == 0)
//         return 0;

//     if (idx < 0)
//         return INF;

//     if (idx == 0)
//     {
//         if (sum % a[0] == 0)
//             return sum / a[0];
//         return INF;
//     }

//     if (dp[idx][sum] != -1)
//         return dp[idx][sum];

//     ll nottake = f(a, idx - 1, sum, dp);
//     ll take = INF;

//     if (a[idx] <= sum)
//         take = 1 + f(a, idx, sum - a[idx], dp);

//     return dp[idx][sum] = min(take, nottake);
// }
// Space optimization trick.
ll f_tab(vector<ll>& a, ll x)
{
    vector<ll> dp(x + 1, INF);
    dp[0] = 0;

    for (ll coin : a)
    {
        for (ll s = coin; s <= x; s++)
        {
            dp[s] = min(dp[s], 1 + dp[s - coin]);
        }
    }

    return dp[x] >= INF ? -1 : dp[x];
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    // vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    // ll ans = f(a, n - 1, m, dp);
    ll ans = f_tab(a, m);
    if (ans >= 1e9)
    {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}