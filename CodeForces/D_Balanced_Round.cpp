#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;
        }
        sort(begin(a) , end(a));
        int ans = -1e9;
        int cnt = 1;
        for(int i = 0 ; i < n -1 ; i ++){
            if(a[i+1] - a[i] <= k){
                cnt++;
                ans = max(ans , cnt);
            }else{
                cnt = 1;
            }
        }
        ans = max(ans , cnt);
        cout<< n - ans<<"\n";
    }
    return 0;
}