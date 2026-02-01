#include "bits/stdc++.h"
using namespace std;
vector<int>a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // NxN grid. 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n);  // a[i] denotes the row of peice i, which is placed in a[i] row.
        for(int i =0;i < n ;i++){
            cin >> a[i];
        }

        
    }
    return 0;
}