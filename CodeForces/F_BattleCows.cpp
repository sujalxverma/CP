#include "bits/stdc++.h"
using namespace std;
#define int long long
void solve() {

    int n, q;
    cin >> n >> q;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    while (q--) {
        int b, c;
        cin >> b >> c;
        b--;
        }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}