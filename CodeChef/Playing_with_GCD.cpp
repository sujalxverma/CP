#include "bits/stdc++.h"
using namespace std;

vector<long long> preCalculate() {
    long long n = 1e6 + 10;
    vector<long long> phi(n + 10);
    for (long long i = 0; i <= n; i++) {
        phi[i] = i;
    }
    for (long long i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (long long j = 1; j * i <= n; j++) {
                phi[i * j] -= phi[i * j] / i;
            }
        }
    }
    vector<long long> prefix(n + 10);
    prefix[0] = phi[0];
    for (long long i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + phi[i];
    }
    return prefix;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // count number of pairs, (x,y)==(y,x), such that gcd(x,y) > 1
    // total pairs - no. of pairs whose gcd == 1
    // can precalulate
    long long t;
    cin >> t;
    vector<long long> f = preCalculate();
    long long cnt = 1;
    while (t--) {
        long long n;
        cin >> n;
        long long total = n * (n + 1) / 2;
        cout << "Case " << cnt << ": ";
        cout << total - f[n] << "\n";
        cnt++;
    }

    return 0;
}