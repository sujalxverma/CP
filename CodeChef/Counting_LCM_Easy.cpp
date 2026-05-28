#include "bits/stdc++.h"
using namespace std;
using ll = long long;
/*
 * N -> p1(a1) * p2(a2) * p3(a3)
 * Then LCM(x,y) == N:
 *      x -> p1(b1)*p2(b2)*p3(b3);
 *      y -> p1(c1)*p2(c2)*p3(c3);
 *      primes should be same,no other prime number should be present.
 *      for 1<=i<=3 , max(bi,ci) == ai
 *      then only LCM(x,y) == N
 * Now, since 0 <= bi,ci <= ai, and max(bi,ci) == ai
 * Thus we have 2(ai)+1 choices.
 * Thus multiply (2ai + 1) for all 1<=i<=k,
 */
vector<ll> smallestPrimeFactor(ll n) {
    vector<ll> spf(n + 1);
    // initially assume every number
    // is its own smallest prime factor
    for (ll i = 0; i <= n; i++) {
        spf[i] = i;
    }
    spf[0] = 0;
    spf[1] = 1;
    for (ll i = 2; i * i <= n; i++) {
        // if spf[i] == i,
        // then i is prime
        if (spf[i] == i) {
            for (ll j = i * i; j <= n; j += i) {
                // first prime reaching j
                // is its smallest prime factor
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}
/*
Prime Factorization using SPF
------------------------------
Time Complexity : O(log n) : each division reduces n by at least a factor of 2.
*/
unordered_map<ll, ll> primeFactors(ll n, vector<ll> &spf) {
    unordered_map<ll, ll> factors;
    while (n > 1) {
        ll p = spf[n];
        factors[p]++;
        n /= p;
    }
    return factors;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    vector<ll> spf = smallestPrimeFactor(1e6 + 10);
    while (t--) {
        ll n;
        cin >> n;
        ll total = n * n;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            unordered_map<ll, ll> f = primeFactors(i, spf);
            ll cal = 1;
            for (auto &[x, y] : f) {
                // cout << y << "\n";
                cal *= 2 * y + 1;
            }
            cnt += cal;
        }
        cout << total - cnt << "\n";
    }
    return 0;
}