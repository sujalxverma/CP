#include "bits/stdc++.h"
using namespace std;
long long n, K;
long long f(vector<long long> a, long long m) {
    // make all card >= m.
    long long k = K;
    for (long long i = 1; i <= n; i++) {
        long long diff = max(0LL, m - a[i]);
        if (diff > k) {
            return 0;
        }
        a[i] += diff;
        k -= diff;
    }

    if (k < 0)
        return 0;

    return 1;
}

void solve() {

    cin >> n >> K;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long s = 0;
    long long e = 1e12;
    long long len = 0;
    long long ans = 0;

    while (s <= e) {
        long long m = s + (e - s) / 2;
        if (f(a, m)) {
            // cout << m << "\n";
            len = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    // cout << "\n";
    ans = n * len - (n - 1);
    long long need = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > len) {
            ans++;
        } else {
            need += (len - a[i]);
        }
    }
    cout << ans + max(0LL, K - need) << "\n";
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