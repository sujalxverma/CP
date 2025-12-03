#include "bits/stdc++.h"
using namespace std;

void solve(){
     int n;
        cin >> n;
        int a[n];
        map<int,int>mp;
        for(int i = 0; i < n ; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a,a+n);
        int f = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(f == 0){

            }
            else {
                if(a[i] != a[i+1]){
                    cout<<"NO\n";
                    return ;
                }
            }
            f = !f;
        }

        cout<<"YES\n";
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