#include "bits/stdc++.h"
using namespace std;
using ll = long long ;

pair<ll, ll> minMaxDigit(long long x) {
    // Handle the special case x == 0
    if (x == 0) {
        return {0, 0};
    }

    ll mn = 9, mx = 0;
    while (x > 0) {
        ll d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }
    return {mn, mx};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){

        ll n,k;
        cin >> n >> k;
        bool f = false;
        ll ans = n;
        for(ll i = 1; i < k ; i++){
            pair<ll,ll>d = minMaxDigit(ans);
            if(d.first == 0){
                f = true;
                break;
            }
            else{
                ans = ans + (d.first * d.second);
            }
        }

        if(f == true){
            cout<<ans<<"\n";
        }else{
            cout<<ans<<"\n";
        }

    }
    return 0;
}