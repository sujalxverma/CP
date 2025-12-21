#include "bits/stdc++.h"
using namespace std;

void solve(){
     int n;
        cin >> n;
        vector<int>s;
        for(int i = 0; i < n ; i++){
            int k;
            cin >> k;
            s.push_back(k);
        }
        sort(s.begin(),s.end());
        int first = s[0];
        for(int i = 1; i < n ; i++){
            if(s[i] == s[i-1]){
                cout<<1<<"\n";
                cout<<s[i]<<"\n";
                return ;
                
            }
        }
        cout<<"-1\n";
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