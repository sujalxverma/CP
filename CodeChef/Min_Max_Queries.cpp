#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        while (q--) {
            int x;
            cin >> x;
            if (x == 1) {
                int u, v;
                cin >> u >> v;
                u--;
                a[u] = v;
            } else {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                if (l == r) {
                    cout << a[l] << "\n";
                    continue;
                }
            }
        }
    }

    return 0;
}