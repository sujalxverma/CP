#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// ll binpow(ll a, ll b) {
//     ll res = 1;
//     while (b) {
//         if (b & 1)
//             res *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return res;
// }

// ll gpSum(ll a, ll r, ll x) {
//     if (r == 1)
//         return a * (x + 1);
//     return a * ((binpow(r, x + 1) - 1) / (r - 1));
// }
ll sumPrimePower(ll p, ll e) {
    ll res = 1;
    ll cur = 1;

    for (ll i = 1; i <= e; ++i) {
        cur *= p;
        res += cur;
    }

    return res;
}
vector<ll> linearSieve(ll n) {
    vector<ll> spf(n + 1, 0);
    vector<ll> primes;

    for (ll i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (ll p : primes) {
            if (1LL * i * p > n || p > spf[i])
                break;

            spf[i * p] = p;
        }
    }

    return spf;
}

vector<ll> smallestPrimeFactors() {
    ll n = 1e8 + 10;
    vector<ll> f(n + 1);
    for (ll i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (f[i] == i) {
            // prime.
            for (ll j = 2; i * j <= n; j++) {
                if (f[i * j] == i * j) {
                    f[i * j] = i;
                }
            }
        }
    }
    return f;
}

vector<pair<ll, ll>> primes(ll n, vector<ll> &spf) {
    vector<pair<ll, ll>> store;
    while (n > 1) {
        auto p = spf[n];
        ll cnt = 0;

        while (n > 1 && spf[n] == p) {
            cnt++;
            n /= p;
        }

        store.push_back({p, cnt});
    }
    return store;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    vector<ll> spf = linearSieve(1e6 + 10);
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> p = primes(n, spf);
        ll cnt = 1;

        for (auto &[x, y] : p) {
            cnt *= sumPrimePower(x, y);
        }
        cout << cnt - n << "\n";
    }
    return 0;
}