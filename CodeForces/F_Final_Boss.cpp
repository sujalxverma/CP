#include "bits/stdc++.h"
using namespace std;

using i128 = __int128_t;
using ll = long long;

bool f(vector<i128> &a, vector<i128> &b, i128 d, i128 h) {
    for (i128 i = 0; i < (i128)a.size(); i++) {
        i128 v = (d + b[i] - 1) / b[i];
        h -= v * a[i];

        if (h <= 0) {
            return true;
        }
    }

    return h <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll h, n;
        cin >> h >> n;

        vector<i128> a(n), b(n);

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a[i] = x;
        }

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            b[i] = x;
        }

        i128 H = h;

        i128 ans = 0;
        i128 s = 1;
        i128 e = (i128)1e18;

        while (s <= e) {
            i128 d = s + (e - s) / 2;

            if (f(a, b, d, H)) {
                ans = d;
                e = d - 1;
            } else {
                s = d + 1;
            }
        }

        cout << (long long)ans << '\n';
    }

    return 0;
}