#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1;

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

ll sumPrimePower(ll p, ll e) {
    return (power(p, e + 1, MOD) - 1 + MOD) % MOD *
           power(p - 1, MOD - 2, MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> pf(n);

    for (auto &[p, e] : pf)
        cin >> p >> e;

    // number of divisors
    ll div = 1;
    for (auto [p, e] : pf)
        div = div * (e + 1) % MOD;

    // sum of divisors
    ll sum = 1;
    for (auto [p, e] : pf)
        sum = sum * sumPrimePower(p, e) % MOD;

    // product of divisors
    ll prod = 1;
    ll cnt = 1;

    for (auto [p, e] : pf) {
        prod = power(prod, e + 1, MOD) *
               power(power(p, e * (e + 1) / 2, MOD), cnt, MOD) % MOD;

        cnt = cnt * (e + 1) % PHI;
    }

    cout << div << " " << sum << " " << prod << '\n';
}