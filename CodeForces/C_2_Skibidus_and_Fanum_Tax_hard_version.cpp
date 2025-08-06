#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const ll LINF = 1e18 + 16;

void solve() {
    int n, m;
    cin >> n >> m;
    vl a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(b.begin(), b.end());
    a.insert(a.begin(), -LINF); // Add dummy at front for i-1 safety
    n++;
    rep(i, 1, n) {
        // Find b[j] such that b[j] - a[i] >= a[i-1]
        auto it = lower_bound(b.begin(), b.end(), -15, [&](ll val, ll unused) {
            assert(unused == -15);
            return val - a[i] < a[i-1];
        });
        if (it == b.end()) continue;
        ll j = *it;
        if (a[i] < a[i-1] && j - a[i] < a[i-1]) continue;
        a[i] = min((a[i] < a[i-1] ? LINF : a[i]), (j - a[i] < a[i-1] ? LINF : j - a[i]));
    }
    if (is_sorted(a.begin(), a.end())) yes; else no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
