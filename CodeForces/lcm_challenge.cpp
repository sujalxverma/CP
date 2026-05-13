#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using i128 = __int128_t;
bool f(vector<ll> &a, ll m, ll k) {
    ll n = a.size();

    for (ll i = 0; i < n; i++) {
        if (a[i] >= m)
            continue;

        ll need = m - a[i];

        ll ops = (need + i) / (i + 1);

        if (ops > k)
            return false;

        k -= ops;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);

    for (ll &x : a)
        cin >> x;

    ll s = *min_element(a.begin(), a.end());
    ll e = (ll)4e18; // effectively INF for this problem

    while (s < e) {
        ll m = s + (e - s + 1) / 2;

        if (f(a, m, k)) {
            s = m;
        } else {
            e = m - 1;
        }
    }

    cout << s << '\n';
}