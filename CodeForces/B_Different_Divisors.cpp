#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Global vector to hold primes
vl primes;

// Sieve of Eratosthenes up to 1e6
void sieveOfEratosthenes(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

/*
    1. first we calculate all the primes upto 1e6 , but we can go upto 1e4 aswell.
    2. now primes are stored in vector in sorted oreder, then we use lower bound.
    3. then we find 2 primes.
    4. p1 which is >= (1+d), d is addes b/c we need minimum gap b/w 2 primes to be d.
    4. p2 which is >= (p+d), d is addes b/c we need minimum gap b/w 2 primes to be d.
    5. We pick p1 as the smallest prime ≥ 1 + d, to ensure p1 - 1 ≥ d
    6. Then p2 as the smallest prime ≥ p1 + d, to ensure p2 - p1 ≥ d
*/


void solve() {
    ll d;
    cin >> d;

   auto p1 = *lower_bound(primes.begin(),primes.end(),1+d);
   auto p2 = *lower_bound(primes.begin(),primes.end(),p1+d);
    cout << p1 * p2 << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fast_io;

    sieveOfEratosthenes(1e6);  // Precompute all primes up to 1e6

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
