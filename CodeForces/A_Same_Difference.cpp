#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n ;
        cin >> s;
        map<char,int>mp;
      
        for(auto x : s){
            mp[x]++;

        }
        cout<<n - mp[s[n-1]]<<"\n";
        
        

    }
    return 0;
}