#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        ll g1 = gcd(a, b);
        ll g2 = gcd(c, d);
        ll g = gcd(g1, g2);

        __int128 lcm = (__int128)g1 / g * g2;   // SAFE

        __int128 ans128 = 2 * ((__int128)k / lcm) + 1;

        ll ans = (ll)ans128;   // guaranteed safe by problem
        cout << ans << "\n";
    }
}
