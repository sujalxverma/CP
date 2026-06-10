#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto &x : a) {
        cin >> x;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}