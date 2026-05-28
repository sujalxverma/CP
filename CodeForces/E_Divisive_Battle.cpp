#include "bits/stdc++.h"
using namespace std;

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

/*
Prime Factorization using SPF
------------------------------
Time Complexity : O(log n) : each division reduces n by at least a factor of 2.
*/
vector<int> primeFactors(int n, vector<int> &spf) {
    set<int> factors;

    while (n > 1) {
        int p = spf[n];
        factors.insert(p);

        n /= p;
    }
    vector<int> f(begin(factors), end(factors));
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> spf = smallestPrimeFactor(1e6 + 10);
    unordered_map<int, int> mp;
    mp[1]++;
    for (int i = 2; i <= 1e6; i++) {
        if (spf[i] == i) {
            mp[i]++;
        }
    }
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> p, np;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (mp.count(a[i])) {
                p.push_back(a[i]);
            } else {
                np.push_back(a[i]);
            }
        }
        bool f = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                f = false;
            }
        }
        if (f) {
            cout << "Bob\n";
            continue;
        }
        f = true;
        for (int i = 0; i < n; i++) {
            if (mp.count(a[i])) {
                // do nothing.
            } else {
                vector<int> k = primeFactors(a[i], spf);
                if ((int)k.size() == 1) {
                    a[i] = k[0];
                } else {
                    a[i] = 1e9;
                    f = false;
                }
            }
        }
        if (!f) {
            cout << "Alice\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {

                f = false;
            }
        }
        if (f) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}