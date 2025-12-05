#include "bits/stdc++.h"
using namespace std;
using ll = long long ;



// all factors of 'n' including 1.
vector<ll> factors(ll n)
{
    vector<ll> ans;
    for (ll i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            { // avoid duplicates
                ans.push_back(n / i);
            }
        }
    }
    if (n > 1)
    {
        ans.push_back(1);
        ans.push_back(n);
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll a[n];
    for(ll i = 0; i < n ; i++) cin >> a[i];
    sort(a,a+n);
    vector<ll>ans ;
    for(ll i = 0 ; i < n ; i++){
        ll b = a[i];
        vector<ll>f = factors(b);
        bool fp = true;

        
        for(auto x : f){
            for(ll i = 0; i < n ; i++){
                if(a[i]%x != 0){
                    fp = false;
                    break;
                }

            }
            if(fp == false){
                fp = true;
            }else{
                ans.push_back(x);
                break;
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}