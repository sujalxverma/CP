
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Generate all primes up to sqrt(high)
vector<ll> simpleSieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }

    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

// Segmented sieve for range [low, high]
void segmentedSieve(ll low, ll high, const vector<ll> &basePrimes) {
    vector<bool> is_prime(high - low + 1, true);

    for (ll p : basePrimes) {
        ll start = max(p * p, ((low + p - 1) / p) * p);
        for (ll j = start; j <= high; j += p) {
            is_prime[j - low] = false;
        }
    }

    if (low == 1) is_prime[0] = false;

    for (ll i = 0; i <= high - low; ++i) {
        if (is_prime[i])
            cout << (low + i) << "\n";
    }
}

int main() {
    fast_io

    int t;
    cin >> t;

    while (t--) {
        ll m, n;
        cin >> m >> n;

        // Generate base primes only once per test case
        vector<ll> primes = simpleSieve(sqrt(n) + 1);
        segmentedSieve(m, n, primes);
        cout << "\n"; // Separate test cases with a blank line
    }

    return 0;
}
