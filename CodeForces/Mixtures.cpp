#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = (LLONG_MAX) / 4;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (true) {
        if (!(cin >> n))
            return 0;

        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> p(n + 1, 0); // prefix sum
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i];
        }

        vector<vector<int>> dp(n + 5, vector<int>(n + 5, inf));
        for (int i = 0; i <= n; i++) {
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= (n - len + 1); i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    int v1 = dp[i][k] + dp[k + 1][j] + (((p[k] - p[i - 1]) % 100) * ((p[j] - p[k]) % 100));
                    int v2 = dp[i][k - 1] + dp[k][j] + (((p[k - 1] - p[i - 1]) % 100) * ((p[j] - p[k - 1]) % 100));
                    dp[i][j] = min({dp[i][j], v1, v2});
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        std::cout << dp[1][n] << "\n";
    }

    return 0;
}
