#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        sort(a.begin(),a.end());
        sort(b.begin() , b.end());
        bool f= true;
        for(int i = 0; i < n ; i++){
            if(a[i] != b[i]){
                f = false;
            }
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}