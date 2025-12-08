#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        vector<ll>a(n,0);
        ll j = 1;
        ll xorv = 0;
        for(ll i = x ; i <= y ; i++){
            if(i == y){
                a[i] = xorv;
                break;
            }
            a[i] = j;
            xorv = xorv^j;
            j=2;
            
            
        }
        
        ll c = 1;
        for(ll i = 0 ; i < n ; i++){
            if(a[i] == 0){
                a[i] = (1LL << c);
                c++;
                c = c%4;
                if(c==0) c++;
            }
        }

        for(auto x : a){
            cout<<x<<" ";
        }
        cout<<"\n";

    }
    return 0;
}