#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt = 0;
    for(auto &x : s){
        if(x == 'i' || x=='j'){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}