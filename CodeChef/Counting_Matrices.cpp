#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = 0;
        // brute force 
        for(int i = 1 ; i <= (n/2) ; i++){
            int a = i;
            int d = (n-i);

            if(a==d){

            }else{
                int same = 0;
                int product = a*d - 1;
                int count = 0;
                for(int j = 1 ; j <= product ; j ++){
                    
                }
            }
        }
    }
    return 0;
}