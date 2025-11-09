#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;

    ll a[n+1];
    for(ll i = 1 ;i <= n ; i++){
        cin >> a[i];
    }

    ll p[3][n+1] ; // 1 based indexing, prefix sum.
    p[1][1] = a[1]; // odd
    p[2][1] = 0 ;   // even
    p[2][2] = a[2];
    p[1][2] = p[1][1];
    for(ll i = 3; i <= n ; i++){
        if((i&1) == 0){ // even
            p[2][i] = p[2][i-2] + a[i];
            p[1][i] = p[1][i-1];
        }else{  // odd  
            p[1][i] = p[1][i-2] + a[i];
            p[2][i] = p[2][i-1];
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