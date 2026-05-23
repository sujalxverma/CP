#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll cnt = 0;

    // num = (1<<a)*(b*b)
    for (ll i = 1; i < 60; i++) {
        ll val = 0;
        ll s = 1;
        ll e = 1e9;
        if ((1LL << i) > n) {
            break;
        }
        while (s <= e) {
            ll m = s + (e - s) / 2;
            if ((1LL << i) <= n / (m * m)) {
                val = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        cnt += (val + 1) / 2;
    }

    cout << cnt << "\n";

    return 0;
}