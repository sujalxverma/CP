#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        int odd = 0;
        int ones = 0;
        for(int i = 0; i < n ; i++){
            int k;
             cin >> k;
             if(k%2 == 1 && k!=1){
                odd++;
             }
             if(k  == 1){
                ones++;

             }
        }

        if(odd%2 == 1){
            cout<<"Alice\n";
        }
        else{
            if()
        }
    }
    return 0;
}