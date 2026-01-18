#include "bits/stdc++.h"
using namespace std;
vector<int>a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }
        if(a[0] == 1 || a[n-1] == 1){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
    }
    return 0;
}