#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 998244353;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 2, 0);
    dp[0] = 1;
    while (n--) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] = (dp[i] % mod + dp[i - x] % mod) % mod;
            }

        } else {
            for (int i = x; i <= k; i++) {
                dp[i] = (dp[i] % mod - dp[i - x] % mod + mod) % mod;
            }
        }
        cout << dp[k] % mod << "\n";
    }
    return 0;
}