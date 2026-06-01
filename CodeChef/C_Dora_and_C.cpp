#include "bits/stdc++.h"
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        vector<long long> v(n);
        for (auto &i : v) {
            cin >> i;
        }
        if (a > b) {
            swap(a, b);
        }
        if (a == 1) {
            cout << "0\n";
            continue;
        }
        if (gcd(a, b) == 1) {
            // bezout identity.
            cout << "0\n";
            continue;
        }

        long long g = gcd(a, b);
        for (long long i = 0; i < n; i++) {
            v[i] = v[i] % g;
        }
        sort(begin(v), end(v));
        long long ans = v[n - 1] - v[0];
        for (long long i = 0; i < n - 1; i++) {
            ans = min(ans, v[i] + g - v[i + 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}