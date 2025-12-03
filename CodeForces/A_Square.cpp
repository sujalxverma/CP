#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        set<int>s;
        for(int i = 0 ; i < 4 ; i++){
            int k;
            cin >> k;
            s.insert(k);
        }
        if(s.size() == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}