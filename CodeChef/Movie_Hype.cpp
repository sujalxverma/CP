#include "bits/stdc++.h"
using namespace std;
vector<int>a;
vector<int>b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n+1);
        b.resize(2*n+2);
        for(int i = 0; i <= n ; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= n ; i++){
            b[2*(i+1)-1] = a[i];
        }
        // for(int i = 1; i < 2*n+2 ; i++){
        //     cout<<b[i]<<" ";
        // }
        // return 0;
        int ans = 1e9;
        for(int i = 2 ; i <= 2*n ; i+=2){
            ans = min(ans,max(b[i-1] , b[i+1]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}