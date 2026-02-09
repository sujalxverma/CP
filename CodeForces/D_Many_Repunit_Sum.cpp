#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll>a(1e5+5);
    for(int i = 1; i <= n ; i++){
        ll k;
        cin >> k;
        a[k] ++ ;
    }    
    
    return 0;
}