#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<long long> sieve(long long n) {
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
    vector<long long> primes;
    for (long long i = 2; i <= n; i++) {
        if (f[i] == 0)
            primes.push_back(i);
    }
    return primes;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long t;
    cin >> t;
    vector<long long> f = sieve(1e6 + 10);
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << f[i] * f[i + 1] << " ";
        }
        cout << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}