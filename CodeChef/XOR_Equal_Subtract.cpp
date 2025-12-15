#include "bits/stdc++.h"
using namespace std;
using ll = long long ;

/*
a-b == a^b , then a&b == b, (a>=b).
*/


int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>a(n) ;
        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }
        vector<vector<int>>p(n);
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                // if(i == j){
                //     continue;
                // }
                if((a[i]&a[j]) == min(a[i],a[j])){
                    p[i].push_back(a[j]);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n ; i++){
            // if(p[i].size() != 0){
            //     count++;
            // }
            cout<<a[i]<<" : ";
            for(auto x : p[i]){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        // cout<<count+1<<"\n";
    }
}
