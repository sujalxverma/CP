#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

unordered_map<ll, ll> dp;

ll maxDollars(ll n) {
    // Memoisation
    // if (n == 0 || n == 1) return n;  // Base cases

    // if (dp.count(n)) return dp[n];

    // ll exchangeValue = maxDollars(n / 2) + maxDollars(n / 3) + maxDollars(n / 4);
    // return dp[n] = max(n, exchangeValue);

    // // Tabulation
    // Base case for small values
    if (n < 5) return n;

    vector<ll> DP(n + 1);
    for (int i = 0; i <= 4; i++) {
        DP[i] = i;
    }

    for (ll i = 5; i <= n; i++) {
        DP[i] = max(i, DP[i / 2] + DP[i / 3] + DP[i / 4]);
    }

    return DP[n];


}


void solve() {
    ll n;
    while (cin >> n) {  // Read all test cases until EOF
        cout << maxDollars(n) << "\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
