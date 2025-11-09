#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>a(n+1); // 1 bases indexing
    int profit = 0;
    for(int i = 1; i <= n; i++ ){
        cin >> a[i];
        if(a[i] == i){
            profit ++ ;
        }
    }
    if(profit == n){
        cout<<n<<"\n";
        return ;
    }
    if(a[1] == 1 || a[n]==n){
        cout<<n-1<<"\n";
        return ;
    }
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