#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++ ){
        cin >> a[i];
        sum += 1LL * a[i];
    }
    sort(a , a+n);
    ll used = 0;
    int chance = 0;
    for(ll i = 0; i < n ; i++){

        if(a[i] == 0){
            continue;
        }
        used += a[i];
        sum -= a[i] * (n - i);
        chance = chance ^ 1;
    }
    if(chance == 0){
        cout<<"BOB\n";

    }else{
        cout<<"ALICE\n";
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