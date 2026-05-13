#include "bits/stdc++.h"
using namespace std;
/*
 * If on == 0, then string has all elements zero.
 * So, only switch string bit of max element, thus ->(max*max - x)
 * If zn == 0, then string has all elements one.
 * Step->4. Then we can greddily try to make minimum element as large as possible.
 * If max element of A, is not present in one array, then either include it, and do step 4.
 * Or do not include it and do step 4.
 */
void solve() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    string s;
    cin >> s;
    vector<long long> zero, one;
    for (long long i = 0; i < n; i++) {

        if (s[i] == '1') {
            one.push_back(a[i]);
        } else {
            zero.push_back(a[i]);
        }
    }

    sort(begin(a), end(a));
    sort(begin(zero), end(zero));
    sort(begin(one), end(one));
    long long zn = (long long)zero.size();
    long long on = (long long)one.size();
    long long ans = 0;
    if (zn == n) {
        cout << max(0LL, a[n - 1] * a[n - 1] - x) << "\n";
        return;
    }
    if (on == n) {
        for (long long i = 0; i < on; i++) {
            ans = max(ans, one[on - 1] * one[i] - (i)*x);
        }
        cout << ans << "\n";
        return;
    }
    if (one[on - 1] < zero[zn - 1]) {

        for (long long i = 0; i < on; i++) {
            ans = max(ans, zero[zn - 1] * one[i] - (i + 1) * x);
        }
        ans = max(ans, zero[zn - 1] * zero[zn - 1] - (on + 1) * x);
    }
    for (long long i = 0; i < on; i++) {
        ans = max(ans, one[on - 1] * one[i] - (i)*x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}