#include "bits/stdc++.h"
using namespace std;
/*
Y.
1. The right side of smallest element should be sorted.
2. If not then -1.
3. Else number of elements on its left side.
*/
void solve(){
    int n;
    cin >> n ;
    vector<int>a(n);
    
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int idx = min_element(a.begin(),a.end())-a.begin();
    bool f = false;
    for(int i = idx ; i < n - 1 ; i++){
        if(a[i] > a[i+1]){
            f = true;
            break;
        }
    }
    if(f == true){
        cout<<"-1\n";
        return ;
    }
  
    cout<<idx<<"\n";
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