#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>f(n+1,0);
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;
            f[x]++;
        }
        int ans = 0;
        for(int i = 1; i <= n ; i++){
            ans += (f[i])/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}