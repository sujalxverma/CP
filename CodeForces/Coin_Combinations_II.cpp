#include "bits/stdc++.h"
using namespace std;
int n, c;
const int mod = 1e9 + 7;
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(c + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            if (a[i] <= j) {
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            }
        }
    }

    cout << dp[c] << "\n";

    return 0;
}