#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll>cost;
    ll totalP = 0;
    for(int i = 0 ; i < n ; i++){
        ll a,b;
        cin >> a >> b;
        cost.push_back(a+b);
        totalP += b;
    }

    sort(cost.begin(),cost.end());
    int count = 0;
    ll totalC = 0;
    for(int i = 0; i < n ; i++){
        totalC += cost[i];
        if(totalC > totalP){
            break;
        }
        else{
            count++;
        }
    }
    cout<<count<<"\n";

    

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