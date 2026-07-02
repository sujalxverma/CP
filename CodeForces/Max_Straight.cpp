#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (dp.count(a[i] - 1)) {
            dp[a[i]] = max(dp[a[i]], 1 + dp[a[i] - 1]);
        } else {
            dp[a[i]] = 1;
        }
    }

    int ans = 0;
    for (auto &[x, y] : dp) {
        ans = max(ans, y);
    }
    cout << ans << "\n";

    return 0;
}