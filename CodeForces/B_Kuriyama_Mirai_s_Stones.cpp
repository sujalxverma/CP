#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    vector<long long> b = a;
    sort(begin(b), end(b));
    vector<long long> pa(n, a[0]);
    vector<long long> pb(n, b[0]);
    for (long long i = 1; i < n; i++) {
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
    }
    long long q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        if (x == 1) {
            cout << pa[r] - (l == 0 ? 0 : pa[l - 1]) << "\n";
        } else {
            cout << pb[r] - (l == 0 ? 0 : pb[l - 1]) << "\n";
        }
    }
    return 0;
}