#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);

    // initially assume every number
    // is its own smallest prime factor
    for (int i = 0; i <= n; i++) {
        spf[i] = i;
    }

    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i * i <= n; i++) {
        // if spf[i] == i,
        // then i is prime
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                // first prime reaching j
                // is its smallest prime factor
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}
vector<int> spf;
vector<vector<int>> f(200010);
vector<int> primeFactors(int n, vector<int> &spf) {
    vector<int> factors;

    while (n > 1) {
        int p = spf[n];
        factors.push_back(p);

        n /= p;
    }
    return factors;
}
void solve();
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    spf = smallestPrimeFactor(200010);

    for (int i = 1; i < 200010; i++) {
        f[i] = primeFactors(i, spf);
    }
    while (t--) {
        solve();
    }
    return 0;
}

int rec(int n, vector<int> &cal, int &k) {
    if (n <= k) {
        return 0;
    }
    if (cal[n] != -1) {
        return cal[n];
    }
    int ans = 1e9;
    // we have to make min operations.
    // so its possible by dividing by bigger/smaller/medium number leads to
    // min value.
    // so try all prime factors of n.
    for (int &x : f[n]) {
        ans = min(ans, x * rec(n / x, cal, k));
    }
    return cal[n] = ans + 1;
}

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    if (a[n - 1] <= k) {
        cout << "0\n";
        return;
    }
    vector<int> cal(n + 10, -1);
    cal[0] = 0;
    cal[1] = 1;
    cal[2] = 1;
    cal[3] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            continue; // skip, no problem
        }
        ans = ans + rec(a[i], cal, k);
    }
    cout << ans << "\n";
}