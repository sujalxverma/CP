#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int>s;
    for(int i   = 0; i < n ; i++){
        int j;
        cin >> j;
        s.insert(j);
    }
    if(s.size() > 3){
        cout<<"-1\n";
        return 0;
    }
    vector<int>v;
    for(auto k : s){
        v.push_back(k);
    }

    if(v.size() == 3){
        if(v[1] - v[0] == v[2] - v[1]){
            cout<<v[1]-v[0]<<"\n";
            return 0;
        }else{
            cout<<"-1\n";
            return 0;
        }
    }
    if(v.size() == 2){
        if((v[1] - v[0])%2 == 0){
            cout<<(v[1]-v[0])/2<<"\n";
        }else{
            cout<<v[1]-v[0]<<"\n";
        }
        return 0;
    }
    cout<<0<<"\n";



    return 0;
}