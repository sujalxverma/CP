#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x, b;
            cin >> x >> b;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        for (int i = m; i >= 1; i--) {
            ans += (n * i);
            ans += (i * (i + 1)) / 2;
        }
        cout << ans << "\n";
    }

    return 0;
}