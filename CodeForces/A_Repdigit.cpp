#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    map<char,int>mp;
    for(int i = 0; i < n ; i++){
        mp[s[i]]++;
    }
    if(mp.size() == 1){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }

    return 0;
}