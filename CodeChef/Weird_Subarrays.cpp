#include "bits/stdc++.h"
using namespace std;

int f(vector<int>&a , int idx,int prev , vector<int>&dp){
    if(idx == 0){
        if(a[0] <= prev){
            return 1;
        }return 0;
    }

    if(a[idx] <)


}

void solve(){
    int  n;
    cin >> n;
    vector<int>a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<int>dp(n,-1);
    int ans = f(a,n-1,1e9,dp);

    cout<<ans<<"\n";
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