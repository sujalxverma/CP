#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
vector<vector<ll>> dp;
ll f(ll n, ll r, vector<vector<ll>> &dp)
{
    if (n < r)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    if (r == 1)
    {
        return n;
    }
    ll val1, val2;
    if (dp[n - 1][r - 1] != -1)
    {
        val1 = dp[n - 1][r - 1] % mod;
    }
    else
    {
        val1 = f(n - 1, r - 1, dp);
        dp[n - 1][r - 1] = val1 % mod;
    }

    if (dp[n - 1][r] != -1)
    {
        val2 = dp[n - 1][r] % mod;
    }
    else
    {
        val2 = f(n - 1, r, dp);
        dp[n - 1][r] = val2 % mod;
    }

    return dp[n][r] = (val1 % mod + val2 % mod) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    if (n <= 12)
    {
        cout << "0\n";
        return 0;
    }
    // ll space = n - 12;
    // if (space == 1)
    // {
    //     cout << "1 \n";
    //     return 0;
    // }
    // if space left is even then 7 should appear atleast twice, else its appearance is odd, and atleast 1.
    n = (n - 13) / 2;
    dp.assign(1e6 + 5, vector<ll>(7, -1));

    cout << f(n + 6, 6, dp) % mod << "\n";

    return 0;
}