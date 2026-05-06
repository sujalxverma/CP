#include "bits/stdc++.h"
using namespace std;
long long n, W;
vector<long long> w, v;
vector<vector<long long>> dp;

/*
long long f(long long idx, long long target) {

    if (idx == 0) {
        if (w[0] <= target) {
            return v[0];
        }
        return 0;
    }

    if (dp[idx][target] != -1) {
        return dp[idx][target];
    }

    long long nottake = f(idx - 1, target);
    long long take = (w[idx] <= target ? (v[idx] + f(idx - 1, target - w[idx])) : 0);

    return dp[idx][target] = max(take, nottake);
}
*/

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> W;
    v.resize(n);
    w.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    /*
    dp.resize(n, vector<long long>(W + 1, 0));
    for (int i = 0; i <= W; i++) {
        if (w[0] > i)
            continue;
        dp[0][i] = v[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (w[i] <= j) {
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }
    }
    cout << dp[n - 1][W] << "\n";
    */
    vector<long long> dp(W + 1, 0);
    for (long long i = 1; i <= W; i++) {
        if (w[0] <= i) {
            dp[i] = v[0];
        }
    }

    for (long long i = 1; i < n; i++) {
        for (long long j = W; j >= 0; j--) {
            if (w[i] <= j) {
                dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
            }
        }
    }
    cout << dp[W] << "\n";

    return 0;
}