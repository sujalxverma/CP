#include "bits/stdc++.h"
using namespace std;
using ll = long long;


void solve()
{
    ll n;
    cin >> n;
    vector<ll> coins = {1, 3, 6, 10, 15};
    

    vector<pair<ll, ll>> p;
    ll ans = 0;
    for (ll i = 4; i >= 0; i--)
    {
        p.push_back({coins[i], (n / coins[i])});
        n = n % coins[i];
    }
    sort(p.begin(), p.end());
    for (auto &x : p)
    {
        if (x.first == 10)
        {
            if (x.second > 2)
            {
                x.second -= 3;
                for (auto &y : p)
                {
                    if (y.first == 15)
                    {
                        y.second += 2;
                        break;
                    }
                }
            }
        }
        else if (x.first == 6)
        {
            if (x.second > 4)
            {
                x.second -= 5;
                for (auto &y : p)
                {
                    if (y.first == 15)
                    {
                        y.second += 2;
                        break;
                    }
                }
            }
        }
        else if (x.first == 3)
        {
            if(x.second > 1){
                x.second -= 2;
                for(auto &y : p){
                    if(y.first == 6){
                        y.second += 1;
                        break;
                    }
                }
            }
        }
        else if (x.first == 1)
        {
            if(x.second > 2){
                x.second -= 3;
                for(auto &y : p){
                    if(y.first == 3){
                        y.second += 1;
                        break;
                    }
                }
            }
        }
    }
    for(auto x : p){
        ans += x.second;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}