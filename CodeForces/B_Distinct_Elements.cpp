#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>a(n);
        for(auto &x : a){
            cin >> x;
        }
        vector<int>ans(n);
        ans[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(i - (a[i] - a[i-1]) >= 0){
                 ans[i] =  ans[i - (a[i] - a[i-1])];
            }
            else{
                ans[i] = i +1;
            }
           
        }
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<"\n";

        
    }
    return 0;
}