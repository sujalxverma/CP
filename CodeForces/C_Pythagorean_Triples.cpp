#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;

vector<ll> sieve(ll n) {
    vector<ll> f(n + 1, 0); // mark all numbers as 0, means all are prime.

    for (ll i = 2; i * i <= n; i++) {
        if (f[i] == 0) {
            // means this number i is a prime.
            // mark all factors of i to be non prime.
            for (ll j = i * i; j <= n; j += i) {
                f[j] = 1;
            }
        }
    }
    vector<ll> primes;
    for (ll i = 2; i <= n; i++) {
        if (f[i] == 0)
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    ll n;
    cin >> n;

    vector<ll> f = sieve(1e6 + 100);
    ll num = 0;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}