#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    set<ll> s;
    for (auto &x : a) {
        cin >> x;
        s.insert(x);
    }
    if ((int)s.size() != n) {

        // if any num is duplicate, then the result will ultimately become 0.
        if (0 >= l && 0 <= r) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (n > 7) {
        cout << "NO\n";
        return;
    }
    ll p = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            p *= (a[i] ^ a[j]);
            if (p > 1e9) { // since, p <= 1e9
                cout << "NO\n";
                return;
            }
        }
    }
    if (p >= l && r >= p) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}