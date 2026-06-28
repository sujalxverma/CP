#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = -1e18;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n);
    vector<int> y(n - 1);
    for (auto &a : x) {
        cin >> a;
    }
    for (auto &a : y) {
        cin >> a;
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, inf));
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int l = 0; l < 2; l++) {
            for (int c = 0; c < 2; c++) {
                if (dp[i - 1][l] == inf) {
                    continue;
                }
                int val = dp[i - 1][l];

                if (c == 0) {
                    if (s[i - 1] == 'S') {
                        val -= x[i - 1];
                    }
                } else {
                    if (s[i - 1] == 'R') {
                        val -= x[i - 1];
                    }
                }

                if (i - 1 > 0 && l == 0 && c == 1) {
                    val += y[i - 2];
                }

                dp[i][c] = max(dp[i][c], val);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
