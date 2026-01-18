#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p,q,a,b;
    cin >> p >> q >> a >> b;
     if (a >= p && a <= p + 99 &&
        b >= q && b <= q + 99) {
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}