#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int main() {
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
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= sum / 2; j++) {
            dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - v[i]] % mod) % mod;
        }
    }

    cout << dp[n][sum / 2 + 1] % mod << "\n";

    return 0;
}