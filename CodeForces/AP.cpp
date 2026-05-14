#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int f, l, s;
        cin >> f >> l >> s;
        // t3 + t(n-2) == t1 + tn
        // 2s = n(t1 + tn)
        // 2s = n(t3 + t(n-2))
        int n = 2 * s / (f + l);
        int d = (l - f) / (n - 5);
        int a = f - 2 * d;
        cout << n << "\n";
        cout << a << " ";
        for (int i = 1; i <= n - 1; i++) {
            cout << a + i * d << " ";
        }
        cout << "\n";
    }

    return 0;
}