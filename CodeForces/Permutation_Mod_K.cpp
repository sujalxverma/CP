#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k == 1){
            cout<<"-1\n";
            continue;
        }
        if(k == 2 && n%2){
            cout<<"-1\n";
            continue;
        }
        cout<<n<<" ";
        for(int i = 1; i <= n-1 ; i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}