#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<vector<int>> dp;
int n, m;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (a[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] != 0) {
            int j = a[i];
            dp[i][j] = ((j - 1 >= 1 ? dp[i - 1][j - 1] : 0) % mod + dp[i - 1][j] % mod + (j + 1 <= m ? dp[i - 1][j + 1] : 0) % mod) % mod;
            continue;
        }
        for (int j = 1; j <= m; j++) {

            dp[i][j] = ((j - 1 >= 1 ? dp[i - 1][j - 1] : 0) % mod + dp[i - 1][j] % mod + (j + 1 <= m ? dp[i - 1][j + 1] : 0) % mod) % mod;
        }
    }
    if (a[n] != 0) {
        cout << dp[n][a[n]] % mod << "\n";
    } else {
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            sum = (sum % mod + dp[n][i] % mod) % mod;
        }
        cout << sum << "\n";
    }

    return 0;
}