#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int>a(n+1);
    for(int i = 1 ; i <= n ;i++){
        if(y == i){
            a[i] = a[x-1];
            continue;
        }
        a[i] = i;
    }
    cout<<1<<" ";
    for(int i = 2 ; i <= n ; i++){
        cout<<(a[i]^a[i-1])<<" ";
    }

    cout<<"\n";
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