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
        int o=0;
        int e = 0;
        for(auto &x : a){
            cin >> x;
            if(x%2 == 0){
                e++;
            }else{
                o++;
            }
        }
        if(o == n || e == n){
            for(auto x : a){
                cout<<x<<" ";
            }
            cout<<"\n";
            
        }else{
            sort(a.begin() , a.end());
            for(auto x : a)
            {
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}