#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    vector<int>p(n);
    p[0] = a[0];
    for(int i = 1; i < n ; i++){
        p[i] = p[i-1]^a[i];
    }

    while(q--){
        int i,j;
        cin >> i >> j;
        i--;
        j--;
        if(i == 0){
            cout<<p[j]<<"\n";
        }else{
            cout<<(p[j] ^ p[i-1])<<"\n";
        }
    }


    return 0;
}