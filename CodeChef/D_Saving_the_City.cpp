#include "bits/stdc++.h"
using namespace std;

void solve(){
    int a,b;
    cin >> a >> b;
    string s ;
    cin >> s;
    int r = -1;
    bool f = false;
    int n = s.length();
    int ans = 0;
    int j = -1;
    for(int i = 0; i < n ; i++){
        if(s[i] == '1'){
            j = i;
            break;
        }
    }
    f = true;
    r = j;
    vector<int>d;
    for(int i = j+1 ; i < n ; i++){
        if(s[i] == '1' && f== false){
            f = true;
            d.push_back(i-r-1);
            r=i;
        }
        else{
            f = false;
        }
    }
    for(auto x : d){
        if(a <= b){
            ans+=a;
        }
        else{
            if(x*b )
        }
    }
    if(a<=b){
        ans+=a;
    }
    cout<<ans<<"\n";
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