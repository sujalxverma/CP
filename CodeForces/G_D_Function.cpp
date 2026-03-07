#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
const ll mod = 1e9 + 7;

// Modular Exponention
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll sumOfDigits(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n = n / 10;
    }
    return sum;
}

/*
        ll l, r, k;
        cin >> l >> r >> k;
        if (k == 1) {
            cout << (mod_pow(10, r, mod) - mod_pow(10, l, mod) + mod) % mod << "\n";
            continue;
        }
        if (l == 0) {
            cout << mod_pow(2, r + 1, mod) - 1 << "\n";
            continue;
        }
        ll end = mod_pow(2, r + 1, mod) - 1;
        ll start = mod_pow(2, l, mod) - 1;

        cout << abs(end - start) << "\n";
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        if (k == 1) {
            cout << (mod_pow(10, r, mod) - mod_pow(10, l, mod) + mod) % mod << "\n";
            continue;
        }

        ll start = min(mod_pow(10, l, mod), mod_pow(10, r, mod));
        ll end = max(mod_pow(10, l, mod), mod_pow(10, r, mod));
        ll ans = 0;
        for (ll i = start; i < end; i++) {
            if (sumOfDigits((k % mod * i % mod) % mod) == k * sumOfDigits(i)) {
                cout << i << "\n";
                ans++;
            }
        }

        // ll l, r, k;
        // cin >> l >> r >> k;
        // if (k == 1) {
        //     cout << (mod_pow(10, r, mod) - mod_pow(10, l, mod) + mod) % mod << "\n";
        //     continue;
        // }
        // if (l == 0) {
        //     cout << mod_pow(2, r + 1, mod) - 1 << "\n";
        //     continue;
        // }
        // ll end = mod_pow(2, r, mod) - 1;
        // ll start = mod_pow(2, l, mod) - 1;

        // cout << abs(end - start) << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}