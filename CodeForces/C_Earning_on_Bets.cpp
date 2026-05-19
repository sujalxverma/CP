#include "bits/stdc++.h"
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long lcm = 1;
        long long sum = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            lcm = lcm * a[i] / gcd(lcm, a[i]);
        }
        for (long long i = 0; i < n; i++) {
            sum += lcm / a[i];
        }
        if (sum >= lcm) {
            cout << "-1\n";
        } else {
            for (long long i = 0; i < n; i++) {
                cout << lcm / a[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}