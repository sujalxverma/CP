#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll f(vector<ll> &dp, ll n)
{

    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    ll ways = 0;
    for (ll i = 1; i <= 6; i++)
    { // dice constraint
        if (n - i >= 0)
        {
            ways += (f(dp, n - i)) % mod; // ADD, not assign
        }
    }

    return dp[n] = ways % mod;
}

ll f_tab(ll n){
    vector<ll>dp(n+1,0);

    dp[0] = 1;

    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= 6 ; j++){
            if(i - j >= 0){
                dp[i] += (dp[i-j]) % mod;
            }
        }
    }


    return dp[n] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    ll ans = f_tab(n);
    cout << ans << "\n";
    return 0;
}