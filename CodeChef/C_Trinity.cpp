#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll>a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n);
        for(auto &x : a){
            cin >> x;
        }
        sort(a.begin() , a.end());
        int ans = n-1; // simply make every element equal, this is the max value.
        

    }
    return 0;
}