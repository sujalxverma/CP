#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    // 0<= k < n , (n ^ k)&x = 0

    int bits1 = floor(log2(n)) + 1;
    int bits2 = floor(log2(x)) + 1;

    if (bits1 > bits2) {
        int ans = 1;
        for (int i = bits1 - 2; i >= 0; i--) {
            if (((1 << i) & (x)) == 0) {
                // this bit can be 0 or 1, no effect.
                ans *= 2;
            }
        }
        // cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}