#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, inf));
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= (n - len + 1); i++) {
            int j = i + len - 1;
            for (int k = i + 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + (p[k - 1] - p[i - 1]) + (p[j] - p[k - 1]) + dp[k][j]);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}