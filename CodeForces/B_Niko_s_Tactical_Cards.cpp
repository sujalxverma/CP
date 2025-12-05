#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll f(vector<ll>& a, vector<ll>& b, ll k, ll index) {
    if (index >= a.size()) return k; // return current score at end

    // Option 1: choose red card
    ll first = f(a, b, k - a[index], index + 1);

    // Option 2: choose blue card
    ll second = f(a, b, b[index] - k, index + 1);

    return max(first, second);
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    ll s = f(a, b, 0, 0); // start with k = 0
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
