#include "bits/stdc++.h"
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
constexpr ll INV2 = 500000004; // 2^{-1} mod MOD

ll sum(ll l, ll r) {
    l %= MOD;
    r %= MOD;
    ll cnt = (r - l + 1 + MOD) % MOD;
    return ((l + r) % MOD * cnt % MOD) * INV2 % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll ans = 0;

    for (ll l = 1; l <= n;) {
        ll q = n / l;
        ll r = n / q;

        ans = (ans + q % MOD * sum(l, r)) % MOD;
        l = r + 1;
    }

    cout << ans << '\n';
}