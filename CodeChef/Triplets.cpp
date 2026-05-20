#include "bits/stdc++.h"
using namespace std;
const long long mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long p, q, r;
        cin >> p >> q >> r;
        vector<long long> a(p), b(q), c(r);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        for (auto &x : c)
            cin >> x;

        sort(begin(a), end(a));
        sort(begin(b), end(b));
        sort(begin(c), end(c));

        vector<long long> pz(r, c[0] % mod);
        for (long long i = 1; i < r; i++) {
            pz[i] = (pz[i - 1] + c[i]) % mod;
        }
        vector<long long> px(p, a[0] % mod);
        for (int i = 1; i < p; i++) {
            px[i] = (px[i - 1] + a[i]) % mod;
        }
        long long ans = 0;
        /*  TC : (p+q+r)log(n) -> 1e10 operation, i.e TLE.
        // x <= y >= z
        for (long long i = 0; i < p; i++) {

            long long v1 = a[i]; // x
            auto it = lower_bound(begin(b), end(b), v1);
            if (it == b.end()) {
                break;
            }
            bool found = false;
            for (long long j = it - begin(b); j < q; j++) {
                long long v2 = b[j]; // y
                if (found == 1) {
                    long long n = r;
                    long long left = (v1 + v2) % mod;
                    long long right =
                        ((v2 % mod) * (n % mod)) % mod;

                    right = (right + pz[r - 1] % mod) % mod;

                    ans = (ans + (left * right) % mod) % mod;
                    continue;
                }
                long long it = upper_bound(begin(c), end(c), v2) - begin(c) - 1;
                if (it < 0) {
                    continue;
                }
                if (c[it] > v2) {
                    break;
                }
                if (it == r - 1) {
                    found = 1;
                }
                long long n = it + 1;
                long long left = (v1 + v2) % mod;

                long long right =
                    ((v2 % mod) * (n % mod)) % mod;

                right = (right + pz[it] % mod) % mod;

                ans = (ans + (left * right) % mod) % mod;
            }
        }
            */

        // TC : O(plogp+qlogq+rlogr+qlogp+qlogr)
        for (long long j = 0; j < q; j++) {
            long long v1 = b[j];

            auto it1 = upper_bound(begin(a), end(a), v1) - begin(a) - 1;
            if (it1 < 0) {
                continue;
            }

            auto it2 = upper_bound(begin(c), end(c), v1) - begin(c) - 1;
            if (it2 < 0) {
                continue;
            }

            long long zlen = it2 + 1;
            long long xlen = it1 + 1;

            long long first =
                (((zlen % mod) * (v1 % mod)) % mod + pz[it2]) % mod;

            long long second =
                (((xlen % mod) * (v1 % mod)) % mod + px[it1]) % mod;

            ans = (ans + (first * second) % mod) % mod;
        }
        cout << ans << "\n";
    }

    return 0;
}