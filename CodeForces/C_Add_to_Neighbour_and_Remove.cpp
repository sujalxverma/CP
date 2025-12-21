#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0;  i < n ; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    for(int i = n ; i >= 1 ; i--){
        
        if(sum % i == 0){
            bool f = true;    
            int curSum = 0;
            for(int j = 0; j < n ; j++){
                curSum += a[j];
                if(curSum > (sum/i)){
                    f = false;
                    break;
                }
                else if(curSum == (sum/i)){
                    curSum = 0;
                }
            }

            if(f){
                cout<<n - i <<"\n";
                break;
            }
        }
    }
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