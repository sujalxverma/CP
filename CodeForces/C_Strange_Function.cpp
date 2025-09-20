#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const long long MOD = 1000000007LL;

static inline long long safe_gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Returns pair {exceeds, value}. If lcm(x,y) > limit, returns {true, 0} without overflowing.
static inline pair<bool, long long> lcm_upto(long long x, long long y, long long limit) {
    long long d = safe_gcd(x, y);
    long long t = x / d;
    // Check t * y > limit without overflow
    if (t > limit / y) return {true, 0};
    return {false, t * y};
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return;
    while (T--) {
        long long n;
        cin >> n;

        long long G = 1;
        long long ans = 0;

        for (long long i = 1; G <= n; ++i) {
            auto [exceeds, val] = lcm_upto(G, i, n);
            if (exceeds) break;
            G = val;
            if (G > n) break;
            ans += (n / G);
            if (ans >= (LLONG_MAX / 2)) ans %= MOD; // keep ans bounded
        }

        cout << ( (ans % MOD + n % MOD) % MOD ) << '\n';
    }
}

int main() {
    solve();
    return 0;
}
