#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = (int)s.length();
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < 3 ; i++){
            sum1 += (s[i] - '0');
        }
        for(int i = n-1 ; i > n-4 ; i--){
            sum2 += (s[i] - '0');
        }

        if(sum1 == sum2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}