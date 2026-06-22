#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 5, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v = a[i];
        // backward
        if (i - v - 1 >= 0 && dp[i - v - 1] == 1) {
            dp[i] = 1;
        }
        // forward
        if (i + v <= n && dp[i - 1] == 1) {
            dp[i + v] = 1;
        }
    }
    cout << (dp[n] == 1 ? "YES\n" : "NO\n");
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