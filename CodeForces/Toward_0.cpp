#include "bits/stdc++.h"
using namespace std;
using ll = long long;

unordered_map<ll, double> dp;

double helper(ll n, ll a, ll x, double y) {
    if (n == 0) {
        return 0;
    }
    if (dp.count(n)) {
        return dp[n];
    }
    double res = 1e18;
    res = x + helper(n / a, a, x, y);
    res = min(res, 1.2 * y + 0.2 * (helper(n / 2, a, x, y) + helper(n / 3, a, x, y) + helper(n / 4, a, x, y) + helper(n / 5, a, x, y) + helper(n / 6, a, x, y)));
    return dp[n] = res;
}

void solve() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;
    cout << helper(n, a, x, y);
}

int main() {
    solve();
};