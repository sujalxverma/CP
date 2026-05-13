#include "bits/stdc++.h"
using namespace std;
vector<long long> a;
long long n, k;
long long f(long long m) {
    long long products = 0;
    for (long long i = 0; i < n; i++) {
        products += m / a[i];
        if (products >= k)
            return 1;
    }
    if (products >= k)
        return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long s = 0;
    long long e = 1e18;
    while (s <= e) {
        long long m = s + (e - s) / 2;
        if (f(m)) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    cout << s << "\n";
    return 0;
}