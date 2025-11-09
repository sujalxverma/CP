#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 5, vector<ll>(m + 5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (auto x : {-1, 1})
    {
        for (auto y : {-1, 1})
        {
            map<ll, ll> mp;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    ll add = (i - 1) * x + (j - 1) * y;
                    mp[a[i][j] + add]++;
                }
            }
            for(auto [i,j] : mp){
                ans = max(ans , j);
            }

        }
    }
    cout<< (n*m) - ans<<"\n";
    return ;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}