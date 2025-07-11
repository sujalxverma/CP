#include "bits/stdc++.h"
using namespace std;

using ll = long long;

// Return all divisors of x in O(sqrt(x))
vector<ll> get_divisors(ll x) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) divisors.push_back(x / i);
        }
    }
    return divisors;
}

/*
    Let the difficulties of the n sub-problems be: a1, a2, ..., an.
    Their GCD must be a divisor of x (since a1 + a2 + ... + an = x).

    For a divisor d of x, we can choose the difficulties:
        d, d, ..., x - (n-1)*d

    This is valid only if: n * d <= x

    Goal: Find the maximum such valid d (divisor of x)
*/
void solve() {
    ll x, n;
    cin >> x >> n;

    vector<ll> divisors = get_divisors(x);
    ll max_balance = 1;

    for (ll d : divisors) {
        if (n * d <= x) {
            max_balance = max(max_balance, d);
        }
    }

    cout << max_balance << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
