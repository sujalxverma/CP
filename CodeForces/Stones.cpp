#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K;
    cin >> n >> K;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, 0)));
    dp[0][0][0] = 1; // 1 means loss.
    dp[0][0][1] = 1; // 1 means loss.

    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= K; j++) {
            for (int k = 0; k <= 1; k++) {
                dp[i][j][k] |= dp[i - 1][j - a[i]][k];
            }
        }
    }
    return 0;
}