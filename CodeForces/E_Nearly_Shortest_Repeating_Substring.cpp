#include "bits/stdc++.h"
using namespace std;
vector<int>f(26,0);

void solve(){
      int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n ; i++){
            f[s[i]-'a']++;
        }
        // check if all characters are same.
        for(int i = 0; i < n ; i++){
            if(f[i] == n){
                cout<<"1\n";
                return ;
            }
        }
        // check if palindrome, it fails for s ->   aaabaaa, answer would be 1, not n.
        // can discard this case.

        
        




        f.clear();
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