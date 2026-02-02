#include "bits/stdc++.h"
using namespace std;
using ll = long long;


/*
1. Using BS, to find the segment to which d belongs.
2. b is already cummulative, no need to find prefix sum.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<ll> a(k + 1), b(k + 1);
        a[0] = 0;
        b[0] = 0;

        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];

        while (q--) {
            ll d;
            cin >> d;

            if (d == n) {
                cout << b[k] << " ";
                continue;
            }

            int s = 1, e = k, pos = k;
            while (s <= e) {
                int m = (s + e) / 2;
                if (a[m] >= d) pos = m, e = m - 1;
                else s = m + 1;
            }

            int seg = pos - 1;

            ll dist = d - a[seg];
            ll len  = a[seg + 1] - a[seg];
            ll tseg = b[seg + 1] - b[seg];

            ll ans = b[seg] + (dist * tseg) / len;
            cout << ans << " ";
        }
        cout << "\n";
    }
}
