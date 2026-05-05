#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }
    /*
    vector<vector<int>> dp(h, vector<int>(w, 0));
    if (g[0][0] == '#') {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (g[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }

            if (i - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            if (j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[h - 1][w - 1] << "\n";
    */

    vector<int> dp(w, 0);
    if (g[0][0] == '#') {
        dp[0] = 0;
    } else {
        dp[0] = 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 && j == 0)
                continue;
            if (g[i][j] == '#') {
                dp[j] = 0;
                continue;
            }
            if (j - 1 >= 0) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
    }

    cout << dp[w - 1] << "\n";
    return 0;
}