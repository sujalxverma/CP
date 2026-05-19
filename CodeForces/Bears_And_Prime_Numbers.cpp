#include "bits/stdc++.h"
using namespace std;

vector<int> sieve(int n) {
    vector<int> f(n + 1, 0);
    f[0] = f[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (f[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                f[j] = 1;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (f[i] == 0)
            primes.push_back(i);
    }
    return primes;
}

vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);
    for (int i = 0; i <= n; i++) {
        spf[i] = i;
    }
    spf[0] = 0;
    spf[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

void primeFactors(int n, vector<int> &spf, unordered_map<int, int> &mp) {
    unordered_set<int> factors;
    while (n > 1) {
        int p = spf[n];
        factors.insert(p);
        n /= p;
    }
    for (auto &x : factors) {
        mp[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;

    vector<int> f = smallestPrimeFactor(1e7 + 7);
    vector<int> ft = sieve(1e7 + 7);
    vector<int> prefix((int)ft.size());
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        primeFactors(a[i], f, mp);
    }
    prefix[0] = mp[2];
    for (int i = 1; i < (int)ft.size(); i++) {
        prefix[i] = prefix[i - 1] + mp[ft[i]];
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        int l = lower_bound(begin(ft), end(ft), u) - begin(ft);
        int r = upper_bound(begin(ft), end(ft), v) - begin(ft) - 1;
        if (r < l) {
            cout << 0 << "\n";
        } else {
            int sum = prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
            cout << sum << "\n";
        }
    }

    return 0;
}