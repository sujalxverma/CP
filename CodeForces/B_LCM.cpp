#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast multiplication mod m (avoid overflow)
ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

// Fast exponentiation mod m
ll modpow(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin primality test (deterministic for 64-bit)
bool miller_rabin(ll n) {
    if (n < 2) return false;
    ll r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    // Test bases for 64-bit integers (deterministic set)
    vector<ll> testBases = {2,3,5,7,11,13,17,19,23};
    for (ll a : testBases) {
        if (a >= n) break;
        ll x = modpow(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool composite = true;
        for (ll i = 0; i < r-1; i++) {
            x = mulmod(x, x, n);
            if (x == n-1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    ll x = rand() % (n-2) + 2;
    ll y = x;
    ll c = rand() % (n-1) + 1;
    ll d = 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = __gcd(abs(x - y), n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}

void factor(ll n, vector<ll> &factors) {
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors.push_back(n);
        return;
    }
    ll divisor = pollard_rho(n);
    factor(divisor, factors);
    factor(n / divisor, factors);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;

    vector<ll> f;
    factor(n, f);
    sort(f.begin(), f.end());

    // Count number of divisors:
    // Exponents of prime factors:
    ll ans = 1;
    for (size_t i = 0; i < f.size();) {
        ll count = 1;
        size_t j = i + 1;
        while (j < f.size() && f[j] == f[i]) {
            j++;
            count++;
        }
        ans *= (count + 1);
        i = j;
    }
    cout << ans << "\n";

    return 0;
}
