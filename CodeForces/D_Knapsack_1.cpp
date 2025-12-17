#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// ll knap(vector<pair<ll, ll>> &p, ll idx, ll W, vector<vector<ll>> &dp)
// {
//     if(idx < 0 || W == 0){
//         return 0;
//     }
//     if (idx == 0)
//     {
//         if (p[0].first <= W)
//         {
//             return p[0].second;
//         }
//         return 0;
//     }

//     if (dp[idx][W] != -1)
//     {
//         return dp[idx][W];
//     }

//     ll nottake = knap(p, idx - 1, W, dp);
//     ll take = 0;
//     if (p[idx].first <= W)
//     {
//         take = p[idx].second + knap(p, idx - 1, W - p[idx].first, dp);
//     }

//     return dp[idx][W] = max(take, nottake);
// }

ll kanp(vector<pair<ll, ll>> &p , ll &W){
    ll n = p.size();
    vector<vector<ll>>dp(n+ 1 , vector<ll>(W+1,0));

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= W ; j++){
            ll nottake = dp[i-1][j];
            ll take = 0;
            if(p[i-1].first <= j){
                take = p[i-1].second + dp[i-1][j - p[i-1].first] ;
            }
            dp[i][j] = max(take , nottake);
        }
    }
    return dp[n][W];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, W;
    cin >> n >> W;
    vector<pair<ll, ll>> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i].first;
        cin >> p[i].second;
    }
    
   cout<<kanp(p,W);
    return 0;
}