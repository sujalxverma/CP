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
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;
        }
        int k ;
        cin >> k;
        if(k >= *min_element(a.begin()  ,a.end()) && k<=*max_element(a.begin()  ,a.end()) ){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}