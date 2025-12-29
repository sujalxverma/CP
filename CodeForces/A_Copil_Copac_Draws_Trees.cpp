#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        vector<int>dp(n+1,0);
        vector<int>id(n+1);
        dp[1] = 0;
        id[1]= 0;
        for(int i = 2; i <= n  ; i ++){
            int u,v;
            cin >> u  >> v;
        }
    }
    return 0;
}