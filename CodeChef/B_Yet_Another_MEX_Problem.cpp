#include "bits/stdc++.h"
using namespace std;
vector<int>a,mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        a.resize(n);
        mp.resize(n);
        fill(mp.begin(),mp.end(),0);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        bool f = true;
        int idx = -1;
        for(int i = 0 ; i < k ; i++){
            if(mp[i]==0){
                idx = i-1;
                f = false;
                break;
            }
        }
        if(!f){
            cout<<(idx == -1 ? 0 : idx+1)<<"\n";
        }else{
            cout<<k-1<<"\n";
        }
    }
    return 0;
}