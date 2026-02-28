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
        int idx = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int a,b;
            cin >> a >> b;
            if(a > 10){
                continue;
            }else{
                if(ans < b){
                    ans = b;
                    idx = i+1;
                }
            }
        }
        cout<<idx<<"\n";
    }
    return 0;
}