#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout<<(1LL << n) - (2*n)<<"\n";
    return 0;
}