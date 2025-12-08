// ll x = 232323;
// string s = to_string(x);

// string s = "987654321";
// long long x = stoll(s);

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll modpow10(int len, ll m) {
    ll r = 1;
    while (len--) r = (r * 10) % m;
    return r;
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
    ll ans = 0;
    vector<vector<ll>>g(11);
    for(auto x : a){
        g[to_string(x).size()].push_back(x%m);
    }
    for(auto &x : g){
        sort(x.begin(),x.end());
    }
    /*
    1. There can be atmost 10 digits.
    2. I am storing a[i] in the form of : {digit , x%m}.
    */

    for(ll x : a){
        ll mod1 = x%m;
        ll val = x;
        for(ll i = 1; i < 11 ; i++){
            val *= 10;
            val %= m;
            ll key = (m-val)%m;
            // for number of digits k, i need number of values whose %m is key.
            ans += lower_bound(g[i].begin(), g[i].end(), key + 1) - lower_bound(g[i].begin(), g[i].end(), key);
        }
    }

    
   

    cout << ans << "\n";
    return 0;
}