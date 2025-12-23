#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int maxRange = 1e6 + 5;
ll f(ll n, vector<ll> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 10)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    ll ans = 1e9;
    ll copy = n;
    while (copy > 0)
    {
        ll digit = copy % 10;
        copy /= 10;
        if (digit == 0)
        {
            continue;
        }
        ans = min(ans, 1 + f(n - digit, dp));
    }

    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> dp(maxRange, -1);
    ll ans = f(n, dp);

    cout << ans << "\n";

    return 0;
}