#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, g;
    cin >> r >> g;
    int total = (r + g);

    int h = 0;
    int sum = 0;
    while (sum <= total) {
        if ((h + 1) * (h + 2) / 2 <= total) {
            sum = (h + 1) * (h + 2) / 2;
            h++;
        } else {
            break;
        }
    }
    int ans = 0;
    /*
    vector<vector<int>> dp(h + 1, vector<int>(sum + 1, 0));
    // dp[i][j] -> number of ways to make level i, using j numbers of red blocks.
    dp[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= sum; j++) {

            // use green
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

            // use red
            if (j >= i)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
        }
    }


    for (int j = 0; j <= sum; j++) {
        if (j <= r && sum - j <= g) {
            ans += dp[h][j];
        }
    }
        */

    vector<int> dp(sum + 1, 0);
    vector<int> dpx(sum + 1, 0);
    dp[0] = 1;
    dpx[0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = sum; j >= i; j--) {
            if (j >= i) {
                dp[j] = (dpx[j] + dpx[j - i]) % mod;
            }
        }
        dpx = dp;
    }

    for (int j = 0; j <= sum; j++) {
        if (j <= r && sum - j <= g) {
            ans = (ans + dp[j]) % mod;
        }
    }
    cout << ans << "\n";

    return 0;
}