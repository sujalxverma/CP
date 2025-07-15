#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int MAXN = 1e9 + 1;

bitset<MAXN> is_prime;
set<ll> s;

ll N = 1e9;

// Generate all numbers of form x^2 + y^4 ≤ N
set<ll> allY4() {
    set<ll> ans;
    for (ll y = 1; ; y++) {
        ll y4 = y * y * y * y;
        if (y4 > N) break;
        ll maxi = sqrt(N - y4);
        for (ll x = 1; x <= maxi; x++) {
            ll val = x * x + y4;
            ans.insert(val);
        }
    }
    return ans;
}

// Sieve of Eratosthenes up to limit
void sieve(ll limit) {
    is_prime.set(); // set all to true
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i)
                is_prime[j] = 0;
        }
    }
}

// Solve for a single query
void solve() {
    ll a;
    cin >> a;
    ll c = 0;
    for (auto num : s) {
        if (num > a) break;
        if (is_prime[num]) c++;
    }
    cout << c << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    s = allY4();       // Generate all x^2 + y^4 values
    sieve(N);          // Precompute primes up to N

    while (t--) {
        solve();
    }

    return 0;
}
