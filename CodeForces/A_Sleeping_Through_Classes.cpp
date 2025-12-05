#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        int c = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == '1'){
                c = k;
            }
            else{
                if( c > 0){
                    c--;
                }else{
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}