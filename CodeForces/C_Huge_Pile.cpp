#include "bits/stdc++.h"
using namespace std;
using ll= long long ;


ll f(ll n, ll k, ll steps){
    if(n < k){
        return -1;
    }
    if( n == k){
        return steps + 1;
    }
    return f((n/2) , k , steps +1) || 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n , k;
        cin >> n >> k;


    }
    return 0;
}