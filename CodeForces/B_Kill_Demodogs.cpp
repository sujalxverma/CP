#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

// Function to compute modular inverse using Fermat's Little Theorem
ll modinv(ll a, ll m = MOD) {
    ll res = 1, b = m-2;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

/*
    Approach:
    ----------
    - Computes sum_{k=1}^{n} k^2 using the formula n(n+1)(2n+1)/6 (modular division!).
    - Computes sum_{i=1}^{n-1} i*(i+1) efficiently using formula: sum_{i=1}^{n-1} (i^2 + i)
    - Multiplies final result by 2022 and outputs it modulo MOD.
    - Uses modular inverse for division in modular arithmetic.
*/

void solve() {
    ll n;
    cin >> n;
    ll squaredSum = n % MOD * ((n + 1) % MOD) % MOD * ((2 * n + 1) % MOD) % MOD;
    squaredSum = squaredSum * modinv(6) % MOD; // Proper modular division by 6

    // sum_{i=1}^{n-1} i^2 = (n-1)n(2n-1)/6
    ll sum_i2 = ((n-1) % MOD * (n % MOD) % MOD * ((2*n-1) % MOD)) % MOD;
    sum_i2 = sum_i2 * modinv(6) % MOD;

    // sum_{i=1}^{n-1} i = (n-1)n/2
    ll sum_i = ((n-1) % MOD * (n % MOD)) % MOD;
    sum_i = sum_i * modinv(2) % MOD;

    ll consecutiveSum = (sum_i2 + sum_i) % MOD;

    ll ans = (2022 * ((squaredSum + consecutiveSum) % MOD )) % MOD;
    cout << ans << "\n";
}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}