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
        string s;
        cin >> s;
        vector<int>f(26,0);
        int ans = 0;
        for(int i = 0; i < n ; i++){
            if(f[s[i] - 'A'] == 0){
                ans += 2;
                f[s[i]-'A'] = 1;
            }
            else{
                ans += 1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}