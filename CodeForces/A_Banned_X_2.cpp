#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
void solve()
{
    
    ll a[10];
    ll sum = 0 ;
    set<ll>s;

    for(ll i = 1 ; i <= 9 ; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] != 0){
            s.insert(i);
        }
    }

    if(s.size() == 2){
        if(*s.begin() + *(s.rbegin()) == 10){
            cout<<"1\n";
            return ;
        }
      
    }

    cout<<max(0LL , 2*a[5] - sum - 1)<<"\n";
    return ;


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}