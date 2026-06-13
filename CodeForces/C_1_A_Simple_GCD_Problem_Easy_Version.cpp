#include "bits/stdc++.h"
using namespace std;
#define int long long
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int g = 0;
        for (int i = 0; i < n; i++) {
            g = gcd(a[i], g);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                continue;
            }
            int l = 0;
            int r = 0;
            if (i - 1 >= 0) {
                l = gcd(a[i], a[i - 1]);
            }
            if (i + 1 < n) {
                r = gcd(a[i], a[i + 1]);
            }
            if (i == 0) {
                if (r < a[i]) {
                    cnt++;
                }
                continue;
            }
            if (i == n - 1) {
                if (l < a[i]) {
                    cnt++;
                }
                continue;
            }
            if (lcm(l, r) < a[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}