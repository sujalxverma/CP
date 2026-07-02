#include "bits/stdc++.h"
using namespace std;
#define int long long
/*
After f moves, the total distance is

    S = f * (f + 1) / 2.

We need

    (x + S) % n == 0

which is equivalent to

    S % n == (n - x) % n.
*/
void solve() {
    int n, x, p;
    cin >> n >> x >> p;
    int sum = 0;
    for (int f = 1; f <= min(p, 2 * n); f++) {
        sum += f;
        if (sum % n == (n - x) % n) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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