#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long n, p, q;
        cin >> n >> p >> q;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        // odd -> use of 1 and 2, even -> alone 2 can handle.
        sort(begin(a), end(a));
        long long cnt = 0;
        for (long long i = 0; i < n; i++) {
            long long cp = p;
            long long cq = q;

            long long need = a[i];

            if (need % 2 == 1) {
                if (cp > 0) {
                    cp--;
                    need--;
                } else {
                    continue;
                }
            }

            long long two = need / 2;

            long long use = min(cq, two);
            cq -= use;
            two -= use;

            if (cp >= two * 2) {
                cp -= two * 2;

                cnt++;
                p = cp;
                q = cq;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}