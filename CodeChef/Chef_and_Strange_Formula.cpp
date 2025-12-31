#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> f(m);
    f[0] = 1;
    for (ll i = 1; i < m; i++) {
        f[i] = (f[i-1] * i) % m;
        if (f[i] == 0) break;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for (ll x : a) {
        __int128 t = (__int128)x * x * (x + 1) / 2;
        ll value = (ll)(t % m);

        if (x + 1 < m) {
            value = (value + f[x+1] - 1) % m;
        } else {
            value = (value - 1) % m;
        }

        if (value < 0) value += m;
        ans = (ans + value) % m;
    }

    cout << ans << "\n";
    return 0;
}
