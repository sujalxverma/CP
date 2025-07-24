#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i,0,n) cin >> a[i];

    // Map to store current position of values
    unordered_map<int, int> pos; 
    rep(i,0,n) pos[a[i]] = i;

    vector<int> c(q);
    rep(i,0,q) cin >> c[i];

    for(int i=0; i<q; i++) {
        int p = pos[c[i]];
        cout << p + 1 << " ";

        // Rotate first p+1 elements right by 1: move a[p] to front.
        // Construct new positions after rotation
        // New order for first p+1 elements: a[p], a[0], a[1], ..., a[p-1]
        if(p > 0) {
            int val = a[p];
            for(int j = p; j > 0; j--) {
                a[j] = a[j-1];
                pos[a[j]] = j;
            }
            a[0] = val;
            pos[val] = 0;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
