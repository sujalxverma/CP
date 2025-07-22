#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll m;
    cin >> n >> m;

    vector<ll> l(n), r(n), p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    // Initialize difference arrays
    vector<ll> prodDiff(m + 2, 1);   // for multiplicative updates
    vector<ll> sumDiff(m + 2, 0);    // for additive updates

    for (int i = 0; i < n; i++) {
        // Compute P_i = p_i * q_i^{-1} mod
        ll inv_q = mod_inv(q[i]);
        ll Pi = (p[i] * inv_q) % MOD;

        // 1 - P_i mod
        ll one_minus_Pi = (1 + MOD - Pi) % MOD;

        // val for sum update = P_i / (1 - P_i)
        ll inv_one_minus_Pi = mod_inv(one_minus_Pi);
        ll val = (Pi * inv_one_minus_Pi) % MOD;

        // Update prodDiff: multiply by (1-Pi) in [l[i], r[i]]
        prodDiff[l[i]] = (prodDiff[l[i]] * one_minus_Pi) % MOD;
        prodDiff[r[i] + 1] = (prodDiff[r[i] + 1] * inv_one_minus_Pi) % MOD;

        // Update sumDiff: add val in [l[i], r[i]]
        sumDiff[l[i]] = (sumDiff[l[i]] + val) % MOD;
        sumDiff[r[i] + 1] = (sumDiff[r[i] + 1] + MOD - val) % MOD;
    }

    // Prefix multiply for prodDiff to get prod[i]
    vector<ll> prod(m + 1, 1);
    for (ll i = 1; i <= m; i++) {
        prod[i] = (prod[i - 1] * prodDiff[i]) % MOD;
    }

    // Prefix sum for sumDiff to get sum[i]
    vector<ll> sum(m + 1, 0);
    for (ll i = 1; i <= m; i++) {
        sum[i] = (sum[i - 1] + sumDiff[i]) % MOD;
    }

    // Calculate final answer = product over all i of prod[i] * sum[i]
    ll answer = 1;
    for (ll i = 1; i <= m; i++) {
        if (sum[i] == 0) {
            // If sum[i] == 0 => probability exactly one segment covers cell i = 0 --> overall zero
            answer = 0;
            break;
        }
        ll cur = (prod[i] * sum[i]) % MOD;
        answer = (answer * cur) % MOD;
    }

    cout << answer << "\n";

    return 0;
}
