#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll f(vector<vector<ll>> &dp, int idx, ll num, ll n, ll k)
{
    if (idx == k)
    {
        return 1;
    }

    if (dp[idx][num] != -1)
    {
        return dp[idx][num] % mod;
    }
    ll ans = 0;
    for (ll i = num; i <= n; i += num)
    {
        ans = (ans + f(dp, idx + 1, i, n, k)) % mod;
    }
    return dp[idx][num] = ans % mod;
}

ll f_tab(ll n, ll k)
{
    vector<vector<ll>> dp(k+1, vector<ll>(n + 1, -1));
    for(ll i = 1 ; i <= n ; i++){
        dp[k][i] = 1;
    }
    for(ll i = k-1 ; i >= 0 ; i--){
        for(ll j = 1 ; j <= n ; j++){
            ll ans = 0;
            for(ll z = j ; z <= n ; z+=j){
                ans = (ans + dp[i+1][z])%mod ;
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][1]%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;

    // vector<vector<ll>> dp(k, vector<ll>(n + 1, -1));
    // ll ans = f(dp, 0, 1, n, k);
    ll ans = f_tab(n,k);
    cout << ans % mod << "\n";
    return 0;
}