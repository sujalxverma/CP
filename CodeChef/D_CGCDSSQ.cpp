#include "bits/stdc++.h"
using namespace std;
vector<int>a;
const int inf = 1e9;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n ; i++) cin >> a[i];
        int max_row = floor(log2(n));
        vector<vector<int>>st(max_row+1 , vector<int>(n,inf));
        st[0] = a;
        for(int i = 1 ; i <= max_row ;i++){
            for(int j = 0 ; j + (1<<i) <= n ; j++){
                st[i][j] = gcd(st[i-1][j] , st[i-1][j + (1<<(i-1))]) ;
            }
        }

        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            int count = 0;
            // count numbers of [l,r] pairs,such that this segement gcd is x.
            

        }


    }
    return 0;
}