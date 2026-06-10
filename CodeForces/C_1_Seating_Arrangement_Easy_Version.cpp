#include "bits/stdc++.h"
using namespace std;
const int inf = -1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x, s;
        cin >> x >> s;
        string k;
        cin >> k;

        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -inf));
        // dp[i][j] =>max amount of people seated after processing
        // the first i people and having j tables.
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = 0; j <= x; j++) {
                if (k[i - 1] == 'I') {
                    // introvert.
                    if (dp[i - 1][j] != inf && j < x) {
                        dp[i][j + 1] = max(dp[i - 1][j] + 1, dp[i - 1][j + 1]);
                    }
                }
                if (k[i - 1] == 'E') {
                    if (dp[i - 1][j] < j * s && j > 0) {
                        dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j]);
                    }
                }
                if (k[i - 1] == 'A') {
                    if (dp[i - 1][j] != inf && j < x) {
                        dp[i][j + 1] = max(dp[i - 1][j] + 1, dp[i - 1][j + 1]);
                    }
                    if (dp[i - 1][j] < j * s && j > 0) {
                        dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j]);
                    }
                }
            }
        }
        cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
    }

    return 0;
}