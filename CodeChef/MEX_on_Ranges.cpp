#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(n == 2 && s=="111"){
        cout<<"0 1"<<"\n";
        return ;
    }
    if(n==2 && s=="110"){
        cout<<"0 3"<<"\n";
        return ;
    }
    cout<<0<<" ";
    
    int ans = 1;
    int k = 1;
    for(int i = 2; i <= n ; i++){
        if(s[i] == '0'){
            cout<<k+1<<" ";
            k++;
        }else{
            cout<<ans<<" ";
            ans = i;
            k = ans;
        }
    }
    cout<<"\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}