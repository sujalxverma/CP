#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector<int> fact, invfact;
int mod_pow(int n, int exp) {
    int res = 1 % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res % mod * n % mod) % mod;
        n = (n % mod * n % mod) % mod;
        exp >>= 1;
    }
    return res % mod;
}
std::vector<long long> compute_factorials(int n) {
    std::vector<long long> factorials(n + 1);
    factorials[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorials[i] = (factorials[i - 1] * i) % mod;
    }
    return factorials;
}

// Computes inverse factorials up to n using precomputed factorials
std::vector<long long> compute_inv_factorials(int n, const std::vector<long long> &fact) {
    std::vector<long long> inv_fact(n + 1);
    inv_fact[n] = mod_pow(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    return inv_fact;
}

// computes inverse from 1 to N.
std::vector<int> compute_inverses(int n) {
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (int)((1LL * (mod / i) * inv[mod % i]) % mod);
    }
    return inv;
}

long long nCr(int n, int r,
              const vector<long long> &fact,
              const vector<long long> &inv_fact) {
    if (r < 0 || r > n)
        return 0;

    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        (a[i] == -1 ? cnt++ : cnt);
    }
    if (cnt == n) {
        // then only even len subseq allowed.
        cout << mod_pow(2, n - 1) % mod << "\n";
        return;
    }
    if (cnt == 0) {
        // then only even equal pair subseq allowed.
        }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    fact = compute_factorials(2e5 + 10);
    invfact = compute_inverses(2e5 + 10);
    while (t--) {
        solve();
    }

    return 0;
}