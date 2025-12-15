#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n <= k)
        {
            cout << 1 << "\n";
            
        }
        else{
            ll ans = 1e9;
            for(ll i = 1 ; i * i <= n ; i++){
                if(n % i == 0 && i<=k){
                    ans = min(n/i , ans);
                    if( (n / i) <= k ){
                         ans = min(i , ans);
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}