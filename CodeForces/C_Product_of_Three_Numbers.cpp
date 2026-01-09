#include "bits/stdc++.h"
using namespace std;
using ll = long long ;

void solve(){
     ll n;
    cin >> n;
    vector<ll>f;
    for(ll i = 2 ; i * i< n ; i++){
        if(n % i == 0){
            f.push_back(i);
            f.push_back(n/i);
        }
    }
    
    if(f.size() == 0){
        cout<<"NO"<<"\n";
        return ;
    }
 
    for(auto x : f){
        ll value = x;
        ll num = n;
        num /= value;
 
        for(ll i = 2 ; i * i < num ; i++){
            if(num % i == 0 && value != i && value != (num/i)){
                cout<<"YES\n";
                cout<<value<<" "<<i<<" "<<num/i<<"\n";
                return ;
            }
        }
    }
 
    cout<<"NO\n";
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