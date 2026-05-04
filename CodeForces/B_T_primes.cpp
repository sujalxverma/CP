#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
unordered_map<long long, long long> primes;
void sieve(long long n) {
    vector<long long> f(n + 1, 0); // mark all numbers as 0, means all are prime.

    for (long long i = 2; i * i <= n; i++) {
        if (f[i] == 0) {
            // means this number i is a prime.
            // mark all factors of i to be non prime.
            for (long long j = i * i; j <= n; j += i) {
                f[j] = 1;
            }
        }
    }

    for (long long i = 2; i <= n; i++) {
        if (f[i] == 0) {
            primes[i] = 1;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    sieve(1e6 + 10);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n; i++) {
        long long v = a[i];
        if (floor(sqrt(v)) * floor(sqrt(v)) == v) {
            if (primes.count(floor(sqrt(v)))) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}