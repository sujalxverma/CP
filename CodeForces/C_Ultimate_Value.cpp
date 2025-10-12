#include "bits/stdc++.h"
using namespace std;
using ll = long long;
 /*
    I am not able to understand the solution.
 */
int main(){
 
    int tt;
    cin >> tt;
 
    while(tt--){
 
        int n;
        cin >> n;
 
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(i % 2) ans -= a[i];
            else ans += a[i];
        }
 
        ll init = ans;
 
        for(int i = 0; i < n; i++) ans = max(ans, init + i - (i % 2));
 
        ll min_even = LLONG_MAX / 2, min_odd = LLONG_MAX / 2;
        for(int i = 0; i < n; i++){
            if(i % 2){
                ans = max(init + i + a[i] + a[i] - min_even, ans);
                min_odd = min(min_odd, i - a[i] - a[i]);
            }
            else{
                ans = max(init + i - a[i] - a[i] - min_odd, ans);
                min_even = min(min_even, i + a[i] + a[i]);
            }
        }
 
        cout << ans << '\n';
 
    }
 
    return 0;
}