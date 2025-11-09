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
      
        for(int i = 1; i <= k-3 ; i++){
            cout<<"1 ";
        }
        // 3 numbers remain.
        n = n-k+3;
        k = 3;
        if(n%2 == 0)
        {
            int val = (n)/2;
            if(val%2 == 0){
                 cout<<val<<" "<<val/2<<" "<<val/2<<"\n";
                 continue;
            }
            else{
                 cout<<val-1<<" "<<val-1<<" "<<2<<"\n";
            }
           
           
        }
        else{
            int val = (n)/2;
            cout<<val<<" "<<val<<" "<<1<<"\n";
            continue;
        }
    }
    return 0;
}