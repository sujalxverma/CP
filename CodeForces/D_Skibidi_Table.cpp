#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<vector<ll>>g;

void f(ll v, ll n){
    if(n == 1){
        g[0][0] = v-3;
        g[1][1] = v-2;
        g[1][0] = v-1;
        g[0][1] = v;
        return ;
    }
    f(v>>1 , n >> 1);

    
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        g.assign((1<<n)+1 , vector<ll>((1<<n)+1));
        ll v = (1<<(2*n));
        n = (1<<(n-1))+1;

    }
    return 0;
}