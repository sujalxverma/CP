#include "bits/stdc++.h"
using namespace std;
long long n, k;

long long check(vector<long long> &p, long long &cnt, long long &idx, long long &val) {
    long long req = p[idx] - (idx - cnt >= 0 ? p[idx - cnt] : 0);
    long long cost = cnt * val;
    return (cost - req <= k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(begin(a), end(a));
    vector<long long> p(n, a[0]);
    for (long long i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    long long val = 1e9;
    long long freq = -1e9;
    for (long long i = 0; i < n; i++) {
        long long s = 1;
        long long e = i + 1;
        long long f = 0;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            if (check(p, m, i, a[i])) {
                f = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        if (f == freq) {
            val = min(val, a[i]);
        } else if (f > freq) {
            val = a[i];
            freq = f;
        } else {
            // do nothing.
        }
    }
    cout << freq << " " << val << "\n";
    return 0;
}