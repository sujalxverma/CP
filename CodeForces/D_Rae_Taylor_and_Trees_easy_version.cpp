#include "bits/stdc++.h"
using namespace std;

/*
N. 
1. Calculate minprefix and maxsuffix.
2. if p[i-1] > s[i] , then it means the part from i to n, will not be connected 
   to previouse part as per condition.
*/



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
        // if first element is 1 or last element is n.
        if(a[0] == 1 || a[n-1] == n){
            cout<<"YES\n";
            continue;
        }
        // if first element is n or last element is 1.
        if(a[n-1] == 1 || a[0] == n){
            cout<<"NO\n";
            continue;
        }

        vector<int>p(n,a[0]);
        vector<int>s(n,a[n-1]);

        for(int i = 1 ; i < n ; i++){
            p[i] = min(p[i-1] , a[i]);
        }
        for(int i = n-2 ; i >=0 ; i--){
            s[i] = max(s[i+1] , a[i]);
        }

        bool f = true;
        for(int i = 1; i < n ; i++){
            if(p[i-1] > s[i]){
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