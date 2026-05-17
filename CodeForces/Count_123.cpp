#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
ll C(ll N, ll R, vector<ll> &fact, vector<ll> &invfact) {
    if (R < 0 || R > N)
        return 0;

    return fact[N] * invfact[R] % mod * invfact[N - R] % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    ll n = a + b + c + 10;

    vector<ll> fact(n), invfact(n);

    fact[0] = 1;
    // find factorial.
    for (ll i = 1; i < n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invfact[n - 1] = modpow(fact[n - 1], mod - 2);
    for (ll i = n - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }

    ll m = b + 1;

    ll lim = min({m, a, c});

    ll ans = 0;

    for (ll t = 0; t <= lim; t++) {

        ll cur = C(m, t, fact, invfact);

        cur = cur * C(m + a - t - 1, a - t, fact, invfact) % mod;
        cur = cur * C(m + c - t - 1, c - t, fact, invfact) % mod;

        if (t & 1) {
            ans = (ans - cur + mod) % mod;
        } else {
            ans = (ans + cur) % mod;
        }
    }

    cout << ans % mod << '\n';

    return 0;
}