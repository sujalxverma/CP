#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k;

        vector<tuple<int,int,int>>g;
        for(int i = 0 ; i < k ; i++){
            int a,b,c;
            cin >> a >> b >> c;
            g.push_back({a,b,c});
        }
        if(k == 1){
            cout<<"YES\n";
            continue;
        }

        /*
        A camp may have multiple soliders, but each soldier must be assigned a camp.
        There may be soldiers which are not part of any condition, can be placed freely.
        */

        // ai , bi , -di -> ai = bi + di
        // ai , bi , di -> bi = ai + di

        



    }
    return 0;
}