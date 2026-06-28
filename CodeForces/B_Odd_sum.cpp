#include "bits/stdc++.h"
using namespace std;
#define int long long
const int NEG = -1e9;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 0->even , 1->odd
    vector<vector<int>> dp(n + 1, vector<int>(2, NEG));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        if (a[i] % 2 == 0) {
            dp[i][0] = max(dp[i - 1][0], a[i]);
        } else {
            dp[i][1] = max(dp[i - 1][1], a[i]);
        }

        if (a[i] % 2 == 0) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i]);
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i]);
        } else {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i]);
        }
    }

    cout << dp[n][1] << "\n";

    return 0;
}