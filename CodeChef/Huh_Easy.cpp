#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    string a = "";
    string b = "";
   
    if( k < (n/2)){
        cout<<"-1\n";
        return ;
    }
    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        if((i&1)){ // odd.
            a += 'A';
            b += 'B';
        }
        else{
            a += 'C';
            b += 'C';
            cnt ++;
        }
    }
    int idx = 0;
    while( k > cnt){
        a[idx] = 'B';
        idx+=2;
        k--;
    }
    cout<<a<<"\n";
    cout<<b<<"\n";
    return ;




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