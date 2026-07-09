#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            // a[j][i] = a[i][j];
            g[i].push_back(j);
        }
    }

    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        if (a[0][i] == 1) {
            // means man 0 is compatible with woman i
            dp[(1 << i)][0] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        // means i man paired.
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask == (1 << n) - 1) {
                // all asiigned.
                continue;
            }

            if (__builtin_popcount(mask) != i) {
                // measn say when i = 4, means : 0,1,2,3 : paired.
                // but mask says only 3 and 5 paired. means only 2 woman paired. not possible.
                continue;
            }

            for (int j : g[i]) {
                if (a[i][j] == 1 && !(mask & (1 << j))) {
                    dp[(1 << j) | mask][i] = (dp[(1 << j) | mask][i] % mod + dp[mask][i - 1] % mod) % mod;
                }
            }
        }
    }
    // for (int i = 0; i < (1 << n); i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[(1 << n) - 1][n - 1] << "\n";

    return 0;
}