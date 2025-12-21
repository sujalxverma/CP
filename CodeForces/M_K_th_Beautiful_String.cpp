#include "bits/stdc++.h"
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll>f;
    f.push_back(0);
    for(ll i = 1 ; i <= 1e5 ; i++){
        ll val = i*(i+1)/2;
        f.push_back(val);
    }
    while(t--){
        ll n,k;
        cin >> n >> k;
        k--;
        
        auto it = upper_bound(f.begin(),f.end(),k) - f.begin();
        
        // if(it == 0){
        //     for(ll i = 1 ; i <= n-2 ; i++){
        //         cout<<'a';
        //     }cout<<"bb\n";
        //     continue;
        // }
        // it--;
        // cout<<it<<"\n";
        ll diff =  k - f[it-1];
        ll first =  it+1;
        // cout<<f[it]<<"\n";
        // cout<<first<<"\n";
        ll second = diff+1;
        // cout<<second<<"\n";
        if(second == 0){
            second = 1;
        }
        string s = "";
        for(ll i = 1 ; i<=n ;i++ ){
            if(i == first || i==second){
                s+='b';
            }else{
                s+='a';
            }
        }

        reverse(s.begin(),s.end());
        cout<<s<<"\n";

        


    }
    return 0;
}