#include "bits/stdc++.h"
using namespace std;

/*
Y, it was a pretty good guess.
1. Subtract (largest + smallest)/2 at each iteration (1 to 40).
2. If after 40, its not zero then not possible.
*/

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x : a){
        cin >> x;
    }
 
    bool f = 0;
    vector<int>ans ;
    
    for(int i = 1 ; i<= 40 ; i++){
        int u = *min_element(a.begin(),a.end()) ;
        int v = *max_element(a.begin(),a.end()) ;
        // int c = 1e8;
        // for(int i = 0 ; i < n ; i++ ){
        //     if(a[i] < c && i != u){
        //         v = i;
        //         c = a[i];
        //     }
        // }

        int mean = (u + v) / 2;
        // if(a[u] == a[v]){
        //     mean = a[u]/2;
        // }
        for(int i = 0 ; i < n ; i++ ){
           a[i] = abs(a[i] - mean);
        }
        ans.push_back(mean);
        bool f = true;
         for(int i = 0 ; i < n ; i++ ){
           if(a[i] != 0){
            f = false;
           }
        }

        if(f==true){
            cout<<ans.size()<<"\n";
            for(auto x : ans){
                cout<<x<<" ";
            }
            cout<<"\n";
            return ;
        }

        
    }
   cout<<-1<<"\n";
   return ;
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