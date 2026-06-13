#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> gr(n + 1);
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            // g[j][i] = g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) {
                gr[i].push_back(j);
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>((1 << n), 0));
    // dp[i][mask] -> Number of ways to match first i men with the set of women indicated by the mask
    for (int i = 0; i < n; i++) {
        if (g[0][i] == 1) {
            dp[0][1 << i] = 1;
        }
    }

    for (int i = 1; i < n; i++) { // men 0 already processed.
        for (int j = 0; j < (1 << n); j++) {
            if (__builtin_popcount(j) != i)
                continue;
            // for (int k = 0; k < n; k++) {
            //     if (g[i][k] == 1 && !(j & (1 << k))) {
            //         // means j knows k, and k was not attached to anyone earlier.
            //         dp[i][j | (1 << k)] = (dp[i][j | (1 << k)] % mod + dp[i - 1][j] % mod) % mod;
            //     }
            // }
            for (auto &k : gr[i]) {
                if (g[i][k] == 1 && !(j & (1 << k))) {
                    // means j knows k, and k was not attached to anyone earlier.
                    dp[i][j | (1 << k)] = (dp[i][j | (1 << k)] % mod + dp[i - 1][j] % mod) % mod;
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] % mod << "\n";

    return 0;
}