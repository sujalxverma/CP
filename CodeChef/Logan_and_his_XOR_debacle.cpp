#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>a(n);
        ll xorSum  = 0;
        for(int i = 0; i < n ; i++){
            cin >> a[i];
            xorSum ^= a[i];
        }
        // cout<<xorSum<<"\n";
        if(xorSum == 0){
            cout<<"0\n";
           
        }else{
            ll diff = 1e18;
            for(int i = 0; i < n ; i++){
                diff = min(diff , abs((xorSum^a[i]) - a[i]));
            }
            cout<<diff<<"\n";
        }
    }

    return 0;
}