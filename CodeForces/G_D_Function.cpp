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

long long F(long long x, int k) {
    if (x <= 0)
        return 0;

    string s = to_string(x);
    int n = s.size();

    long long powb[20];
    powb[0] = 1;

    for (int i = 1; i < 20; i++)
        powb[i] = powb[i - 1] * (k + 1);

    long long ans = 0;

    // shorter lengths
    for (int len = 1; len < n; len++)
        ans += k * powb[len - 1];

    // same length
    for (int i = 0; i < n; i++) {

        int d = s[i] - '0';
        int start = (i == 0 ? 1 : 0);

        for (int dig = start; dig < d && dig <= k; dig++)
            ans += powb[n - i - 1];

        if (d > k) {
            ans += powb[n - i];
            return ans;
        }
    }

    return ans + 1;
}
long long countRange(long long s, long long e, int k) {
    return F(e - 1, k) - F(s - 1, k);
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

/*
If k is some power of 10, then answer is 0.
One more Observation.
If k%10 == 0, then also answer is 0.
Actually, one more.
If k>=10 , then answer is 0.
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
        cout << ((mod_pow(9 / k + 1, r, mod)) % mod - (mod_pow(9 / k + 1, l, mod)) % mod + mod) % mod << "\n";
        // ll l, r, k;
        // cin >> l >> r >> k;
        // if (k >= 10) {
        //     cout << "0\n";
        //     continue;
        // }
        // if (k == 1) {
        //     cout << abs(mod_pow(10, r, mod) - mod_pow(10, l, mod)) << "\n";
        //     continue;
        // }
        // if (k >= 5) {
        //     ll start = mod_pow(2, l, mod) - 1;
        //     ll end = mod_pow(2, r, mod) - 1;

        //     ll ans = abs(end - start);

        //     cout << ans << "\n";
        //     continue;
        // }

        // // ll start = mod_pow(2, l, mod) - 1;
        // // ll end = mod_pow(2, r, mod) - 1;

        // // ll ans = abs(end - start);

        // // cout << ans << "\n";

        // ll s = mod_pow(10, l, mod);
        // ll e = mod_pow(10, r, mod);
        // if (k == 2) {

        //     cout << countRange(min(s, e), max(s, e), 4) << "\n";
        // }
        // if (k == 3) {
        //     cout << countRange(min(s, e), max(s, e), 3) << "\n";
        // }
        // if (k == 4) {
        //     cout << countRange(min(s, e), max(s, e), 2) << "\n";
        // }
        // continue;
        // cout << s << " " << e << "\n";
        // continue;
        // int xt = 0;
        // for (ll i = min(s, e); i < max(s, e); i++) {

        //     if (sumOfDigits(i) * k == sumOfDigits((i % mod * k % mod) % mod)) {
        //         cout << i << "\n";
        //         xt++;
        //     }
        // }
        // cout << xt;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}
