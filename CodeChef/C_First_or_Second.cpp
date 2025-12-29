#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,int>>p(n,{0,1});
        ll small = 1e8;
        ll idx = -1;
        for(int i = 0; i < n ; i++){
            cin >> p[i].first;
            if(p[i].first < 0){
                p[i].second = -1;
                p[i].first *= -1;
                if(small < p[i].second){
                    small = p[i].second;
                    idx = i;
                }
            }
           
        }
        ll ans = 0;
        if(idx != 0){
            // now check before idx.
            for(ll i = 1 ; i < idx ; i++){
                ans += p[i].first;
                p[i].first = 0;
            }
            if(p[0].second == -1){
                ans -= p[0].first;
                
            }else{
                ans += p[0].first;
            }
            // now check after idx.
             ll total = 0;
            for(int i = idx ; i < n ; i++){
                if(p[i].second == -1){
                    ans+=p[i].first;
                    p[i].first = 0;
                }else{
                    total+=p[i].first
                }

            }

           
        

        }



    }
    return 0;
}