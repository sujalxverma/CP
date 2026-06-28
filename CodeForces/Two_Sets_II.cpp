#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        v[i] = i;
        sum += v[i];
    }
    if (sum % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    int inv2 = 500000004;
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j < v[i])
                continue;
            dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - v[i]] % mod) % mod;
        }
    }

    cout << dp[n][sum / 2] * inv2 % mod << "\n";

    return 0;
}